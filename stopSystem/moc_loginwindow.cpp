/****************************************************************************
** Meta object code from reading C++ file 'loginwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "loginwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_loginWindow_t {
    QByteArrayData data[7];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_loginWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_loginWindow_t qt_meta_stringdata_loginWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "loginWindow"
QT_MOC_LITERAL(1, 12, 20), // "on_eyeButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 22), // "on_loginButton_clicked"
QT_MOC_LITERAL(4, 57, 20), // "on_regButton_clicked"
QT_MOC_LITERAL(5, 78, 3), // "fun"
QT_MOC_LITERAL(6, 82, 18) // "on_captCha_clicked"

    },
    "loginWindow\0on_eyeButton_clicked\0\0"
    "on_loginButton_clicked\0on_regButton_clicked\0"
    "fun\0on_captCha_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loginWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void loginWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        loginWindow *_t = static_cast<loginWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_eyeButton_clicked(); break;
        case 1: _t->on_loginButton_clicked(); break;
        case 2: _t->on_regButton_clicked(); break;
        case 3: _t->fun(); break;
        case 4: _t->on_captCha_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject loginWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_loginWindow.data,
      qt_meta_data_loginWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *loginWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loginWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_loginWindow.stringdata0))
        return static_cast<void*>(const_cast< loginWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int loginWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
