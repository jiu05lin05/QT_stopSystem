#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QListWidgetItem>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QMessageBox>
#include <QTime>
#include <QThread>

#define DBPATH  "D:/Work/information/share/QT_Project/systemTCPServer/system.db"
#define CLIENTIP   QHostAddress("192.168.49.224")
#define CLIENTPORT  5548
#define SERVERIP   QHostAddress("192.168.49.224")
#define SERVERPORT  10086

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void fun();
    void recvClientMsg();
    void discon();
private:
    Ui::MainWindow *ui;
    QTcpServer* myserver;
    QTcpSocket* newSocket;
    QList<QTcpSocket*> clientSockets;
    QString clientstr;
    QSqlDatabase base1;
    QSqlQuery *query1;
    QString cmd;
};
#endif // MAINWINDOW_H
