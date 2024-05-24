#ifndef MYCAMERA_H
#define MYCAMERA_H

#include "myhead.h"
#include "rfid.h"
#include "tcpclient.h"
#include <QThread>

#define W 160
#define H 120

//自定义结构体保存每个缓冲区的首地址和大小
struct camerabuf
{
    void *start; //缓冲区的首地址
    int len; //缓冲区的大小
};

class mycamera:public QThread
{
public:
    static mycamera* getInstance()
    {
        if (!m_instance)
        {
            m_instance = new mycamera;
        }
        return m_instance;
    }
    int cameraflag;
    int snapshotflag;
    rfid* myrfid;
    //初始化摄像头
    int camera_init();
    //捕捉画面保存成jpg图片
    int camera_capture();
    //关闭摄像头
    int camera_uninit();
    //重写父类QThread的run方法
    void run();
private:
        mycamera();
    static mycamera* m_instance;
    int camerafd;
    int lcdfd;
    int *lcdmem;
    TCPclient* myclient;
    struct camerabuf array[4]; //存放4个缓冲区的首地址和大小
    struct v4l2_buffer v4l2buf;
    enum v4l2_buf_type type;
};

#endif // MYCAMERA_H
