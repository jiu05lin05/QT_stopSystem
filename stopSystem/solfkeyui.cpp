#include "solfkeyui.h"
#include "ui_solfkeyui.h"

solfkeyui::solfkeyui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::solfkeyui)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_KeyCompression);
}

solfkeyui::~solfkeyui()
{
    delete ui;
}
