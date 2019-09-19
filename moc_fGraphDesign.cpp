/****************************************************************************
** Meta object code from reading C++ file 'fGraphDesign.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fGraphDesign.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fGraphDesign.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fGraphDesign_t {
    QByteArrayData data[16];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fGraphDesign_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fGraphDesign_t qt_meta_stringdata_fGraphDesign = {
    {
QT_MOC_LITERAL(0, 0, 12), // "fGraphDesign"
QT_MOC_LITERAL(1, 13, 15), // "nodeContextMenu"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "QGVNode*"
QT_MOC_LITERAL(4, 39, 4), // "node"
QT_MOC_LITERAL(5, 44, 12), // "bNodoClicked"
QT_MOC_LITERAL(6, 57, 12), // "bArcoClicked"
QT_MOC_LITERAL(7, 70, 15), // "bCasualeClicked"
QT_MOC_LITERAL(8, 86, 10), // "bKPercorsi"
QT_MOC_LITERAL(9, 97, 8), // "bPulisci"
QT_MOC_LITERAL(10, 106, 10), // "bBenchmark"
QT_MOC_LITERAL(11, 117, 6), // "bAbout"
QT_MOC_LITERAL(12, 124, 4), // "bDot"
QT_MOC_LITERAL(13, 129, 7), // "bCentra"
QT_MOC_LITERAL(14, 137, 6), // "bSalva"
QT_MOC_LITERAL(15, 144, 7) // "bCarica"

    },
    "fGraphDesign\0nodeContextMenu\0\0QGVNode*\0"
    "node\0bNodoClicked\0bArcoClicked\0"
    "bCasualeClicked\0bKPercorsi\0bPulisci\0"
    "bBenchmark\0bAbout\0bDot\0bCentra\0bSalva\0"
    "bCarica"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fGraphDesign[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void fGraphDesign::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fGraphDesign *_t = static_cast<fGraphDesign *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nodeContextMenu((*reinterpret_cast< QGVNode*(*)>(_a[1]))); break;
        case 1: _t->bNodoClicked(); break;
        case 2: _t->bArcoClicked(); break;
        case 3: _t->bCasualeClicked(); break;
        case 4: _t->bKPercorsi(); break;
        case 5: _t->bPulisci(); break;
        case 6: _t->bBenchmark(); break;
        case 7: _t->bAbout(); break;
        case 8: _t->bDot(); break;
        case 9: _t->bCentra(); break;
        case 10: _t->bSalva(); break;
        case 11: _t->bCarica(); break;
        default: ;
        }
    }
}

const QMetaObject fGraphDesign::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_fGraphDesign.data,
      qt_meta_data_fGraphDesign,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fGraphDesign::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fGraphDesign::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fGraphDesign.stringdata0))
        return static_cast<void*>(const_cast< fGraphDesign*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int fGraphDesign::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
