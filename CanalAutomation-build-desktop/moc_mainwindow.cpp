/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Jan 3 17:48:43 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CanalAutomation/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
     114,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     192,   11,   11,   11, 0x08,
     212,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_Exit_pushButton_clicked()\0"
    "on_Next_pushButton_clicked()\0"
    "on_accept_clicked()\0on_cancel_clicked()\0"
    "on_ok_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_2_clicked(); break;
        case 1: on_pushButton_3_clicked(); break;
        case 2: on_pushButton_4_clicked(); break;
        case 3: on_pushButton_clicked(); break;
        case 4: on_Exit_pushButton_clicked(); break;
        case 5: on_Next_pushButton_clicked(); break;
        case 6: on_accept_clicked(); break;
        case 7: on_cancel_clicked(); break;
        case 8: on_ok_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
