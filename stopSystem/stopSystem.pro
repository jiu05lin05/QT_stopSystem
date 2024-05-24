QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admininterface.cpp \
    captchalogin.cpp \
    keyconfirmation.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    mycamera.cpp \
    registrationwindow.cpp \
    rfid.cpp \
    solfkeyui.cpp \
    tcpclient.cpp

HEADERS += \
    admininterface.h \
    captchalogin.h \
    keyconfirmation.h \
    loginwindow.h \
    mainwindow.h \
    mybutton.h \
    mycamera.h \
    registrationwindow.h \
    rfid.h \
    solfkeyui.h \
    tcpclient.h

FORMS += \
    admininterface.ui \
    captchalogin.ui \
    keyconfirmation.ui \
    loginwindow.ui \
    mainwindow.ui \
    registrationwindow.ui \
    solfkeyui.ui \
    tcpclient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
