#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "tcpclient.h"
#include <QIntValidator>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QBuffer>
#include <QUrlQuery>
#include <QMessageBox>
#include <QTime>
#include <QTimer>

namespace Ui {
class registrationWindow;
}

class registrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit registrationWindow(QWidget *parent = nullptr);
    ~registrationWindow();

private slots:
    void on_btnGet_clicked();

    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void phoneFun();
private:
    Ui::registrationWindow *ui;
    TCPclient *myclient;
    QTimer* mytimer;
    int randomNumber;
    QString phonenumber;
    QNetworkAccessManager myManager;
};

#endif // REGISTRATIONWINDOW_H
