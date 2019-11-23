/****************************************************************************
** Meta object code from reading C++ file 'options.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ui/options.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'options.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_options_t {
    QByteArrayData data[7];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_options_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_options_t qt_meta_stringdata_options = {
    {
QT_MOC_LITERAL(0, 0, 7), // "options"
QT_MOC_LITERAL(1, 8, 21), // "on_backToMenu_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 22), // "on_validPlayer_clicked"
QT_MOC_LITERAL(4, 54, 19), // "on_letsPlay_clicked"
QT_MOC_LITERAL(5, 74, 9), // "getPseudo"
QT_MOC_LITERAL(6, 84, 20) // "std::vector<QString>"

    },
    "options\0on_backToMenu_clicked\0\0"
    "on_validPlayer_clicked\0on_letsPlay_clicked\0"
    "getPseudo\0std::vector<QString>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_options[] = {

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
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 6,

       0        // eod
};

void options::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        options *_t = static_cast<options *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_backToMenu_clicked(); break;
        case 1: _t->on_validPlayer_clicked(); break;
        case 2: _t->on_letsPlay_clicked(); break;
        case 3: { std::vector<QString> _r = _t->getPseudo();
            if (_a[0]) *reinterpret_cast< std::vector<QString>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject options::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_options.data,
      qt_meta_data_options,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *options::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *options::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_options.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int options::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
