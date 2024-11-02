/****************************************************************************
** Meta object code from reading C++ file 'replacedialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../replacedialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'replacedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSReplaceDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSReplaceDialogENDCLASS = QtMocHelpers::stringData(
    "ReplaceDialog",
    "rreplaceText",
    "",
    "searchText",
    "replaceText",
    "caseSensitive",
    "replaceAll",
    "searchDown",
    "on_btFindNext_clicked",
    "on_btReplace_clicked",
    "on_btReplaceall_clicked",
    "on_btCancel_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSReplaceDialogENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[14];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[12];
    char stringdata5[14];
    char stringdata6[11];
    char stringdata7[11];
    char stringdata8[22];
    char stringdata9[21];
    char stringdata10[24];
    char stringdata11[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSReplaceDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSReplaceDialogENDCLASS_t qt_meta_stringdata_CLASSReplaceDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ReplaceDialog"
        QT_MOC_LITERAL(14, 12),  // "rreplaceText"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 10),  // "searchText"
        QT_MOC_LITERAL(39, 11),  // "replaceText"
        QT_MOC_LITERAL(51, 13),  // "caseSensitive"
        QT_MOC_LITERAL(65, 10),  // "replaceAll"
        QT_MOC_LITERAL(76, 10),  // "searchDown"
        QT_MOC_LITERAL(87, 21),  // "on_btFindNext_clicked"
        QT_MOC_LITERAL(109, 20),  // "on_btReplace_clicked"
        QT_MOC_LITERAL(130, 23),  // "on_btReplaceall_clicked"
        QT_MOC_LITERAL(154, 19)   // "on_btCancel_clicked"
    },
    "ReplaceDialog",
    "rreplaceText",
    "",
    "searchText",
    "replaceText",
    "caseSensitive",
    "replaceAll",
    "searchDown",
    "on_btFindNext_clicked",
    "on_btReplace_clicked",
    "on_btReplaceall_clicked",
    "on_btCancel_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSReplaceDialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   55,    2, 0x08,    7 /* Private */,
       9,    0,   56,    2, 0x08,    8 /* Private */,
      10,    0,   57,    2, 0x08,    9 /* Private */,
      11,    0,   58,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    3,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ReplaceDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSReplaceDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSReplaceDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSReplaceDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ReplaceDialog, std::true_type>,
        // method 'rreplaceText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_btFindNext_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btReplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btReplaceall_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btCancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ReplaceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReplaceDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rreplaceText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 1: _t->on_btFindNext_clicked(); break;
        case 2: _t->on_btReplace_clicked(); break;
        case 3: _t->on_btReplaceall_clicked(); break;
        case 4: _t->on_btCancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReplaceDialog::*)(const QString , const QString , bool , bool , bool );
            if (_t _q_method = &ReplaceDialog::rreplaceText; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ReplaceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReplaceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSReplaceDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ReplaceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ReplaceDialog::rreplaceText(const QString _t1, const QString _t2, bool _t3, bool _t4, bool _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
