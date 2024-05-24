/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <solfkeyui.h>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QPushButton *loginButton;
    QLabel *accountLB;
    QLabel *titleLE;
    QLineEdit *passwdLE;
    QPushButton *eyeButton;
    solfkeyui *widget;
    QLineEdit *accountLE;
    QPushButton *regButton;
    QLabel *passwdLB;
    QPushButton *captCha;

    void setupUi(QDialog *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QStringLiteral("loginWindow"));
        loginWindow->resize(800, 480);
        loginWindow->setMinimumSize(QSize(800, 480));
        loginWindow->setMaximumSize(QSize(800, 480));
        loginWindow->setStyleSheet(QStringLiteral("QMainWindow{border-image: url(:/new/prefix1/pic/city.jpg);}"));
        loginButton = new QPushButton(loginWindow);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(150, 260, 91, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        loginButton->setFont(font);
        accountLB = new QLabel(loginWindow);
        accountLB->setObjectName(QStringLiteral("accountLB"));
        accountLB->setGeometry(QRect(130, 90, 50, 50));
        accountLB->setMinimumSize(QSize(50, 50));
        accountLB->setMaximumSize(QSize(50, 50));
        accountLB->setSizeIncrement(QSize(200, 200));
        accountLB->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/pic/acc.jpg);"));
        titleLE = new QLabel(loginWindow);
        titleLE->setObjectName(QStringLiteral("titleLE"));
        titleLE->setGeometry(QRect(220, 20, 471, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\227\346\204\217\351\273\221"));
        font1.setPointSize(22);
        font1.setItalic(true);
        titleLE->setFont(font1);
        passwdLE = new QLineEdit(loginWindow);
        passwdLE->setObjectName(QStringLiteral("passwdLE"));
        passwdLE->setGeometry(QRect(200, 170, 391, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        passwdLE->setFont(font2);
        passwdLE->setMaxLength(8);
        eyeButton = new QPushButton(loginWindow);
        eyeButton->setObjectName(QStringLiteral("eyeButton"));
        eyeButton->setGeometry(QRect(600, 180, 40, 40));
        eyeButton->setMinimumSize(QSize(40, 40));
        eyeButton->setMaximumSize(QSize(40, 40));
        eyeButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/pic/passon.jpg);"));
        widget = new solfkeyui(loginWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 320, 600, 150));
        widget->setMinimumSize(QSize(600, 150));
        widget->setMaximumSize(QSize(600, 150));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(236,142, 158);"));
        accountLE = new QLineEdit(loginWindow);
        accountLE->setObjectName(QStringLiteral("accountLE"));
        accountLE->setGeometry(QRect(200, 90, 391, 51));
        accountLE->setFont(font2);
        accountLE->setMaxLength(11);
        regButton = new QPushButton(loginWindow);
        regButton->setObjectName(QStringLiteral("regButton"));
        regButton->setGeometry(QRect(470, 260, 91, 51));
        regButton->setFont(font);
        passwdLB = new QLabel(loginWindow);
        passwdLB->setObjectName(QStringLiteral("passwdLB"));
        passwdLB->setGeometry(QRect(130, 170, 50, 50));
        passwdLB->setMinimumSize(QSize(50, 50));
        passwdLB->setMaximumSize(QSize(50, 50));
        passwdLB->setSizeIncrement(QSize(200, 200));
        passwdLB->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/pic/lock.jpg);"));
        captCha = new QPushButton(loginWindow);
        captCha->setObjectName(QStringLiteral("captCha"));
        captCha->setGeometry(QRect(310, 270, 91, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(9);
        captCha->setFont(font3);

        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QDialog *loginWindow)
    {
        loginWindow->setWindowTitle(QApplication::translate("loginWindow", "Dialog", 0));
        loginButton->setText(QApplication::translate("loginWindow", "\347\231\273\345\275\225", 0));
        accountLB->setText(QString());
        titleLE->setText(QApplication::translate("loginWindow", "\346\254\242\350\277\216\347\231\273\345\275\225\347\256\241\347\220\206\345\221\230\347\263\273\347\273\237", 0));
        passwdLE->setPlaceholderText(QApplication::translate("loginWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        eyeButton->setText(QString());
        accountLE->setPlaceholderText(QApplication::translate("loginWindow", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267\347\240\201", 0));
        regButton->setText(QApplication::translate("loginWindow", "\346\263\250\345\206\214", 0));
        passwdLB->setText(QString());
        captCha->setText(QApplication::translate("loginWindow", "\351\252\214\350\257\201\347\240\201\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
