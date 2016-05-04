/****************************************************************************
** Meta object code from reading C++ file 'DlgUserQueryEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/DlgUserQueryEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DlgUserQueryEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DlgUserQueryEditor_t {
    QByteArrayData data[12];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DlgUserQueryEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DlgUserQueryEditor_t qt_meta_stringdata_DlgUserQueryEditor = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DlgUserQueryEditor"
QT_MOC_LITERAL(1, 19, 5), // "saved"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "cancelled"
QT_MOC_LITERAL(4, 36, 19), // "loadQueryDataFromUI"
QT_MOC_LITERAL(5, 56, 21), // "updateLastFloorLimits"
QT_MOC_LITERAL(6, 78, 12), // "setEditQuery"
QT_MOC_LITERAL(7, 91, 16), // "RealEstateQuery*"
QT_MOC_LITERAL(8, 108, 5), // "value"
QT_MOC_LITERAL(9, 114, 11), // "refreshInfo"
QT_MOC_LITERAL(10, 126, 4), // "save"
QT_MOC_LITERAL(11, 131, 6) // "cancel"

    },
    "DlgUserQueryEditor\0saved\0\0cancelled\0"
    "loadQueryDataFromUI\0updateLastFloorLimits\0"
    "setEditQuery\0RealEstateQuery*\0value\0"
    "refreshInfo\0save\0cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DlgUserQueryEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,
      10,    0,   62,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DlgUserQueryEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DlgUserQueryEditor *_t = static_cast<DlgUserQueryEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saved(); break;
        case 1: _t->cancelled(); break;
        case 2: _t->loadQueryDataFromUI(); break;
        case 3: _t->updateLastFloorLimits(); break;
        case 4: _t->setEditQuery((*reinterpret_cast< RealEstateQuery*(*)>(_a[1]))); break;
        case 5: _t->refreshInfo(); break;
        case 6: _t->save(); break;
        case 7: _t->cancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RealEstateQuery* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DlgUserQueryEditor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DlgUserQueryEditor::saved)) {
                *result = 0;
            }
        }
        {
            typedef void (DlgUserQueryEditor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DlgUserQueryEditor::cancelled)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DlgUserQueryEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DlgUserQueryEditor.data,
      qt_meta_data_DlgUserQueryEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DlgUserQueryEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DlgUserQueryEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DlgUserQueryEditor.stringdata0))
        return static_cast<void*>(const_cast< DlgUserQueryEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int DlgUserQueryEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DlgUserQueryEditor::saved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DlgUserQueryEditor::cancelled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
