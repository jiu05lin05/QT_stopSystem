#ifndef SOLFKEYUI_H
#define SOLFKEYUI_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class solfkeyui;
}

class solfkeyui : public QWidget
{
    Q_OBJECT

public:
    explicit solfkeyui(QWidget *parent = nullptr);
    ~solfkeyui();

private slots:


private:
    Ui::solfkeyui *ui;
    int keyflag;
};

#endif // SOLFKEYUI_H
