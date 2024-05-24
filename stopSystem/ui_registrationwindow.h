/********************************************************************************
** Form generated from reading UI file 'registrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

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

class Ui_registrationWindow
{
public:
    QPushButton *btnCancel;
    QLineEdit *leEmail;
    QLabel *label;
    QLineEdit *lePasswd;
    QLineEdit *lePhonenum;
    QPushButton *btnOk;
    solfkeyui *widget;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *btnGet;

    void setupUi(QDialog *registrationWindow)
    {
        if (registrationWindow->objectName().isEmpty())
            registrationWindow->setObjectName(QStringLiteral("registrationWindow"));
        registrationWindow->resize(800, 480);
        registrationWindow->setMinimumSize(QSize(800, 480));
        registrationWindow->setMaximumSize(QSize(800, 480));
        btnCancel = new QPushButton(registrationWindow);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(480, 210, 91, 41));
        leEmail = new QLineEdit(registrationWindow);
        leEmail->setObjectName(QStringLiteral("leEmail"));
        leEmail->setGeometry(QRect(260, 150, 200, 40));
        leEmail->setMinimumSize(QSize(0, 40));
        leEmail->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        leEmail->setFont(font);
        label = new QLabel(registrationWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 10, 211, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        label->setFont(font1);
        lePasswd = new QLineEdit(registrationWindow);
        lePasswd->setObjectName(QStringLiteral("lePasswd"));
        lePasswd->setGeometry(QRect(260, 100, 350, 40));
        lePasswd->setMinimumSize(QSize(0, 40));
        lePasswd->setMaximumSize(QSize(16777215, 40));
        lePasswd->setFont(font);
        lePasswd->setMaxLength(8);
        lePhonenum = new QLineEdit(registrationWindow);
        lePhonenum->setObjectName(QStringLiteral("lePhonenum"));
        lePhonenum->setGeometry(QRect(260, 50, 350, 40));
        lePhonenum->setMinimumSize(QSize(0, 40));
        lePhonenum->setMaximumSize(QSize(16777215, 40));
        lePhonenum->setFont(font);
        lePhonenum->setMaxLength(11);
        btnOk = new QPushButton(registrationWindow);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(240, 210, 91, 41));
        widget = new solfkeyui(registrationWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 280, 600, 160));
        widget->setMinimumSize(QSize(600, 160));
        widget->setMaximumSize(QSize(600, 160));
        label_3 = new QLabel(registrationWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 110, 71, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        label_3->setFont(font2);
        label_4 = new QLabel(registrationWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 60, 101, 21));
        label_4->setFont(font2);
        label_5 = new QLabel(registrationWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(140, 160, 71, 21));
        label_5->setFont(font2);
        btnGet = new QPushButton(registrationWindow);
        btnGet->setObjectName(QStringLiteral("btnGet"));
        btnGet->setGeometry(QRect(520, 150, 91, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("AcadEref"));
        font3.setPointSize(8);
        btnGet->setFont(font3);

        retranslateUi(registrationWindow);

        QMetaObject::connectSlotsByName(registrationWindow);
    } // setupUi

    void retranslateUi(QDialog *registrationWindow)
    {
        registrationWindow->setWindowTitle(QApplication::translate("registrationWindow", "Dialog", 0));
        btnCancel->setText(QApplication::translate("registrationWindow", "\345\217\226\346\266\210", 0));
        leEmail->setPlaceholderText(QApplication::translate("registrationWindow", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201", 0));
        label->setText(QApplication::translate("registrationWindow", "\346\254\242\350\277\216\346\263\250\345\206\214\350\264\246\345\217\267", 0));
        lePasswd->setPlaceholderText(QApplication::translate("registrationWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        lePhonenum->setText(QString());
        lePhonenum->setPlaceholderText(QApplication::translate("registrationWindow", "\350\257\267\350\276\223\345\205\245\346\211\213\346\234\272\345\217\267\347\240\201", 0));
        btnOk->setText(QApplication::translate("registrationWindow", "\347\241\256\345\256\232\346\263\250\345\206\214", 0));
        label_3->setText(QApplication::translate("registrationWindow", "\345\257\206\347\240\201:", 0));
        label_4->setText(QApplication::translate("registrationWindow", "\346\211\213\346\234\272\345\217\267\347\240\201:", 0));
        label_5->setText(QApplication::translate("registrationWindow", "\351\252\214\350\257\201\347\240\201:", 0));
        btnGet->setText(QApplication::translate("registrationWindow", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class registrationWindow: public Ui_registrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H
