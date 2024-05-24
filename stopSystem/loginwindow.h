#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "tcpclient.h"
#include "registrationwindow.h"
#include "admininterface.h"
#include "captchalogin.h"
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();
    bool eventFilter(QObject *obj, QEvent *event);
    void getCameraflag(int* flag);
private slots:
    void on_eyeButton_clicked();

    void on_loginButton_clicked();

    void on_regButton_clicked();

private slots:
    void fun();

    void on_captCha_clicked();

private:
    Ui::loginWindow *ui;
    int eyeFlag;
    int loginflag;
    QTimer *mytimer;
    TCPclient *myclient;
    registrationWindow* myreg;
    adminInterface* myadm;
    int* cameraflag;
};

#endif // LOGINWINDOW_H
