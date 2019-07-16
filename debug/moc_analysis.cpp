/****************************************************************************
** Meta object code from reading C++ file 'analysis.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../analysis.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Analysis_t {
    QByteArrayData data[8];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Analysis_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Analysis_t qt_meta_stringdata_Analysis = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Analysis"
QT_MOC_LITERAL(1, 9, 15), // "signal_400mSend"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "data"
QT_MOC_LITERAL(4, 31, 15), // "signal_GMSRSend"
QT_MOC_LITERAL(5, 47, 15), // "signal_SqlQuery"
QT_MOC_LITERAL(6, 63, 10), // "_400mFrame"
QT_MOC_LITERAL(7, 74, 9) // "GMSRFrame"

    },
    "Analysis\0signal_400mSend\0\0data\0"
    "signal_GMSRSend\0signal_SqlQuery\0"
    "_400mFrame\0GMSRFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Analysis[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void Analysis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Analysis *_t = static_cast<Analysis *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_400mSend((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->signal_GMSRSend((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->signal_SqlQuery((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->_400mFrame((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->GMSRFrame((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Analysis::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Analysis::signal_400mSend)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Analysis::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Analysis::signal_GMSRSend)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Analysis::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Analysis::signal_SqlQuery)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Analysis::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Analysis.data,
      qt_meta_data_Analysis,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Analysis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analysis::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Analysis.stringdata0))
        return static_cast<void*>(const_cast< Analysis*>(this));
    return QObject::qt_metacast(_clname);
}

int Analysis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Analysis::signal_400mSend(const QByteArray & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Analysis::signal_GMSRSend(const QByteArray & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Analysis::signal_SqlQuery(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
