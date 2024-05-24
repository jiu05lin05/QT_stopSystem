#include "captchalogin.h"
#include "ui_captchalogin.h"

captChaLogin::captChaLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::captChaLogin)
{
    ui->setupUi(this);
    //获取网络对象
    myclient=TCPclient::instance();
    QRegExp regExp("^[0-9]{1,11}$");// 匹配长度为1到11位的数字
    QValidator *validator =new QRegExpValidator(regExp,this);
    ui->phoneLE->setValidator(validator);
    // 将单行输入框安装事件过滤器
    ui->phoneLE->installEventFilter(this);
    ui->captChaLE->installEventFilter(this);
    //刚进入界面时先将软键盘隐藏
    ui->widget->hide();
    ui->loginButton->setFocus();
    connect(&myManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fun(QNetworkReply*)));
    mytimer=new QTimer(this);
    mytimer->setInterval(300);
    mytimer->start();
    connect(mytimer,SIGNAL(timeout()),this,SLOT(phoneFun()));

}

captChaLogin::~captChaLogin()
{
    delete ui;
}

//注册按钮
void captChaLogin::on_regButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}

//登录按钮
void captChaLogin::on_loginButton_clicked()
{
    QString num=QString::number(randomNumber);
    qDebug()<<num;
    qDebug()<<ui->captChaLE->text();
    if(ui->captChaLE->text()==num)
    {
        QMessageBox::information(this,"正确","验证码正确!");
        adminInterface* myadm=new adminInterface(this);
        myadm->show();
        this->hide();
    }
    else
    {
        QMessageBox::warning(this,"错误","验证码错误!");
    }
}

bool captChaLogin::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->phoneLE || obj == ui->captChaLE) {
        if (event->type() == QEvent::FocusIn) {
            // 获取焦点时显示软键盘
            ui->widget->show();
        }
    }
    return QDialog::eventFilter(obj, event); // 修改此处的返回值
}

//获取验证码
void captChaLogin::on_getcapButton_clicked()
{
    qsrand(QTime::currentTime().msec()); // Properly seed the random number generator

    randomNumber = qrand() % 90000 + 10000; // Generate a 5-digit random number

    phonenumber = ui->phoneLE->text();
    if (phonenumber.size() < 11) {
        QMessageBox::warning(this, "错误", "请正确输入11位手机号码!");
        return;
    }
    myclient->writeSocket("phoneNum@login@"+phonenumber);
}

void captChaLogin::fun(QNetworkReply *rep)
{
    // 读取应答信息
    QByteArray buf = rep->readAll();

    // 输出 HTTP 状态码
    qDebug() << "HTTP status code:" << rep->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    // 输出错误信息
    qDebug() << "Error:" << rep->errorString();

}

//读取服务器发来的手机号正确
void captChaLogin::phoneFun()
{
    if(myclient->readSocket()=="can log in")
    {
        //清空套接字，避免多次发送
        myclient->clearSocket();
        QUrl myUrl("http://gyytz.market.alicloudapi.com/sms/smsSend");
        QNetworkRequest myRequest(myUrl);
        QString appCode = "be7df08feec248cb9f0c04ead1d9fdec";
        QString host = "gyytz.market.alicloudapi.com";

        myRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        myRequest.setRawHeader("Authorization", "APPCODE " + appCode.toUtf8());
        myRequest.setRawHeader("Host", host.toUtf8());

        QUrlQuery postDataQuery;
        postDataQuery.addQueryItem("mobile", phonenumber);
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
    else if(myclient->readSocket()=="Not registered")
    {
        //清空套接字，避免多次发送
        myclient->clearSocket();
        QMessageBox::warning(this,"未注册的用户","请先注册账号后再进行登录!");
    }
}
