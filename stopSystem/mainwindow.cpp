#include "mainwindow.h"
#include "ui_mainwindow.h"

QString parseJsonAndGetPlateNumber(const QString& jsonString) {
    QString plateNumber;

    // 将 JSON 字符串转换为 QJsonDocument 对象
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());

    // 获取 QJsonObject 对象
    QJsonObject jsonObj = jsonDoc.object();

    // 获取车牌号对应的值
    QJsonValue plateValue = jsonObj["plates"].toArray().at(0).toObject()["txt"];

    // 将 QJsonValue 转换为字符串
    if (plateValue.isString()) {
        plateNumber = plateValue.toString();
    }

    return plateNumber;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化当前状态为第一个状态
    currentState = InterfaceState_W1;

    // 初始界面显示第一个状态
    switchInterfaceState(currentState);
    residualnum=15;
    ui->residualInfo->display(residualnum);
    //显示时间
    time = QTime::currentTime();
    ui->timeInfo->display(time.toString("hh:mm:ss"));
    timetimer=new QTimer(this);
    timetimer->setInterval(1000);
    timetimer->start();
    connect(timetimer,SIGNAL(timeout()),this,SLOT(timeChange()));

    //禁用所有按钮
    ui->W1->setEnabled(false);
    ui->W2->setEnabled(false);
    ui->W3->setEnabled(false);

    //获取时间
    QDate date = QDate::currentDate();
    ui->dateInfo->display(date.toString("yyyy-MM-dd"));

    qDebug() << "Current date:" << date.toString("yyyy-MM-dd");
    qDebug() << "Current time:" << time.toString("hh:mm:ss");

    socketTimer=new QTimer(this);
    socketTimer->setInterval(500);
    connect(socketTimer,SIGNAL(timeout()),this,SLOT(readSocketMsg()));
    socketTimer->start();
    connect(ui->A1,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->A2,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->A3,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->A4,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->A5,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->B1,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->B2,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->B3,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->B4,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->B5,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->C1,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->C2,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->C3,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->C4,SIGNAL(clicked()),this,SLOT(fun()));
    connect(ui->C5,SIGNAL(clicked()),this,SLOT(fun()));


     myc = mycamera::getInstance();
    //初始化摄像头
    myc->camera_init();
    myc->start();
    myclient=TCPclient::instance();
    mytimer=new QTimer(this);
    mytimer->setInterval(900);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(timerfun()));
    mytimer->start();
    //关联网络车牌识别api
    connect(&myManager,SIGNAL(finished(QNetworkReply *)),this,SLOT(responseFun(QNetworkReply *)));

    //关联天气api
    connect(&myWeatherManager,SIGNAL(finished(QNetworkReply *)),this,SLOT(weatherFun(QNetworkReply *)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// 上一页按钮点击槽函数
void MainWindow::on_previous_clicked()
{
    // 如果当前状态不是第一个状态，则切换到前一个状态
    if (currentState > InterfaceState_W1) {
        currentState = static_cast<InterfaceState>(currentState - 1);
        switchInterfaceState(currentState);
    }
}

// 下一页按钮点击槽函数
void MainWindow::on_next_clicked()
{
    // 如果当前状态不是最后一个状态，则切换到下一个状态
    if (currentState < InterfaceState_W3) {
        currentState = static_cast<InterfaceState>(currentState + 1);
        switchInterfaceState(currentState);
    }
}

// 切换界面状态的函数
void MainWindow::switchInterfaceState(MainWindow::InterfaceState state)
{
    // 根据状态设置界面的可见性
    ui->W1->setVisible(state == InterfaceState_W1);
    ui->W2->setVisible(state == InterfaceState_W2);
    ui->W3->setVisible(state == InterfaceState_W3);

    // 根据状态设置 "上一页" 和 "下一页" 按钮的可用性
    ui->previous->setEnabled(state != InterfaceState_W1);
    ui->next->setEnabled(state != InterfaceState_W3);
}

//点击"我是管理员"进入到密钥确认界面
void MainWindow::on_previous_2_clicked()
{
    myc->cameraflag=0;
    keyConfirmation* mykey=new keyConfirmation(this);
    mykey->getCameraflag( &(this->myc->cameraflag));
    mykey->show();
    this->hide();
}

//选择车位
void MainWindow::fun()
{
    QObject *p=sender();
    QPushButton* currentButton=qobject_cast<QPushButton*>(p);
    qDebug()<<"点击了按钮:"<<currentButton->text()<<" "<<currentButton;
    currentButton->setStyleSheet("background-color: rgb(144, 75, 106);");
    curButton=currentButton->text();

    QUrl myUrl("http://ocrcp.market.alicloudapi.com/rest/160601/ocr/ocr_vehicle_plate.json");
    QNetworkRequest myRequest(myUrl);
    QString appCode = "APPCODE be7df08feec248cb9f0c04ead1d9fdec";
    QString host = "ocrcp.market.alicloudapi.com";
    myRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    myRequest.setRawHeader("Authorization", appCode.toLocal8Bit());
    myRequest.setRawHeader("Host", host.toLocal8Bit());

    QJsonObject jsonObj;
    jsonObj.insert("image", byteAr.toBase64().data());
    jsonObj.insert("configure", "{\"multi_crop\":true}");
    QJsonDocument jsonDoc = QJsonDocument(jsonObj);
    QByteArray post_data = jsonDoc.toJson(QJsonDocument::Compact);
    myManager.post(myRequest, post_data);

    //将所有按钮widget禁用，只有刷了入库卡的时候可用
    ui->residualInfo->display(--residualnum);
    ui->W1->setEnabled(false);
    ui->W2->setEnabled(false);
    ui->W3->setEnabled(false);
}

//读取是否抓拍到车牌照片
void MainWindow::timerfun()
{
    if(myc->snapshotflag==1)
    {
        qDebug()<<"发送了车牌识别请求";
        myImage.load("./pic.jpg");  // 赋值
        buf.close(); // 关闭缓冲区
        buf.setBuffer(&byteAr);  // 赋值
        myImage.save(&buf, "JPG");
        QString cmd="judgment@"+QString::number(myc->myrfid->cardid,16);

        QPixmap pixmap("./pic.jpg");
        ui->pic->setPixmap(pixmap);
        ui->pic->setScaledContents(true); // 将图片缩放到标签的大小

        myclient->writeSocket(cmd);
    }
}

//车牌应答
void MainWindow::responseFun(QNetworkReply *rep)
{
    //读取应答信息
    QByteArray buf=rep->readAll();
    qDebug()<<"读取到车牌应答";
    qDebug()<<buf;

    QString jsonString(buf);
    plateNumber = parseJsonAndGetPlateNumber(jsonString);
    qDebug() << "车牌号：" << plateNumber;
    qDebug()<<"rfid号: "<<  QString::number(myc->myrfid->cardid,16);
    if(buf!="Invalid Result - parse plate failed")
    {
        //获取当前时间
        QTime currentTime = QTime::currentTime();
        QString timeString = currentTime.toString("hh:mm:ss");
        //将用户信息发送给服务器
        myclient->writeSocket("user@"+QString::number(myc->myrfid->cardid,16)+"@"+plateNumber+"@"+curButton+"@"+timeString);
    }
    else
    {
        myclient->writeSocket("judgment@error@"+QString::number(myc->myrfid->cardid,16));
    }
}

//天气应答
void MainWindow::weatherFun(QNetworkReply *rep)
{
    //读取应答信息
    QByteArray buf=rep->readAll();
    qDebug()<<"读取到天气应答weather";
    qDebug()<<buf;
    QString sbuf(buf);
    //ui->textBrowser->setText(sbuf);
}

//让时间动起来
void MainWindow::timeChange()
{
    QTime time = QTime::currentTime();
    ui->timeInfo->display(time.toString("hh:mm:ss"));
}

//循环读取服务器发来的信息
void MainWindow::readSocketMsg()
{
    QString rbuf=myclient->readSocket();
    QStringList temp=rbuf.split('@');

    if(temp.at(0)=="in")    //车主入库
    {
        qDebug()<<"get in";
        ui->W1->setEnabled(true);
        ui->W2->setEnabled(true);
        ui->W3->setEnabled(true);
        myclient->clearSocket();
    }
    else if(temp.at(0)=="out") //车主出库
    {
        qDebug()<<"get out";
        QList<QObject*> components = {ui->W1, ui->W2, ui->W3};
        foreach (QObject *component, components) {
            QList<QPushButton*> buttons = component->findChildren<QPushButton*>();
            for (QPushButton *button : buttons) {
                if (button->text() == temp.at(1)) {
                    qDebug()<<"button is: "<<button->text();
                    // 找到按钮了
                    button->setStyleSheet("background-color: rgb(255, 255, 255);");
                    break;
                }
            }
        }
        ui->W1->setEnabled(false);
        ui->W2->setEnabled(false);
        ui->W3->setEnabled(false);
        QTime storedTime = QTime::fromString(temp.at(2), "hh:mm:ss");
        QTime currentTime = QTime::currentTime();
        int timeDifferenceMilliseconds = qAbs(currentTime.msecsTo(storedTime));
        int timeDifferenceSeconds = timeDifferenceMilliseconds / 1000;

        QString timeDifferenceString = QString("%1 seconds").arg(timeDifferenceSeconds);
        qDebug() << "time and price is:  " << timeDifferenceString;
        QString temp("请缴费"+timeDifferenceString);
        QMessageBox::information(this,"欢迎再次光临",temp);
        ui->residualInfo->display(++residualnum);
        myclient->clearSocket();
    }else if(temp.at(0)=="cameraUp")
    {
        qDebug()<<"cameraflag=1";
        this->myc->cameraflag=1;
        myclient->clearSocket();
    }

}
