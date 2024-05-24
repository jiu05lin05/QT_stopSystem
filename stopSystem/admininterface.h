#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "tcpclient.h"
#include "mycamera.h"
#include <QTableWidget>

namespace Ui {
class adminInterface;
}

class adminInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminInterface(QWidget *parent = nullptr);
    ~adminInterface();
    void getCameraflag(int* flag);
private slots:
    void on_pushButton_clicked();

    void on_get_clicked();

    void on_confirm_clicked();

    void on_get_2_clicked();

private:
    Ui::adminInterface *ui;
    TCPclient* myclient;
    int* cameraflag;
    mycamera* myc;
};

#endif // ADMININTERFACE_H
