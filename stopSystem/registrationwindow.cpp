#include "registrationwindow.h"
#include "ui_registrationwindow.h"

registrationWindow::registrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationWindow)
{
    ui->setupUi(this);
    myclient=TCPclient::instance();
    QRegExp regExp("^[0-9]{1,11}$");// 匹配长度为1到1位的数字
    QValidator *validator =new QRegExpValidator(regExp,this);
    ui->lePhonenum->setValidator(validator);
    mytimer=new QTimer(this);
    mytimer->setInterval(300);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(phoneFun()));
    mytimer->start();

}

registrationWindow::~registrationWindow()
{
    delete ui;
}

//获取验证码
void registrationWindow::on_btnGet_clicked()
{
    qsrand(QTime::currentTime().msec()); // Properly seed the random number generator

    randomNumber = qrand() % 90000 + 10000; // Generate a 5-digit random number

    phonenumber = ui->lePhonenum->text();
    if (phonenumber.size() < 11) {
       auto myboox= QMessageBox::warning(this, "错误", "请正确输入11位手机号码!");
        return;
    }
    myclient->writeSocket("phoneNum@reg@"+phonenumber);
}

//确认注册
void registrationWindow::on_btnOk_clicked()
{
    QString phontemp=ui->lePhonenum->text();
    QString passwdtemp=ui->lePasswd->text();

    myclient->writeSocket("root@"+phontemp+"@"+passwdtemp);

    auto ret=QMessageBox::information(this,"成功","恭喜注册成功!");
    if(ret==QMessageBox::Ok)
    {
        this->parentWidget()->show();
        this->close();
    }
}

//取消注册
void registrationWindow::on_btnCancel_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void registrationWindow::phoneFun()
{
    //说明可以注册
    if(myclient->readSocket()=="Registration is possible")
    {
        //清空套接字，避免重复执行
        myclient->clearSocket();
        QString telphone(ui->lePhonenum->text());
        QUrl myUrl("http://gyytz.market.alicloudapi.com/sms/smsSend");
        QNetworkRequest myRequest(myUrl);
        QString appCode = "be7df08feec248cb9f0c04ead1d9fdec";
        QString host = "gyytz.market.alicloudapi.com";

        myRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        myRequest.setRawHeader("Authorization", "APPCODE " + appCode.toUtf8());
        myRequest.setRawHeader("Host", host.toUtf8());

        QUrlQuery postDataQuery;
        postDataQuery.addQueryItem("mobile", telphone);
        postDataQuery.addQueryItem("smsSignId", "2e65b1bb3d054466b82f0c9d125465e2");
        postDataQuery.addQueryItem("templateId", "908e94ccf08b4476ba6c876d13f084ad");
        postDataQuery.addQueryItem("param", QString("**code**:%2,**minute**:5").arg(randomNumber));

        QByteArray postData = postDataQuery.query().toUtf8();
        myRequest.setHeader(QNetworkRequest::ContentLengthHeader, QString::number(postData.size()));

        QNetworkReply *reply = myManager.post(myRequest, postData);
        if (reply->error()!= QNetworkReply::NoError) {
            QMessageBox::warning(this, "错误", "Failed to send SMS: " + reply->errorString());
        }
    }
    else if(myclient->readSocket()=="already registered")   //不可以注册
    {
        //清空套接字，避免重复执行
        myclient->clearSocket();
        QMessageBox::warning(this,"不可注册","该手机号已被注册，请重新输入!");
    }


}
