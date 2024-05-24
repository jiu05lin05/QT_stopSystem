#ifndef RFID_H
#define RFID_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <strings.h>
#include <termios.h>
#include <string.h>
#include <QThread>
#include <QMutex>
#include <QString>
#include <QStringList>
#include <QDebug>

class rfid :public QThread
{
public:
    volatile unsigned int cardid ;
    struct timeval timeout;
    rfid();
    void run();
    //打开串口
    int open_serial();
    //配置串口
    void init_tty();
    //发送A命令
    int PiccRequest();
    //发送B命令
    int PiccAnticoll();
    int getrfidflag();
private:

    int fd; //串口的文件描述符
    int rfidflag;
    QStringList idList;
};

#endif // MYSERIAL_H
