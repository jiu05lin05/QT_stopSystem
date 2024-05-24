#include "mainwindow.h"
#include "tcpclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 创建 TCPclient 类的实例
    TCPclient* mytcp = TCPclient::instance();
    MainWindow w;
    w.show();
    return a.exec();
}
