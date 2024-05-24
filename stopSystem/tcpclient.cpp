#include "tcpclient.h"
#include "ui_tcpclient.h"

// 初始化静态成员
TCPclient* TCPclient::m_instance = nullptr;

// 构造函数
TCPclient::TCPclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TCPclient),
    mySocket(new QTcpSocket(this))
{
    ui->setupUi(this);
    // 连接服务器
    this->setWindowTitle("客户端");
    QString strip("192.168.49.224");
    QString strport("10086");
    mySocket->connectToHost(strip, strport.toInt());
    connect(mySocket, SIGNAL(readyRead()), this, SLOT(recvServerMsg()));
    if (!mySocket->waitForConnected())
    {
        qDebug() << "Failed to connect to server.";
        // 连接失败，关闭socket
        mySocket->close();
        delete mySocket;
        mySocket = nullptr;
        exit(0);
    }
}

// 析构函数
TCPclient::~TCPclient()
{
    delete ui;
}

// 获取类的实例
TCPclient *TCPclient::instance()
{
    // 如果实例不存在，则创建一个新的实例
    if (!m_instance)
    {
        m_instance = new TCPclient();
    }
    return m_instance;
}

// 获取socket对象
QTcpSocket *TCPclient::getSocket()
{
    return mySocket;
}

// 读取socket数据
QString TCPclient::readSocket()
{
    return rbuf;
}

// 向socket写入数据
void TCPclient::writeSocket(QString str)
{
    mySocket->write(str.toUtf8());
}

void TCPclient::clearSocket()
{
    rbuf.clear();
}

// 接收服务器消息的槽函数
void TCPclient::recvServerMsg()
{
    rbuf = mySocket->readAll();
    qDebug()<<"tcpRead: "<<rbuf;
}
