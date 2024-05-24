/********************************************************************************
** Form generated from reading UI file 'keyconfirmation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYCONFIRMATION_H
#define UI_KEYCONFIRMATION_H

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

class Ui_keyConfirmation
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    solfkeyui *widget;

    void setupUi(QDialog *keyConfirmation)
    {
        if (keyConfirmation->objectName().isEmpty())
            keyConfirmation->setObjectName(QStringLiteral("keyConfirmation"));
        keyConfirmation->resize(800, 480);
        keyConfirmation->setMinimumSize(QSize(800, 480));
        keyConfirmation->setMaximumSize(QSize(800, 480));
        keyConfirmation->setSizeIncrement(QSize(0, 0));
        keyConfirmation->setStyleSheet(QStringLiteral("QDialog{border-image: url(:/new/prefix1/pic/city.jpg);}"));
        label = new QLabel(keyConfirmation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 10, 381, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(22);
        label->setFont(font);
        lineEdit = new QLineEdit(keyConfirmation);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 80, 391, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(20);
        lineEdit->setFont(font1);
        pushButton = new QPushButton(keyConfirmation);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 150, 91, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(keyConfirmation);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 150, 91, 41));
        pushButton_2->setFont(font2);
        widget = new solfkeyui(keyConfirmation);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 230, 600, 160));
        widget->setMinimumSize(QSize(600, 160));
        widget->setMaximumSize(QSize(600, 160));

        retranslateUi(keyConfirmation);

        QMetaObject::connectSlotsByName(keyConfirmation);
    } // setupUi

    void retranslateUi(QDialog *keyConfirmation)
    {
        keyConfirmation->setWindowTitle(QApplication::translate("keyConfirmation", "Dialog", 0));
        label->setText(QApplication::translate("keyConfirmation", "\350\257\267\350\276\223\345\205\245\347\256\241\347\220\206\345\221\230\345\257\206\351\222\245", 0));
        lineEdit->setPlaceholderText(QApplication::translate("keyConfirmation", "\350\257\267\350\276\223\345\205\245\345\257\206\351\222\245", 0));
        pushButton->setText(QApplication::translate("keyConfirmation", "\347\241\256\345\256\232", 0));
        pushButton_2->setText(QApplication::translate("keyConfirmation", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class keyConfirmation: public Ui_keyConfirmation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYCONFIRMATION_H
