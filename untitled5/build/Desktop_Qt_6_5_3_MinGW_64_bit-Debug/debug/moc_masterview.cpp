/****************************************************************************
** Meta object code from reading C++ file 'masterview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../masterview.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'masterview.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMasterViewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMasterViewENDCLASS = QtMocHelpers::stringData(
    "MasterView",
    "goLoginView",
    "",
    "goWelcomeView",
    "goDoctorView",
    "goDepartmentView",
    "goPatientEditView",
    "rowNo",
    "goPatientView",
    "goPreviousView",
    "on_btback_clicked",
    "on_stackedWidget_currentChanged",
    "arg1",
    "on_btlogout_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMasterViewENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[13];
    char stringdata5[17];
    char stringdata6[18];
    char stringdata7[6];
    char stringdata8[14];
    char stringdata9[15];
    char stringdata10[18];
    char stringdata11[32];
    char stringdata12[5];
    char stringdata13[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMasterViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMasterViewENDCLASS_t qt_meta_stringdata_CLASSMasterViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MasterView"
        QT_MOC_LITERAL(11, 11),  // "goLoginView"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 13),  // "goWelcomeView"
        QT_MOC_LITERAL(38, 12),  // "goDoctorView"
        QT_MOC_LITERAL(51, 16),  // "goDepartmentView"
        QT_MOC_LITERAL(68, 17),  // "goPatientEditView"
        QT_MOC_LITERAL(86, 5),  // "rowNo"
        QT_MOC_LITERAL(92, 13),  // "goPatientView"
        QT_MOC_LITERAL(106, 14),  // "goPreviousView"
        QT_MOC_LITERAL(121, 17),  // "on_btback_clicked"
        QT_MOC_LITERAL(139, 31),  // "on_stackedWidget_currentChanged"
        QT_MOC_LITERAL(171, 4),  // "arg1"
        QT_MOC_LITERAL(176, 19)   // "on_btlogout_clicked"
    },
    "MasterView",
    "goLoginView",
    "",
    "goWelcomeView",
    "goDoctorView",
    "goDepartmentView",
    "goPatientEditView",
    "rowNo",
    "goPatientView",
    "goPreviousView",
    "on_btback_clicked",
    "on_stackedWidget_currentChanged",
    "arg1",
    "on_btlogout_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMasterViewENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x0a,    2 /* Public */,
       4,    0,   76,    2, 0x0a,    3 /* Public */,
       5,    0,   77,    2, 0x0a,    4 /* Public */,
       6,    1,   78,    2, 0x0a,    5 /* Public */,
       8,    0,   81,    2, 0x0a,    7 /* Public */,
       9,    0,   82,    2, 0x0a,    8 /* Public */,
      10,    0,   83,    2, 0x08,    9 /* Private */,
      11,    1,   84,    2, 0x08,   10 /* Private */,
      13,    0,   87,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MasterView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMasterViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMasterViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMasterViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MasterView, std::true_type>,
        // method 'goLoginView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goWelcomeView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goDoctorView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goDepartmentView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goPatientEditView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'goPatientView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'goPreviousView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btback_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stackedWidget_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_btlogout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MasterView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MasterView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goLoginView(); break;
        case 1: _t->goWelcomeView(); break;
        case 2: _t->goDoctorView(); break;
        case 3: _t->goDepartmentView(); break;
        case 4: _t->goPatientEditView((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->goPatientView(); break;
        case 6: _t->goPreviousView(); break;
        case 7: _t->on_btback_clicked(); break;
        case 8: _t->on_stackedWidget_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_btlogout_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MasterView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MasterView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMasterViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MasterView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
