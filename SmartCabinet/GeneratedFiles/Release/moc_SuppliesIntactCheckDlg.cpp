/****************************************************************************
** Meta object code from reading C++ file 'SuppliesIntactCheckDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SuppliesIntactCheckDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SuppliesIntactCheckDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SuppliesIntactCheckDlg_t {
    QByteArrayData data[10];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SuppliesIntactCheckDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SuppliesIntactCheckDlg_t qt_meta_stringdata_SuppliesIntactCheckDlg = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SuppliesIntactCheckDlg"
QT_MOC_LITERAL(1, 23, 25), // "suppliesIntactCheckSignal"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 10), // "IntactType"
QT_MOC_LITERAL(4, 61, 20), // "suppliesIntactStatus"
QT_MOC_LITERAL(5, 82, 10), // "onCanClick"
QT_MOC_LITERAL(6, 93, 10), // "onBtnClose"
QT_MOC_LITERAL(7, 104, 21), // "onButtonNormalClicked"
QT_MOC_LITERAL(8, 126, 22), // "onButtonMissingClicked"
QT_MOC_LITERAL(9, 149, 18) // "onButtonBadClicked"

    },
    "SuppliesIntactCheckDlg\0suppliesIntactCheckSignal\0"
    "\0IntactType\0suppliesIntactStatus\0"
    "onCanClick\0onBtnClose\0onButtonNormalClicked\0"
    "onButtonMissingClicked\0onButtonBadClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SuppliesIntactCheckDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SuppliesIntactCheckDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SuppliesIntactCheckDlg *_t = static_cast<SuppliesIntactCheckDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->suppliesIntactCheckSignal((*reinterpret_cast< IntactType(*)>(_a[1]))); break;
        case 1: _t->onCanClick(); break;
        case 2: _t->onBtnClose(); break;
        case 3: _t->onButtonNormalClicked(); break;
        case 4: _t->onButtonMissingClicked(); break;
        case 5: _t->onButtonBadClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SuppliesIntactCheckDlg::*_t)(IntactType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SuppliesIntactCheckDlg::suppliesIntactCheckSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SuppliesIntactCheckDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SuppliesIntactCheckDlg.data,
      qt_meta_data_SuppliesIntactCheckDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SuppliesIntactCheckDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SuppliesIntactCheckDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SuppliesIntactCheckDlg.stringdata0))
        return static_cast<void*>(const_cast< SuppliesIntactCheckDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int SuppliesIntactCheckDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SuppliesIntactCheckDlg::suppliesIntactCheckSignal(IntactType _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
