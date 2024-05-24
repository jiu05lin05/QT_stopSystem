#ifndef CAPTCHALOGIN_H
#define CAPTCHALOGIN_H

#include <QDialog>
#include <QIntValidator>
#include "tcpclient.h"
#include "admininterface.h"
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
#include <QMessageBox>
#include <QTime>
#include <QUrlQuery>
#include <QTimer>

//#include <QRandomGenerator>

namespace Ui {
class captChaLogin;
}

class captChaLogin : public QDialog
{
    Q_OBJECT

public:
    explicit captChaLogin(QWidget *parent = nullptr);
    ~captChaLogin();
    bool eventFilter(QObject *obj, QEvent *event);
private slots:
    void on_regButton_clicked();

    void on_loginButton_clicked();

    void on_getcapButton_clicked();

    void fun(QNetworkReply *rep);

    void phoneFun();
private:
    Ui::captChaLogin *ui;
    TCPclient* myclient;
    QNetworkAccessManager myManager;
    QTimer *mytimer;
    QString phonenumber;
    int randomNumber;
};

#endif // CAPTCHALOGIN_H
