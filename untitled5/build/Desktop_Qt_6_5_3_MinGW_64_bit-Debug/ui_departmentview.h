/********************************************************************************
** Form generated from reading UI file 'departmentview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTVIEW_H
#define UI_DEPARTMENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_departmentview
{
public:

    void setupUi(QWidget *departmentview)
    {
        if (departmentview->objectName().isEmpty())
            departmentview->setObjectName("departmentview");
        departmentview->resize(400, 300);

        retranslateUi(departmentview);

        QMetaObject::connectSlotsByName(departmentview);
    } // setupUi

    void retranslateUi(QWidget *departmentview)
    {
        departmentview->setWindowTitle(QCoreApplication::translate("departmentview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class departmentview: public Ui_departmentview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTVIEW_H
