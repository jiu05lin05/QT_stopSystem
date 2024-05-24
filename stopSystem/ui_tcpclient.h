/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_TCPclient
{
public:

    void setupUi(QDialog *TCPclient)
    {
        if (TCPclient->objectName().isEmpty())
            TCPclient->setObjectName(QStringLiteral("TCPclient"));
        TCPclient->resize(400, 300);

        retranslateUi(TCPclient);

        QMetaObject::connectSlotsByName(TCPclient);
    } // setupUi

    void retranslateUi(QDialog *TCPclient)
    {
        TCPclient->setWindowTitle(QApplication::translate("TCPclient", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class TCPclient: public Ui_TCPclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
