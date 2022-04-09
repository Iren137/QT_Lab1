/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../main_window.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[42];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 10), // "ResetCards"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 6), // "amount"
QT_MOC_LITERAL(30, 22), // "TryUpdateAmountOfCards"
QT_MOC_LITERAL(53, 11), // "CardClicked"
QT_MOC_LITERAL(65, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(82, 19), // "ProcessDialogAnswer"
QT_MOC_LITERAL(102, 16), // "QAbstractButton*"
QT_MOC_LITERAL(119, 13), // "TryChangeName"
QT_MOC_LITERAL(133, 23), // "TryChangeStatusOfOpened"
QT_MOC_LITERAL(157, 10), // "PickRandom"
QT_MOC_LITERAL(168, 17), // "CardDoubleClicked"
QT_MOC_LITERAL(186, 15), // "TryShowQuestion"
QT_MOC_LITERAL(202, 12), // "ChangeStatus"
QT_MOC_LITERAL(215, 1), // "i"
QT_MOC_LITERAL(217, 6), // "Status"
QT_MOC_LITERAL(224, 10), // "new_status"
QT_MOC_LITERAL(235, 20), // "SetColorForNewActive"
QT_MOC_LITERAL(256, 19), // "DisableHighlighting"
QT_MOC_LITERAL(276, 16) // "ShowPreviousCard"

    },
    "MainWindow\0ResetCards\0\0amount\0"
    "TryUpdateAmountOfCards\0CardClicked\0"
    "QListWidgetItem*\0ProcessDialogAnswer\0"
    "QAbstractButton*\0TryChangeName\0"
    "TryChangeStatusOfOpened\0PickRandom\0"
    "CardDoubleClicked\0TryShowQuestion\0"
    "ChangeStatus\0i\0Status\0new_status\0"
    "SetColorForNewActive\0DisableHighlighting\0"
    "ShowPreviousCard"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x0a,    1 /* Public */,
       4,    0,   95,    2, 0x0a,    3 /* Public */,
       5,    1,   96,    2, 0x0a,    4 /* Public */,
       7,    1,   99,    2, 0x0a,    6 /* Public */,
       9,    0,  102,    2, 0x0a,    8 /* Public */,
      10,    1,  103,    2, 0x0a,    9 /* Public */,
      11,    0,  106,    2, 0x0a,   11 /* Public */,
      12,    1,  107,    2, 0x0a,   12 /* Public */,
      13,    1,  110,    2, 0x0a,   14 /* Public */,
      14,    2,  113,    2, 0x0a,   16 /* Public */,
      18,    1,  118,    2, 0x0a,   19 /* Public */,
      19,    1,  121,    2, 0x0a,   21 /* Public */,
      20,    0,  124,    2, 0x0a,   23 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 16,   15,   17,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ResetCards((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->TryUpdateAmountOfCards(); break;
        case 2: _t->CardClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->ProcessDialogAnswer((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 4: _t->TryChangeName(); break;
        case 5: _t->TryChangeStatusOfOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->PickRandom(); break;
        case 7: _t->CardDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->TryShowQuestion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ChangeStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Status(*)>(_a[2]))); break;
        case 10: _t->SetColorForNewActive((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->DisableHighlighting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->ShowPreviousCard(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Status, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
