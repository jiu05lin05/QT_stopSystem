/********************************************************************************
** Form generated from reading UI file 'admininterface.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMININTERFACE_H
#define UI_ADMININTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <solfkeyui.h>

QT_BEGIN_NAMESPACE

class Ui_adminInterface
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    solfkeyui *widget;
    QPushButton *get;
    QPushButton *get_2;
    QPushButton *confirm;

    void setupUi(QMainWindow *adminInterface)
    {
        if (adminInterface->objectName().isEmpty())
            adminInterface->setObjectName(QStringLiteral("adminInterface"));
        adminInterface->resize(800, 480);
        adminInterface->setMinimumSize(QSize(800, 480));
        adminInterface->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(adminInterface);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(710, 320, 71, 51));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 801, 301));
        widget = new solfkeyui(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 310, 600, 160));
        widget->setMinimumSize(QSize(600, 160));
        widget->setMaximumSize(QSize(600, 160));
        get = new QPushButton(centralwidget);
        get->setObjectName(QStringLiteral("get"));
        get->setGeometry(QRect(10, 320, 71, 51));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(8);
        get->setFont(font);
        get->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        get_2 = new QPushButton(centralwidget);
        get_2->setObjectName(QStringLiteral("get_2"));
        get_2->setGeometry(QRect(10, 400, 71, 51));
        get_2->setFont(font);
        get_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        confirm = new QPushButton(centralwidget);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(710, 410, 71, 51));
        confirm->setFont(font);
        confirm->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        adminInterface->setCentralWidget(centralwidget);

        retranslateUi(adminInterface);

        QMetaObject::connectSlotsByName(adminInterface);
    } // setupUi

    void retranslateUi(QMainWindow *adminInterface)
    {
        adminInterface->setWindowTitle(QApplication::translate("adminInterface", "MainWindow", 0));
        pushButton->setText(QApplication::translate("adminInterface", "\350\277\224\345\233\236", 0));
        get->setText(QApplication::translate("adminInterface", "\350\216\267\345\217\226\344\277\241\346\201\257", 0));
        get_2->setText(QApplication::translate("adminInterface", "\345\210\240\351\231\244", 0));
        confirm->setText(QApplication::translate("adminInterface", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
    } // retranslateUi

};

namespace Ui {
    class adminInterface: public Ui_adminInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMININTERFACE_H
