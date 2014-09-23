/****************************************************************************
** Meta object code from reading C++ file 'namecontroller.h'
**
** Created: Thu Nov 3 17:12:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../namecontroller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'namecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NameController[] = {

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
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NameController[] = {
    "NameController\0\0quit()\0getData()\0"
};

const QMetaObject NameController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NameController,
      qt_meta_data_NameController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NameController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NameController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NameController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NameController))
        return static_cast<void*>(const_cast< NameController*>(this));
    return QObject::qt_metacast(_clname);
}

int NameController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: quit(); break;
        case 1: getData(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void NameController::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
