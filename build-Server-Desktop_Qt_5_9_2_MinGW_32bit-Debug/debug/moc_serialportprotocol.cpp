/****************************************************************************
** Meta object code from reading C++ file 'serialportprotocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/SerialPort/serialportprotocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportprotocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortProtocol_t {
    QByteArrayData data[9];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortProtocol_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortProtocol_t qt_meta_stringdata_SerialPortProtocol = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SerialPortProtocol"
QT_MOC_LITERAL(1, 19, 18), // "transferDeviceData"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 8), // "DataInfo"
QT_MOC_LITERAL(4, 48, 11), // "receiveData"
QT_MOC_LITERAL(5, 60, 21), // "receiveDeviceDataSlot"
QT_MOC_LITERAL(6, 82, 4), // "data"
QT_MOC_LITERAL(7, 87, 21), // "receiveDatafromSocket"
QT_MOC_LITERAL(8, 109, 4) // "info"

    },
    "SerialPortProtocol\0transferDeviceData\0"
    "\0DataInfo\0receiveData\0receiveDeviceDataSlot\0"
    "data\0receiveDatafromSocket\0info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortProtocol[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   32,    2, 0x0a /* Public */,
       7,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, 0x80000000 | 3,    8,

       0        // eod
};

void SerialPortProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortProtocol *_t = static_cast<SerialPortProtocol *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->transferDeviceData((*reinterpret_cast< DataInfo(*)>(_a[1]))); break;
        case 1: _t->receiveDeviceDataSlot((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->receiveDatafromSocket((*reinterpret_cast< const DataInfo(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialPortProtocol::*_t)(DataInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPortProtocol::transferDeviceData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SerialPortProtocol::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialPortProtocol.data,
      qt_meta_data_SerialPortProtocol,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialPortProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortProtocol.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialPortProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SerialPortProtocol::transferDeviceData(DataInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
