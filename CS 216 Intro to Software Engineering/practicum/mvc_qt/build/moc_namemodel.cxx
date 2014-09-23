/****************************************************************************
** Meta object code from reading C++ file 'namemodel.h'
**
** Created: Mon Nov 7 09:05:07 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../namemodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'namemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NameModel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   25,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NameModel[] = {
    "NameModel\0\0nameChanged()\0f,l\0"
    "setName(std::string,std::string)\0"
};

const QMetaObject NameModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NameModel,
      qt_meta_data_NameModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NameModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NameModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NameModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NameModel))
        return static_cast<void*>(const_cast< NameModel*>(this));
    return QObject::qt_metacast(_clname);
}

int NameModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: nameChanged(); break;
        case 1: setName((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void NameModel::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
