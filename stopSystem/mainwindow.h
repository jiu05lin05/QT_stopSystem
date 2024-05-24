#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStringList>
#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QBuffer>
#include <QImage>
#include "tcpclient.h"
#include "keyconfirmation.h"
#include "mycamera.h"

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
    void on_previous_clicked();

    void on_next_clicked();

    void on_previous_2_clicked();

    void fun();

    void timerfun();

    void responseFun(QNetworkReply *rep);

    void weatherFun(QNetworkReply *rep);

    void timeChange();

    void readSocketMsg();
private:
    Ui::MainWindow *ui;
    int flag;
    enum InterfaceState {
        InterfaceState_W1,
        InterfaceState_W2,
        InterfaceState_W3
    };
    InterfaceState currentState;
    QTimer* mytimer;
    QTimer* timetimer;
    QTimer* socketTimer;
    mycamera* myc;
    TCPclient* myclient;
    QTime time;
    QStringList idList;
    QString plateNumber;
    QString curButton;
    QImage myImage;
    QByteArray byteAr;
    QBuffer buf;
    int residualnum;
    QNetworkAccessManager myManager;
    QNetworkAccessManager myWeatherManager;
    void switchInterfaceState(InterfaceState state);


};
#endif // MAINWINDOW_H
