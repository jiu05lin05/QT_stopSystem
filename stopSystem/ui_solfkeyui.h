/********************************************************************************
** Form generated from reading UI file 'solfkeyui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLFKEYUI_H
#define UI_SOLFKEYUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mybutton.h"

QT_BEGIN_NAMESPACE

class Ui_solfkeyui
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    mybutton *keyQ;
    mybutton *keyW;
    mybutton *keyE;
    mybutton *keyR;
    mybutton *keyT;
    mybutton *keyY;
    mybutton *keyU;
    mybutton *keyI;
    mybutton *keyO;
    mybutton *keyP;
    mybutton *keyBackspace;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    mybutton *key1;
    mybutton *key2;
    mybutton *key3;
    QHBoxLayout *horizontalLayout_5;
    mybutton *key4;
    mybutton *key5;
    mybutton *key6;
    QHBoxLayout *horizontalLayout_4;
    mybutton *key7;
    mybutton *key8;
    mybutton *key9;
    QHBoxLayout *horizontalLayout_8;
    mybutton *keyAt;
    mybutton *key0;
    mybutton *key0_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    mybutton *keyZ;
    mybutton *keyX;
    mybutton *keyC;
    mybutton *keyV;
    mybutton *keyB;
    mybutton *keyN;
    mybutton *keyM;
    QLabel *label_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_2;
    mybutton *keyA;
    mybutton *keyS;
    mybutton *keyD;
    mybutton *keyF;
    mybutton *keyG;
    mybutton *keyH;
    mybutton *keyJ;
    mybutton *keyK;
    mybutton *keyL;
    mybutton *keyEnter;

    void setupUi(QWidget *solfkeyui)
    {
        if (solfkeyui->objectName().isEmpty())
            solfkeyui->setObjectName(QStringLiteral("solfkeyui"));
        solfkeyui->resize(600, 160);
        solfkeyui->setMinimumSize(QSize(600, 160));
        solfkeyui->setMaximumSize(QSize(600, 150));
        solfkeyui->setStyleSheet(QLatin1String("mybutton{background-color: rgb(255, 189, 163);}\n"
"QWidget{background-color: rgb(145,76,107);}"));
        layoutWidget = new QWidget(solfkeyui);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 550, 150));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        keyQ = new mybutton(layoutWidget);
        keyQ->setObjectName(QStringLiteral("keyQ"));
        keyQ->setMinimumSize(QSize(30, 30));
        keyQ->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        keyQ->setFont(font);
        keyQ->setFocusPolicy(Qt::NoFocus);
        keyQ->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyQ);

        keyW = new mybutton(layoutWidget);
        keyW->setObjectName(QStringLiteral("keyW"));
        keyW->setMinimumSize(QSize(30, 30));
        keyW->setMaximumSize(QSize(30, 30));
        keyW->setFont(font);
        keyW->setFocusPolicy(Qt::NoFocus);
        keyW->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyW);

        keyE = new mybutton(layoutWidget);
        keyE->setObjectName(QStringLiteral("keyE"));
        keyE->setMinimumSize(QSize(30, 30));
        keyE->setMaximumSize(QSize(30, 30));
        keyE->setFont(font);
        keyE->setFocusPolicy(Qt::NoFocus);
        keyE->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyE);

        keyR = new mybutton(layoutWidget);
        keyR->setObjectName(QStringLiteral("keyR"));
        keyR->setMinimumSize(QSize(30, 30));
        keyR->setMaximumSize(QSize(30, 30));
        keyR->setFont(font);
        keyR->setFocusPolicy(Qt::NoFocus);
        keyR->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyR);

        keyT = new mybutton(layoutWidget);
        keyT->setObjectName(QStringLiteral("keyT"));
        keyT->setMinimumSize(QSize(30, 30));
        keyT->setMaximumSize(QSize(30, 30));
        keyT->setFont(font);
        keyT->setFocusPolicy(Qt::NoFocus);
        keyT->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyT);

        keyY = new mybutton(layoutWidget);
        keyY->setObjectName(QStringLiteral("keyY"));
        keyY->setMinimumSize(QSize(30, 30));
        keyY->setMaximumSize(QSize(30, 30));
        keyY->setFont(font);
        keyY->setFocusPolicy(Qt::NoFocus);
        keyY->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyY);

        keyU = new mybutton(layoutWidget);
        keyU->setObjectName(QStringLiteral("keyU"));
        keyU->setMinimumSize(QSize(30, 30));
        keyU->setMaximumSize(QSize(30, 30));
        keyU->setFont(font);
        keyU->setFocusPolicy(Qt::NoFocus);
        keyU->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyU);

        keyI = new mybutton(layoutWidget);
        keyI->setObjectName(QStringLiteral("keyI"));
        keyI->setMinimumSize(QSize(30, 30));
        keyI->setMaximumSize(QSize(30, 30));
        keyI->setFont(font);
        keyI->setFocusPolicy(Qt::NoFocus);
        keyI->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyI);

        keyO = new mybutton(layoutWidget);
        keyO->setObjectName(QStringLiteral("keyO"));
        keyO->setMinimumSize(QSize(30, 30));
        keyO->setMaximumSize(QSize(30, 30));
        keyO->setFont(font);
        keyO->setFocusPolicy(Qt::NoFocus);
        keyO->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyO);

        keyP = new mybutton(layoutWidget);
        keyP->setObjectName(QStringLiteral("keyP"));
        keyP->setMinimumSize(QSize(30, 30));
        keyP->setMaximumSize(QSize(30, 30));
        keyP->setFont(font);
        keyP->setFocusPolicy(Qt::NoFocus);
        keyP->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_3->addWidget(keyP);


        horizontalLayout_7->addLayout(horizontalLayout_3);

        keyBackspace = new mybutton(layoutWidget);
        keyBackspace->setObjectName(QStringLiteral("keyBackspace"));
        keyBackspace->setMinimumSize(QSize(30, 30));
        keyBackspace->setMaximumSize(QSize(30, 30));
        keyBackspace->setFont(font);
        keyBackspace->setFocusPolicy(Qt::NoFocus);
        keyBackspace->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_7->addWidget(keyBackspace);


        gridLayout->addLayout(horizontalLayout_7, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        key1 = new mybutton(layoutWidget);
        key1->setObjectName(QStringLiteral("key1"));
        key1->setMinimumSize(QSize(30, 30));
        key1->setMaximumSize(QSize(30, 30));
        key1->setFont(font);
        key1->setFocusPolicy(Qt::NoFocus);
        key1->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_6->addWidget(key1);

        key2 = new mybutton(layoutWidget);
        key2->setObjectName(QStringLiteral("key2"));
        key2->setMinimumSize(QSize(30, 30));
        key2->setMaximumSize(QSize(30, 30));
        key2->setFont(font);
        key2->setFocusPolicy(Qt::NoFocus);
        key2->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_6->addWidget(key2);

        key3 = new mybutton(layoutWidget);
        key3->setObjectName(QStringLiteral("key3"));
        key3->setMinimumSize(QSize(30, 30));
        key3->setMaximumSize(QSize(30, 30));
        key3->setFont(font);
        key3->setFocusPolicy(Qt::NoFocus);
        key3->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_6->addWidget(key3);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        key4 = new mybutton(layoutWidget);
        key4->setObjectName(QStringLiteral("key4"));
        key4->setMinimumSize(QSize(30, 30));
        key4->setMaximumSize(QSize(30, 30));
        key4->setFont(font);
        key4->setFocusPolicy(Qt::NoFocus);
        key4->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_5->addWidget(key4);

        key5 = new mybutton(layoutWidget);
        key5->setObjectName(QStringLiteral("key5"));
        key5->setMinimumSize(QSize(30, 30));
        key5->setMaximumSize(QSize(30, 30));
        key5->setFont(font);
        key5->setFocusPolicy(Qt::NoFocus);
        key5->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_5->addWidget(key5);

        key6 = new mybutton(layoutWidget);
        key6->setObjectName(QStringLiteral("key6"));
        key6->setMinimumSize(QSize(30, 30));
        key6->setMaximumSize(QSize(30, 30));
        key6->setFont(font);
        key6->setFocusPolicy(Qt::NoFocus);
        key6->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_5->addWidget(key6);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        key7 = new mybutton(layoutWidget);
        key7->setObjectName(QStringLiteral("key7"));
        key7->setMinimumSize(QSize(30, 30));
        key7->setMaximumSize(QSize(30, 30));
        key7->setFont(font);
        key7->setFocusPolicy(Qt::NoFocus);
        key7->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_4->addWidget(key7);

        key8 = new mybutton(layoutWidget);
        key8->setObjectName(QStringLiteral("key8"));
        key8->setMinimumSize(QSize(30, 30));
        key8->setMaximumSize(QSize(30, 30));
        key8->setFont(font);
        key8->setFocusPolicy(Qt::NoFocus);
        key8->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_4->addWidget(key8);

        key9 = new mybutton(layoutWidget);
        key9->setObjectName(QStringLiteral("key9"));
        key9->setMinimumSize(QSize(30, 30));
        key9->setMaximumSize(QSize(30, 30));
        key9->setFont(font);
        key9->setFocusPolicy(Qt::NoFocus);
        key9->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_4->addWidget(key9);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        keyAt = new mybutton(layoutWidget);
        keyAt->setObjectName(QStringLiteral("keyAt"));
        keyAt->setMinimumSize(QSize(30, 30));
        keyAt->setMaximumSize(QSize(30, 30));
        keyAt->setFont(font);
        keyAt->setFocusPolicy(Qt::NoFocus);
        keyAt->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_8->addWidget(keyAt);

        key0 = new mybutton(layoutWidget);
        key0->setObjectName(QStringLiteral("key0"));
        key0->setMinimumSize(QSize(30, 30));
        key0->setMaximumSize(QSize(30, 30));
        key0->setFont(font);
        key0->setFocusPolicy(Qt::NoFocus);
        key0->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_8->addWidget(key0);

        key0_2 = new mybutton(layoutWidget);
        key0_2->setObjectName(QStringLiteral("key0_2"));
        key0_2->setMinimumSize(QSize(30, 30));
        key0_2->setMaximumSize(QSize(30, 30));
        key0_2->setFont(font);
        key0_2->setFocusPolicy(Qt::NoFocus);
        key0_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_8->addWidget(key0_2);


        verticalLayout->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout, 0, 0, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(15, 30));
        label_5->setMaximumSize(QSize(15, 30));

        horizontalLayout->addWidget(label_5);

        keyZ = new mybutton(layoutWidget);
        keyZ->setObjectName(QStringLiteral("keyZ"));
        keyZ->setMinimumSize(QSize(30, 30));
        keyZ->setMaximumSize(QSize(30, 30));
        keyZ->setFont(font);
        keyZ->setFocusPolicy(Qt::NoFocus);
        keyZ->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout->addWidget(keyZ);

        keyX = new mybutton(layoutWidget);
        keyX->setObjectName(QStringLiteral("keyX"));
        keyX->setMinimumSize(QSize(30, 30));
        keyX->setMaximumSize(QSize(30, 30));
        keyX->setFont(font);
        keyX->setFocusPolicy(Qt::NoFocus);
        keyX->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout->addWidget(keyX);

        keyC = new mybutton(layoutWidget);
        keyC->setObjectName(QStringLiteral("keyC"));
        keyC->setMinimumSize(QSize(30, 30));
        keyC->setMaximumSize(QSize(30, 30));
        keyC->setFont(font);
        keyC->setFocusPolicy(Qt::NoFocus);
        keyC->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout->addWidget(keyC);

        keyV = new mybutton(layoutWidget);
        keyV->setObjectName(QStringLiteral("keyV"));
        keyV->setMinimumSize(QSize(30, 30));
        keyV->setMaximumSize(QSize(30, 30));
        keyV->setFont(font);
        keyV->setFocusPolicy(Qt::NoFocus);
        keyV->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout->addWidget(keyV);

        keyB = new mybutton(layoutWidget);
        keyB->setObjectName(QStringLiteral("keyB"));
        keyB->setMinimumSize(QSize(30, 30));
        keyB->setMaximumSize(QSize(30, 30));
        keyB->setFont(font);
        keyB->setFocusPolicy(Qt::NoFocus);
        keyB->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout->addWidget(keyB);

        keyN = new mybutton(layoutWidget);
        keyN->setObjectName(QStringLiteral("keyN"));
        keyN->setMinimumSize(QSize(30, 30));
        keyN->setMaximumSize(QSize(30, 30));
        keyN->setFont(font);
        keyN->setFocusPolicy(Qt::NoFocus);
        keyN->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout->addWidget(keyN);

        keyM = new mybutton(layoutWidget);
        keyM->setObjectName(QStringLiteral("keyM"));
        keyM->setMinimumSize(QSize(30, 30));
        keyM->setMaximumSize(QSize(30, 30));
        keyM->setFont(font);
        keyM->setFocusPolicy(Qt::NoFocus);
        keyM->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout->addWidget(keyM);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(30, 30));
        label_4->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(label_4);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(30, 30));
        label_3->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        keyA = new mybutton(layoutWidget);
        keyA->setObjectName(QStringLiteral("keyA"));
        keyA->setMinimumSize(QSize(30, 30));
        keyA->setMaximumSize(QSize(30, 30));
        keyA->setFont(font);
        keyA->setFocusPolicy(Qt::NoFocus);
        keyA->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyA);

        keyS = new mybutton(layoutWidget);
        keyS->setObjectName(QStringLiteral("keyS"));
        keyS->setMinimumSize(QSize(30, 30));
        keyS->setMaximumSize(QSize(30, 30));
        keyS->setFont(font);
        keyS->setFocusPolicy(Qt::NoFocus);
        keyS->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyS);

        keyD = new mybutton(layoutWidget);
        keyD->setObjectName(QStringLiteral("keyD"));
        keyD->setMinimumSize(QSize(30, 30));
        keyD->setMaximumSize(QSize(30, 30));
        keyD->setFont(font);
        keyD->setFocusPolicy(Qt::NoFocus);
        keyD->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyD);

        keyF = new mybutton(layoutWidget);
        keyF->setObjectName(QStringLiteral("keyF"));
        keyF->setMinimumSize(QSize(30, 30));
        keyF->setMaximumSize(QSize(30, 30));
        keyF->setFont(font);
        keyF->setFocusPolicy(Qt::NoFocus);
        keyF->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyF);

        keyG = new mybutton(layoutWidget);
        keyG->setObjectName(QStringLiteral("keyG"));
        keyG->setMinimumSize(QSize(30, 30));
        keyG->setMaximumSize(QSize(30, 30));
        keyG->setFont(font);
        keyG->setFocusPolicy(Qt::NoFocus);
        keyG->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyG);

        keyH = new mybutton(layoutWidget);
        keyH->setObjectName(QStringLiteral("keyH"));
        keyH->setMinimumSize(QSize(30, 30));
        keyH->setMaximumSize(QSize(30, 30));
        keyH->setFont(font);
        keyH->setFocusPolicy(Qt::NoFocus);
        keyH->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyH);

        keyJ = new mybutton(layoutWidget);
        keyJ->setObjectName(QStringLiteral("keyJ"));
        keyJ->setMinimumSize(QSize(30, 30));
        keyJ->setMaximumSize(QSize(30, 30));
        keyJ->setFont(font);
        keyJ->setFocusPolicy(Qt::NoFocus);
        keyJ->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyJ);

        keyK = new mybutton(layoutWidget);
        keyK->setObjectName(QStringLiteral("keyK"));
        keyK->setMinimumSize(QSize(30, 30));
        keyK->setMaximumSize(QSize(30, 30));
        keyK->setFont(font);
        keyK->setFocusPolicy(Qt::NoFocus);
        keyK->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyK);

        keyL = new mybutton(layoutWidget);
        keyL->setObjectName(QStringLiteral("keyL"));
        keyL->setMinimumSize(QSize(30, 30));
        keyL->setMaximumSize(QSize(30, 30));
        keyL->setFont(font);
        keyL->setFocusPolicy(Qt::NoFocus);
        keyL->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_2->addWidget(keyL);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        keyEnter = new mybutton(layoutWidget);
        keyEnter->setObjectName(QStringLiteral("keyEnter"));
        keyEnter->setMinimumSize(QSize(60, 30));
        keyEnter->setMaximumSize(QSize(60, 30));
        keyEnter->setFont(font);
        keyEnter->setFocusPolicy(Qt::NoFocus);
        keyEnter->setStyleSheet(QStringLiteral("background-color: rgb(255, 189, 163);"));

        horizontalLayout_9->addWidget(keyEnter);


        gridLayout->addLayout(horizontalLayout_9, 1, 1, 1, 1);


        retranslateUi(solfkeyui);

        QMetaObject::connectSlotsByName(solfkeyui);
    } // setupUi

    void retranslateUi(QWidget *solfkeyui)
    {
        solfkeyui->setWindowTitle(QApplication::translate("solfkeyui", "Form", 0));
        keyQ->setText(QApplication::translate("solfkeyui", "q", 0));
        keyW->setText(QApplication::translate("solfkeyui", "w", 0));
        keyE->setText(QApplication::translate("solfkeyui", "e", 0));
        keyR->setText(QApplication::translate("solfkeyui", "r", 0));
        keyT->setText(QApplication::translate("solfkeyui", "t", 0));
        keyY->setText(QApplication::translate("solfkeyui", "y", 0));
        keyU->setText(QApplication::translate("solfkeyui", "u", 0));
        keyI->setText(QApplication::translate("solfkeyui", "i", 0));
        keyO->setText(QApplication::translate("solfkeyui", "o", 0));
        keyP->setText(QApplication::translate("solfkeyui", "p", 0));
        keyBackspace->setText(QApplication::translate("solfkeyui", "\342\206\220", 0));
        key1->setText(QApplication::translate("solfkeyui", "1", 0));
        key2->setText(QApplication::translate("solfkeyui", "2", 0));
        key3->setText(QApplication::translate("solfkeyui", "3", 0));
        key4->setText(QApplication::translate("solfkeyui", "4", 0));
        key5->setText(QApplication::translate("solfkeyui", "5", 0));
        key6->setText(QApplication::translate("solfkeyui", "6", 0));
        key7->setText(QApplication::translate("solfkeyui", "7", 0));
        key8->setText(QApplication::translate("solfkeyui", "8", 0));
        key9->setText(QApplication::translate("solfkeyui", "9", 0));
        keyAt->setText(QApplication::translate("solfkeyui", "@", 0));
        key0->setText(QApplication::translate("solfkeyui", "0", 0));
        key0_2->setText(QApplication::translate("solfkeyui", ".", 0));
        label_5->setText(QString());
        keyZ->setText(QApplication::translate("solfkeyui", "z", 0));
        keyX->setText(QApplication::translate("solfkeyui", "x", 0));
        keyC->setText(QApplication::translate("solfkeyui", "c", 0));
        keyV->setText(QApplication::translate("solfkeyui", "v", 0));
        keyB->setText(QApplication::translate("solfkeyui", "b", 0));
        keyN->setText(QApplication::translate("solfkeyui", "n", 0));
        keyM->setText(QApplication::translate("solfkeyui", "m", 0));
        label_4->setText(QString());
        label_3->setText(QString());
        keyA->setText(QApplication::translate("solfkeyui", "a", 0));
        keyS->setText(QApplication::translate("solfkeyui", "s", 0));
        keyD->setText(QApplication::translate("solfkeyui", "d", 0));
        keyF->setText(QApplication::translate("solfkeyui", "f", 0));
        keyG->setText(QApplication::translate("solfkeyui", "g", 0));
        keyH->setText(QApplication::translate("solfkeyui", "h", 0));
        keyJ->setText(QApplication::translate("solfkeyui", "j", 0));
        keyK->setText(QApplication::translate("solfkeyui", "k", 0));
        keyL->setText(QApplication::translate("solfkeyui", "l", 0));
        keyEnter->setText(QApplication::translate("solfkeyui", "Enter", 0));
    } // retranslateUi

};

namespace Ui {
    class solfkeyui: public Ui_solfkeyui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLFKEYUI_H
