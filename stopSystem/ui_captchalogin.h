/********************************************************************************
** Form generated from reading UI file 'captchalogin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTCHALOGIN_H
#define UI_CAPTCHALOGIN_H

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

class Ui_captChaLogin
{
public:
    QLabel *label;
    QLineEdit *captChaLE;
    QPushButton *loginButton;
    QLabel *captChaLB;
    QLabel *accountLB;
    QPushButton *regButton;
    QLabel *titleLE;
    QLineEdit *phoneLE;
    solfkeyui *widget;
    QPushButton *getcapButton;

    void setupUi(QDialog *captChaLogin)
    {
        if (captChaLogin->objectName().isEmpty())
            captChaLogin->setObjectName(QStringLiteral("captChaLogin"));
        captChaLogin->resize(800, 480);
        captChaLogin->setMinimumSize(QSize(800, 480));
        captChaLogin->setMaximumSize(QSize(800, 480));
        label = new QLabel(captChaLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 30, 72, 15));
        captChaLE = new QLineEdit(captChaLogin);
        captChaLE->setObjectName(QStringLiteral("captChaLE"));
        captChaLE->setGeometry(QRect(220, 170, 191, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        captChaLE->setFont(font);
        captChaLE->setMaxLength(8);
        loginButton = new QPushButton(captChaLogin);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(170, 260, 91, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        loginButton->setFont(font1);
        captChaLB = new QLabel(captChaLogin);
        captChaLB->setObjectName(QStringLiteral("captChaLB"));
        captChaLB->setGeometry(QRect(150, 170, 50, 50));
        captChaLB->setMinimumSize(QSize(50, 50));
        captChaLB->setMaximumSize(QSize(50, 50));
        captChaLB->setSizeIncrement(QSize(200, 200));
        captChaLB->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/pic/captcha.jpg);"));
        accountLB = new QLabel(captChaLogin);
        accountLB->setObjectName(QStringLiteral("accountLB"));
        accountLB->setGeometry(QRect(150, 90, 50, 50));
        accountLB->setMinimumSize(QSize(50, 50));
        accountLB->setMaximumSize(QSize(50, 50));
        accountLB->setSizeIncrement(QSize(200, 200));
        accountLB->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/pic/phone.jpg);"));
        regButton = new QPushButton(captChaLogin);
        regButton->setObjectName(QStringLiteral("regButton"));
        regButton->setGeometry(QRect(490, 260, 91, 51));
        regButton->setFont(font1);
        titleLE = new QLabel(captChaLogin);
        titleLE->setObjectName(QStringLiteral("titleLE"));
        titleLE->setGeometry(QRect(240, 20, 471, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\227\346\204\217\351\273\221"));
        font2.setPointSize(22);
        font2.setItalic(true);
        titleLE->setFont(font2);
        phoneLE = new QLineEdit(captChaLogin);
        phoneLE->setObjectName(QStringLiteral("phoneLE"));
        phoneLE->setGeometry(QRect(220, 90, 391, 51));
        phoneLE->setFont(font);
        phoneLE->setMaxLength(11);
        widget = new solfkeyui(captChaLogin);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 320, 600, 150));
        widget->setMinimumSize(QSize(600, 150));
        widget->setMaximumSize(QSize(600, 150));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(236,142, 158);"));
        getcapButton = new QPushButton(captChaLogin);
        getcapButton->setObjectName(QStringLiteral("getcapButton"));
        getcapButton->setGeometry(QRect(450, 170, 151, 51));
        getcapButton->setFont(font);

        retranslateUi(captChaLogin);

        QMetaObject::connectSlotsByName(captChaLogin);
    } // setupUi

    void retranslateUi(QDialog *captChaLogin)
    {
        captChaLogin->setWindowTitle(QApplication::translate("captChaLogin", "Dialog", 0));
        label->setText(QString());
        captChaLE->setPlaceholderText(QApplication::translate("captChaLogin", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201", 0));
        loginButton->setText(QApplication::translate("captChaLogin", "\347\231\273\345\275\225", 0));
        captChaLB->setText(QString());
        accountLB->setText(QString());
        regButton->setText(QApplication::translate("captChaLogin", "\351\200\200\345\207\272", 0));
        titleLE->setText(QApplication::translate("captChaLogin", "\346\254\242\350\277\216\344\275\277\347\224\250\351\252\214\350\257\201\347\240\201\347\231\273\345\275\225", 0));
        phoneLE->setPlaceholderText(QApplication::translate("captChaLogin", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267\347\240\201", 0));
        getcapButton->setText(QApplication::translate("captChaLogin", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class captChaLogin: public Ui_captChaLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTCHALOGIN_H
