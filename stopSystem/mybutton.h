#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QApplication>
class mybutton : public QPushButton
{
    Q_OBJECT
public:
    mybutton(QWidget *parent = nullptr);
private slots:
    void fun();

private:

};

#endif // MYBUTTON_H
