#include "mycamera.h"
#include "jpeglib.h"  //jpeg库的头文件

mycamera* mycamera::m_instance = nullptr;
//封装函数把YUV转成RGB
int yuvtorgb(int y,int u,int v)
{
    int r,g,b;
    int pix;
    r=y+1.4075*(v-128);
    g=y-0.3455*(u-128)-0.7169*(v-128);
    b=y+1.779*(u-128);
    //修正计算结果
    if(r>255)
        r=255;
    if(g>255)
        g=255;
    if(b>255)
        b=255;
    if(r<0)
        r=0;
    if(g<0)
        g=0;
    if(b<0)
        b=0;
    //因为lcd要求是ARGB，所以我们顺便在这里把RGB转成ARGB，方便后续使用
    pix=0x00<<24|r<<16|g<<8|b;
    return pix;
}

int allyuyvtoargb(char *yuyvdata,int *argbdata)
{
    int i,j;
    for(i=0,j=0; i<(W*H); i+=2,j+=4)
    {
        argbdata[i]=yuvtorgb(yuyvdata[j],yuyvdata[j+1],yuyvdata[j+3]);
        argbdata[i+1]=yuvtorgb(yuyvdata[j+2],yuyvdata[j+1],yuyvdata[j+3]);
    }
    return 0;
}

//封装函数把一张完整画面的YUYV数据全部转换成RGB数据
int allyuvtorgb(char *yuvdata,char *rgb)
{

    int i,j;
    int pix;
    char *p;
    //有W*H个像素点
    for(i=0,j=0; i<W*H*3; i+=6,j+=4) // W*H*3/6  次数
    {
        pix=yuvtorgb(yuvdata[j],yuvdata[j+1],yuvdata[j+3]);
        p=(char *)&pix;
        //根据学习的C语言指针运算规则
        //p+0-->B p+1-->G  p+2-->R  p+3 -->A
        rgb[i]=*(p+2);
        rgb[i+1]=*(p+1);
        rgb[i+2]=*(p+0);

        pix=yuvtorgb(yuvdata[j+2],yuvdata[j+1],yuvdata[j+3]);
        p=(char *)&pix;
        rgb[i+3]=*(p+2);
        rgb[i+4]=*(p+1);
        rgb[i+5]=*(p+0);
    }
    return 0;
}

//把RGB压缩成jpeg图片
int rgbtojpg(char *rgbdata,char *jpgfile)
{
    int i;
    //定义压缩结构体和处理错误的结构体并初始化
    struct jpeg_compress_struct mycom;
    jpeg_create_compress(&mycom);
    struct jpeg_error_mgr myerr;
    mycom.err=jpeg_std_error(&myerr);

    //设置压缩参数(宽，高)
    mycom.image_width=W;
    mycom.image_height=H;
    mycom.in_color_space=JCS_RGB;
    mycom.input_components=3;
    jpeg_set_defaults(&mycom);

    //设置压缩比例(压缩质量)
    jpeg_set_quality(&mycom,90,(boolean)true);

    //绑定输出
    FILE *myfile=fopen(jpgfile,"w+");
    if(myfile==NULL)
    {
        perror("新建jpg图片失败了!\n");
        return -1;
    }
    jpeg_stdio_dest(&mycom,myfile);

    //开始压缩
    jpeg_start_compress(&mycom,(boolean)true);

    JSAMPROW row_pointer[1];
    //把压缩后的数据写入到空白的jpeg文件
    for(i=0; i<H; i++)
    {
        //把每一行的RGB数据保存到数组中
        row_pointer[0]=(JSAMPROW)(rgbdata+i*W*3);
        //一次写入一行数据
        jpeg_write_scanlines(&mycom,row_pointer,1);
    }

    //收尾
    jpeg_finish_compress(&mycom);
    jpeg_destroy_compress(&mycom);
    fclose(myfile);
    return 0;
}
mycamera::mycamera()
{
    //线程运行标志位
    this->cameraflag=1;

}
//初始化摄像头
int mycamera::camera_init()
{
    int ret;
    int i;
    //创建rfid实例
    myrfid=new rfid();
    //开启实例
    myrfid->start();

    //打开摄像头的驱动
    camerafd=open("/dev/video7",O_RDWR);
    if(camerafd==-1)
    {
        perror("打开摄像头的驱动失败了!\n");
        return -1;
    }

    //打开液晶屏的驱动
    lcdfd=open("/dev/fb0",O_RDWR);
    if(lcdfd==-1)
    {
        perror("打开液晶屏的驱动失败了!\n");
        return -1;
    }

    //映射得到液晶屏的首地址
    lcdmem=(int *)mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,lcdfd,0);
    if(lcdmem==NULL)
    {
        perror("映射液晶屏首地址失败了!\n");
        return -1;
    }

    //设置摄像头的采集格式(画面的宽，高，像素点的格式)
    struct v4l2_format myfmt;
    bzero(&myfmt,sizeof(myfmt));
    myfmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    myfmt.fmt.pix.width=W;
    myfmt.fmt.pix.height=H;
    myfmt.fmt.pix.pixelformat=V4L2_PIX_FMT_YUYV; //粤嵌发的摄像头是YUV格式的

    ret=ioctl(camerafd,VIDIOC_S_FMT,&myfmt);
    if(ret==-1)
    {
        perror("设置摄像头的采集格式失败了!\n");
        return -1;
    }

    //申请缓冲区--》存放画面的
    struct v4l2_requestbuffers reqbuf;
    bzero(&reqbuf,sizeof(reqbuf));
    reqbuf.count=4; //申请4个缓冲区
    reqbuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    reqbuf.memory=V4L2_MEMORY_MMAP;
    ret=ioctl(camerafd,VIDIOC_REQBUFS,&reqbuf);
    if(ret==-1)
    {
        perror("申请缓冲区失败了!\n");
        return -1;
    }

    //分配缓冲区--》把你刚才申请的缓冲区分配给你，顺便映射得到每个缓冲区的首地址
    for(i=0; i<4; i++)
    {
        bzero(&v4l2buf,sizeof(v4l2buf));
        v4l2buf.index=i; //缓冲区的索引号
        v4l2buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        v4l2buf.memory=V4L2_MEMORY_MMAP;
        ret=ioctl(camerafd,VIDIOC_QUERYBUF,&v4l2buf);
        if(ret==-1)
        {
            perror("分配缓冲区失败了!\n");
            return -1;
        }

        //映射得到每个缓冲区的首地址
        array[i].len=v4l2buf.length;  //存放缓冲区大小
        array[i].start=mmap(NULL,v4l2buf.length,PROT_READ|PROT_WRITE,MAP_SHARED,camerafd,v4l2buf.m.offset);
        if(array[i].start==NULL)
        {
            perror("映射首地址失败了!\n");
            return -1;
        }
        //申请画面数据入队--》下一步摄像头就要启动了，提前做好准备
        //入队：申请把画面数据存放到缓冲区
        ret=ioctl(camerafd,VIDIOC_QBUF,&v4l2buf);
        if(ret==-1)
        {
            perror("申请入队失败了!\n");
            return -1;
        }
    }
    //启动摄像头采集
    type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret=ioctl(camerafd,VIDIOC_STREAMON,&type);
    if(ret==-1)
    {
        perror("启动摄像头采集失败了!\n");
        return -1;
    }
    return 0;
}
//捕捉画面显示
int mycamera::camera_capture()
{
    int i,j;
    int ret;
    char jpgname[10];
    //循环出队，入队，显示视频流(关键步骤)
    char rgbbuf[3*W*H]; //存放转换得到的一帧画面的RGB数据
    int argbbuf[W*H]; //存放转换得到的一帧画面的ARGB数据
    //定义文件描述符集合
    fd_set myset;
    FD_ZERO(&myset);
    //添加你要监测的文件描述符
    FD_SET(camerafd,&myset);
    for(i=0; i<4; i++)
    {
        //监测摄像头是否有数据可读
        ret=select(camerafd+1,&myset,NULL,NULL,NULL);
        if(ret>0)
        {
            //有数据可读才出队
            bzero(&v4l2buf,sizeof(v4l2buf));
            v4l2buf.index=i; //缓冲区的索引号
            v4l2buf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
            v4l2buf.memory=V4L2_MEMORY_MMAP;
            //出队--》把画面从缓冲区里面取出来
            ret=ioctl(camerafd,VIDIOC_DQBUF,&v4l2buf);
            if(ret==-1)
            {
                perror("申请出队失败了!\n");
                return -1;
            }
            allyuvtorgb((char *)(array[i].start),rgbbuf);

            allyuyvtoargb((char *)(array[i].start),argbbuf);
            for(j=0; j<H; j++) //一行行拷贝数据
                memcpy(lcdmem+j*800+640,&argbbuf[j*W],W*4);

            //            sleep(1);
            //入队
            ret=ioctl(camerafd,VIDIOC_QBUF,&v4l2buf);
            if(ret==-1)
            {
                perror("申请入队失败了!\n");
                return -1;
            }
        }
    }
    if(myrfid->getrfidflag()==1)
    {
        //把刚才转换得到的RGB数据压缩成jpeg图片
        strcpy(jpgname,"pic.jpg");
        rgbtojpg(rgbbuf,jpgname);
        //抓拍标志
        snapshotflag=1;

        QThread::sleep(1);
        snapshotflag=0;
    }
    return 0;
}
//关闭摄像头
int mycamera::camera_uninit()
{
    int i;
    int ret;
    //收尾
    ret=ioctl(camerafd,VIDIOC_STREAMOFF,&type);
    if(ret==-1)
    {
        perror("关闭摄像头采集失败了!\n");
        return -1;
    }
    close(lcdfd);
    close(camerafd);
    munmap(lcdmem,800*480*4);
    for(i=0; i<4; i++)
        munmap(array[i].start,array[i].len);
    return 0;
}

//线程的任务函数
void mycamera::run()
{
    while(1)
    {
        while(cameraflag)
        {
            camera_capture();
        }
    }

}
