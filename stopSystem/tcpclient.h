#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class TCPclient;
}

class TCPclient : public QDialog
{
    Q_OBJECT

public:
    explicit TCPclient(QWidget *parent = nullptr);
    ~TCPclient();

    static TCPclient* instance(); // 获取类的实例
    QTcpSocket* getSocket(); // 获取socket对象
    QString readSocket(); // 读取socket数据
    void writeSocket(QString str); // 向socket写入数据
    void clearSocket();
private slots:
    void recvServerMsg(); // 接收服务器消息的槽函数

private:
    Ui::TCPclient *ui;
    QTcpSocket* mySocket; // socket对象
    QString rbuf; // 用于存储接收到的数据
    static TCPclient* m_instance; // 类的唯一实例对象
};

#endif // TCPCLIENT_H
