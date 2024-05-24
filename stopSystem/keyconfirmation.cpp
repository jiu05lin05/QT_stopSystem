#include "keyconfirmation.h"
#include "ui_keyconfirmation.h"

keyConfirmation::keyConfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyConfirmation)
{
    ui->setupUi(this);
    mytimer=new QTimer(this);
    mytimer->setInterval(300);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(fun()));
    myclient=TCPclient::instance();
    // 将单行输入框安装事件过滤器
    ui->lineEdit->installEventFilter(this);
}

keyConfirmation::~keyConfirmation()
{
    delete ui;
}

//确定按钮
void keyConfirmation::on_pushButton_clicked()
{
    myclient->writeSocket("key@"+ui->lineEdit->text());
    mytimer->start();
}

//退出按钮
void keyConfirmation::on_pushButton_2_clicked()
{
    this->close();
    mytimer->stop();
    this->parentWidget()->show();
}

void keyConfirmation::fun()
{
    QString temp=myclient->readSocket();
    qDebug()<<"读取到套接字: "<<temp;
    if(temp=="The key is correct")
    {
        mytimer->stop();
        //说明密钥正确,跳转到登录界面
        loginWindow* mylogin=new loginWindow(this);
        mylogin->getCameraflag(this->cameraflag);
        mylogin->show();
        this->hide();
    }
    else
    {
        mytimer->stop();
        ui->lineEdit->clear();
        QMessageBox::warning(this,"错误","密钥错误!");
    }
}

bool keyConfirmation::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->lineEdit) {
        if (event->type() == QEvent::FocusIn) {
            // 获取焦点时显示软键盘
            ui->widget->show();
        }
    }
    return QDialog::eventFilter(obj, event); // 修改此处的返回值
}

void keyConfirmation::getCameraflag(int *flag)
{
    cameraflag=flag;
}
