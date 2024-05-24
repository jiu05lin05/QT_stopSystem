#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    //将标志位置为0 最开始显示的是普通模式
    eyeFlag=0;
    // 将单行输入框安装事件过滤器
    ui->accountLE->installEventFilter(this);
    ui->passwdLE->installEventFilter(this);
    //刚进入界面时先将软键盘隐藏
    ui->widget->hide();
    ui->loginButton->setFocus();
    //获取网络对象
    myclient=TCPclient::instance();

    QRegExp regExp("^[0-9]{1,11}$");// 匹配长度为1到1位的数字
    QValidator *validator =new QRegExpValidator(regExp,this);
    ui->accountLE->setValidator(validator);

    mytimer=new QTimer(this);
    mytimer->setInterval(200);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(fun()));
}

loginWindow::~loginWindow()
{
    delete ui;
}

bool loginWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->accountLE || obj == ui->passwdLE) {
        if (event->type() == QEvent::FocusIn) {
            // 获取焦点时显示软键盘
            ui->widget->show();
        }
    }
    return QDialog::eventFilter(obj, event); // 修改此处的返回值
}

void loginWindow::getCameraflag(int *flag)
{
    cameraflag=flag;
}

//显示密码模式
void loginWindow::on_eyeButton_clicked()
{
    if(eyeFlag==1)
    {
        //eyeFlag为1 显示模式
        ui->eyeButton->setStyleSheet("border-image: url(:/new/prefix1/pic/passon.jpg);");
        ui->passwdLE->setEchoMode(QLineEdit::Normal);
        //qDebug()<<"flag is: "<<eyeFlag;
    }
    else if(eyeFlag==0)
    {
        //eyeFlag为0 密码模式
        ui->eyeButton->setStyleSheet("border-image: url(:/new/prefix1/pic/passoff.jpg)");
        ui->passwdLE->setEchoMode(QLineEdit::Password);
        //qDebug()<<"flag is: "<<eyeFlag;
    }
    eyeFlag=!eyeFlag;
    ui->widget->hide();
}

//登录按钮
void loginWindow::on_loginButton_clicked()
{
    ui->widget->show();
    //获取账号密码输入框中的文本
    QString account(ui->accountLE->text());
    QString passwd(ui->passwdLE->text());

    myclient->writeSocket(QString("login@"+account+'@'+passwd).toUtf8());

    ui->accountLE->clear();
    ui->passwdLE->clear();
    mytimer->start();
}

//注册按钮
void loginWindow::on_regButton_clicked()
{
    myreg=new registrationWindow(this);
    myreg->show();
    this->hide();
}

void loginWindow::fun()
{
    mytimer->stop();
    QString buf=myclient->readSocket();
    if(buf=="Login successful")
    {
        myclient->clearSocket();
        myadm=new adminInterface(this);
        myadm->getCameraflag(this->cameraflag);
        myadm->show();
        this->hide();
    }
    else if(buf=="Login fail")
    {
        myclient->clearSocket();
        QMessageBox::warning(this,"错误","账号或密码错误!");
        mytimer->start();
    }
}

void loginWindow::on_captCha_clicked()
{
    captChaLogin* mycap=new captChaLogin(this);
    mycap->show();
    this->hide();
}
