/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *next;
    QLabel *date;
    QPushButton *previous;
    QLabel *weather;
    QLabel *weatherInfo;
    QLabel *time;
    QWidget *W2;
    QPushButton *B1;
    QPushButton *B2;
    QPushButton *B3;
    QPushButton *B5;
    QPushButton *B4;
    QWidget *W1;
    QPushButton *A1;
    QPushButton *A2;
    QPushButton *A3;
    QPushButton *A5;
    QPushButton *A4;
    QWidget *W3;
    QPushButton *C1;
    QPushButton *C2;
    QPushButton *C3;
    QPushButton *C5;
    QPushButton *C4;
    QLabel *residual;
    QPushButton *previous_2;
    QLCDNumber *timeInfo;
    QLCDNumber *dateInfo;
    QLCDNumber *residualInfo;
    QLabel *pic;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setStyleSheet(QStringLiteral("QMainWindow{border-image: url(:/new/prefix1/pic/city.jpg);}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        next = new QPushButton(centralwidget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(680, 220, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        next->setFont(font);
        date = new QLabel(centralwidget);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(20, 20, 61, 41));
        date->setFont(font);
        previous = new QPushButton(centralwidget);
        previous->setObjectName(QStringLiteral("previous"));
        previous->setGeometry(QRect(10, 220, 101, 41));
        previous->setFont(font);
        weather = new QLabel(centralwidget);
        weather->setObjectName(QStringLiteral("weather"));
        weather->setGeometry(QRect(20, 70, 61, 41));
        weather->setFont(font);
        weatherInfo = new QLabel(centralwidget);
        weatherInfo->setObjectName(QStringLiteral("weatherInfo"));
        weatherInfo->setGeometry(QRect(90, 70, 81, 41));
        weatherInfo->setFont(font);
        time = new QLabel(centralwidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(20, 120, 61, 41));
        time->setFont(font);
        W2 = new QWidget(centralwidget);
        W2->setObjectName(QStringLiteral("W2"));
        W2->setGeometry(QRect(10, 270, 781, 201));
        W2->setFont(font);
        W2->setStyleSheet(QStringLiteral(""));
        B1 = new QPushButton(W2);
        B1->setObjectName(QStringLiteral("B1"));
        B1->setGeometry(QRect(41, 18, 93, 171));
        B1->setFont(font);
        B1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        B2 = new QPushButton(W2);
        B2->setObjectName(QStringLiteral("B2"));
        B2->setGeometry(QRect(180, 18, 93, 171));
        B2->setFont(font);
        B2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        B3 = new QPushButton(W2);
        B3->setObjectName(QStringLiteral("B3"));
        B3->setGeometry(QRect(319, 18, 93, 171));
        B3->setFont(font);
        B3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        B5 = new QPushButton(W2);
        B5->setObjectName(QStringLiteral("B5"));
        B5->setGeometry(QRect(597, 21, 93, 171));
        B5->setFont(font);
        B5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        B4 = new QPushButton(W2);
        B4->setObjectName(QStringLiteral("B4"));
        B4->setGeometry(QRect(458, 21, 93, 171));
        B4->setFont(font);
        B4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        W1 = new QWidget(centralwidget);
        W1->setObjectName(QStringLiteral("W1"));
        W1->setGeometry(QRect(10, 270, 781, 201));
        W1->setFont(font);
        W1->setStyleSheet(QStringLiteral(""));
        A1 = new QPushButton(W1);
        A1->setObjectName(QStringLiteral("A1"));
        A1->setGeometry(QRect(41, 18, 93, 171));
        A1->setFont(font);
        A1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        A2 = new QPushButton(W1);
        A2->setObjectName(QStringLiteral("A2"));
        A2->setGeometry(QRect(180, 18, 93, 171));
        A2->setFont(font);
        A2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        A3 = new QPushButton(W1);
        A3->setObjectName(QStringLiteral("A3"));
        A3->setGeometry(QRect(319, 18, 93, 171));
        A3->setFont(font);
        A3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        A5 = new QPushButton(W1);
        A5->setObjectName(QStringLiteral("A5"));
        A5->setGeometry(QRect(597, 21, 93, 171));
        A5->setFont(font);
        A5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        A4 = new QPushButton(W1);
        A4->setObjectName(QStringLiteral("A4"));
        A4->setGeometry(QRect(458, 21, 93, 171));
        A4->setFont(font);
        A4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        W3 = new QWidget(centralwidget);
        W3->setObjectName(QStringLiteral("W3"));
        W3->setGeometry(QRect(10, 270, 781, 201));
        W3->setFont(font);
        W3->setStyleSheet(QStringLiteral(""));
        C1 = new QPushButton(W3);
        C1->setObjectName(QStringLiteral("C1"));
        C1->setGeometry(QRect(41, 18, 93, 171));
        C1->setFont(font);
        C1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        C2 = new QPushButton(W3);
        C2->setObjectName(QStringLiteral("C2"));
        C2->setGeometry(QRect(180, 18, 93, 171));
        C2->setFont(font);
        C2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        C3 = new QPushButton(W3);
        C3->setObjectName(QStringLiteral("C3"));
        C3->setGeometry(QRect(319, 18, 93, 171));
        C3->setFont(font);
        C3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        C5 = new QPushButton(W3);
        C5->setObjectName(QStringLiteral("C5"));
        C5->setGeometry(QRect(597, 21, 93, 171));
        C5->setFont(font);
        C5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        C4 = new QPushButton(W3);
        C4->setObjectName(QStringLiteral("C4"));
        C4->setGeometry(QRect(458, 21, 93, 171));
        C4->setFont(font);
        C4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        residual = new QLabel(centralwidget);
        residual->setObjectName(QStringLiteral("residual"));
        residual->setGeometry(QRect(340, 20, 111, 41));
        residual->setFont(font);
        previous_2 = new QPushButton(centralwidget);
        previous_2->setObjectName(QStringLiteral("previous_2"));
        previous_2->setGeometry(QRect(10, 170, 101, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        previous_2->setFont(font1);
        timeInfo = new QLCDNumber(centralwidget);
        timeInfo->setObjectName(QStringLiteral("timeInfo"));
        timeInfo->setGeometry(QRect(90, 130, 151, 23));
        timeInfo->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 255);"));
        timeInfo->setDigitCount(10);
        dateInfo = new QLCDNumber(centralwidget);
        dateInfo->setObjectName(QStringLiteral("dateInfo"));
        dateInfo->setGeometry(QRect(90, 30, 151, 21));
        dateInfo->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 255);"));
        dateInfo->setDigitCount(10);
        residualInfo = new QLCDNumber(centralwidget);
        residualInfo->setObjectName(QStringLiteral("residualInfo"));
        residualInfo->setGeometry(QRect(460, 30, 71, 23));
        residualInfo->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 255);"));
        pic = new QLabel(centralwidget);
        pic->setObjectName(QStringLiteral("pic"));
        pic->setGeometry(QRect(330, 110, 160, 120));
        pic->setMinimumSize(QSize(160, 120));
        pic->setMaximumSize(QSize(160, 120));
        MainWindow->setCentralWidget(centralwidget);
        W3->raise();
        W2->raise();
        W1->raise();
        next->raise();
        date->raise();
        previous->raise();
        weather->raise();
        weatherInfo->raise();
        time->raise();
        residual->raise();
        previous_2->raise();
        timeInfo->raise();
        dateInfo->raise();
        residualInfo->raise();
        pic->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        next->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", 0));
        date->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237:", 0));
        previous->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", 0));
        weather->setText(QApplication::translate("MainWindow", "\345\244\251\346\260\224:", 0));
        weatherInfo->setText(QApplication::translate("MainWindow", "\346\232\264\351\233\250", 0));
        time->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264:", 0));
        B1->setText(QApplication::translate("MainWindow", "B1", 0));
        B2->setText(QApplication::translate("MainWindow", "B2", 0));
        B3->setText(QApplication::translate("MainWindow", "B3", 0));
        B5->setText(QApplication::translate("MainWindow", "B5", 0));
        B4->setText(QApplication::translate("MainWindow", "B4", 0));
        A1->setText(QApplication::translate("MainWindow", "A1", 0));
        A2->setText(QApplication::translate("MainWindow", "A2", 0));
        A3->setText(QApplication::translate("MainWindow", "A3", 0));
        A5->setText(QApplication::translate("MainWindow", "A5", 0));
        A4->setText(QApplication::translate("MainWindow", "A4", 0));
        C1->setText(QApplication::translate("MainWindow", "C1", 0));
        C2->setText(QApplication::translate("MainWindow", "C2", 0));
        C3->setText(QApplication::translate("MainWindow", "C3", 0));
        C5->setText(QApplication::translate("MainWindow", "C5", 0));
        C4->setText(QApplication::translate("MainWindow", "C4", 0));
        residual->setText(QApplication::translate("MainWindow", "\345\211\251\344\275\231\350\275\246\344\275\215:", 0));
        previous_2->setText(QApplication::translate("MainWindow", "\346\210\221\346\230\257\347\256\241\347\220\206\345\221\230", 0));
        pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
