/****************************************************************************
** Meta object code from reading C++ file 'qFlightInstruments.h'
**
** Created: Mon Mar 23 09:22:01 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qFlightInstruments.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qFlightInstruments.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QADI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QADI[] = {
    "QADI\0canvasReplot()\0\0canvasReplot_slot()\0"
};

void QADI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QADI *_t = static_cast<QADI *>(_o);
        switch (_id) {
        case 0: _t->canvasReplot(); break;
        case 1: _t->canvasReplot_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QADI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QADI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QADI,
      qt_meta_data_QADI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QADI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QADI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QADI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QADI))
        return static_cast<void*>(const_cast< QADI*>(this));
    return QWidget::qt_metacast(_clname);
}

int QADI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QADI::canvasReplot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_QCompass[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QCompass[] = {
    "QCompass\0canvasReplot()\0\0canvasReplot_slot()\0"
};

void QCompass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QCompass *_t = static_cast<QCompass *>(_o);
        switch (_id) {
        case 0: _t->canvasReplot(); break;
        case 1: _t->canvasReplot_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QCompass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QCompass::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QCompass,
      qt_meta_data_QCompass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QCompass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QCompass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QCompass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCompass))
        return static_cast<void*>(const_cast< QCompass*>(this));
    return QWidget::qt_metacast(_clname);
}

int QCompass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QCompass::canvasReplot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_QKeyValueListView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   31,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   31,   31,   31, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QKeyValueListView[] = {
    "QKeyValueListView\0listUpdate()\0\0"
    "listUpdate_slot()\0"
};

void QKeyValueListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QKeyValueListView *_t = static_cast<QKeyValueListView *>(_o);
        switch (_id) {
        case 0: _t->listUpdate(); break;
        case 1: _t->listUpdate_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QKeyValueListView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QKeyValueListView::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_QKeyValueListView,
      qt_meta_data_QKeyValueListView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QKeyValueListView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QKeyValueListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QKeyValueListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QKeyValueListView))
        return static_cast<void*>(const_cast< QKeyValueListView*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int QKeyValueListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QKeyValueListView::listUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
