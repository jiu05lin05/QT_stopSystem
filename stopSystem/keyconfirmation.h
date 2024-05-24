#ifndef KEYCONFIRMATION_H
#define KEYCONFIRMATION_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>
#include "tcpclient.h"
#include "loginwindow.h"

namespace Ui {
class keyConfirmation;
}

class keyConfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit keyConfirmation(QWidget *parent = nullptr);
    ~keyConfirmation();
    bool eventFilter(QObject *obj, QEvent *event);
    void getCameraflag(int* flag);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void fun();
private:
    Ui::keyConfirmation *ui;
    TCPclient *myclient;
    QTimer *mytimer;
    int* cameraflag;
};

#endif // KEYCONFIRMATION_H
