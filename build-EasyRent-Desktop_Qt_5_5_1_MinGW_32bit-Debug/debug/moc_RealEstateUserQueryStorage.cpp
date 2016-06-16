/****************************************************************************
** Meta object code from reading C++ file 'RealEstateUserQueryStorage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/RealEstateUserQueryStorage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RealEstateUserQueryStorage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RealEstateUserQueryStorage_t {
    QByteArrayData data[11];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RealEstateUserQueryStorage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RealEstateUserQueryStorage_t qt_meta_stringdata_RealEstateUserQueryStorage = {
    {
QT_MOC_LITERAL(0, 0, 26), // "RealEstateUserQueryStorage"
QT_MOC_LITERAL(1, 27, 4), // "save"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 21), // "RealEstateQuery*const"
QT_MOC_LITERAL(4, 55, 5), // "query"
QT_MOC_LITERAL(5, 61, 23), // "QList<RealEstateQuery*>"
QT_MOC_LITERAL(6, 85, 7), // "queries"
QT_MOC_LITERAL(7, 93, 4), // "load"
QT_MOC_LITERAL(8, 98, 16), // "RealEstateQuery*"
QT_MOC_LITERAL(9, 115, 7), // "queryID"
QT_MOC_LITERAL(10, 123, 7) // "loadAll"

    },
    "RealEstateUserQueryStorage\0save\0\0"
    "RealEstateQuery*const\0query\0"
    "QList<RealEstateQuery*>\0queries\0load\0"
    "RealEstateQuery*\0queryID\0loadAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RealEstateUserQueryStorage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       1,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x0a /* Public */,
      10,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5,    6,
    0x80000000 | 8, QMetaType::Int,    9,
    0x80000000 | 5,

       0        // eod
};

void RealEstateUserQueryStorage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RealEstateUserQueryStorage *_t = static_cast<RealEstateUserQueryStorage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->save((*reinterpret_cast< const RealEstateQuery*const(*)>(_a[1]))); break;
        case 1: _t->save((*reinterpret_cast< const QList<RealEstateQuery*>(*)>(_a[1]))); break;
        case 2: { RealEstateQuery* _r = _t->load((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< RealEstateQuery**>(_a[0]) = _r; }  break;
        case 3: { QList<RealEstateQuery*> _r = _t->loadAll();
            if (_a[0]) *reinterpret_cast< QList<RealEstateQuery*>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<RealEstateQuery*> >(); break;
            }
            break;
        }
    }
}

const QMetaObject RealEstateUserQueryStorage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RealEstateUserQueryStorage.data,
      qt_meta_data_RealEstateUserQueryStorage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RealEstateUserQueryStorage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RealEstateUserQueryStorage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RealEstateUserQueryStorage.stringdata0))
        return static_cast<void*>(const_cast< RealEstateUserQueryStorage*>(this));
    return QObject::qt_metacast(_clname);
}

int RealEstateUserQueryStorage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
