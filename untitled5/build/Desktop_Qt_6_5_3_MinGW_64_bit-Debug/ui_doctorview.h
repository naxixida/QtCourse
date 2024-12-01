/********************************************************************************
** Form generated from reading UI file 'doctorview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORVIEW_H
#define UI_DOCTORVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctorview
{
public:

    void setupUi(QWidget *doctorview)
    {
        if (doctorview->objectName().isEmpty())
            doctorview->setObjectName("doctorview");
        doctorview->resize(400, 300);

        retranslateUi(doctorview);

        QMetaObject::connectSlotsByName(doctorview);
    } // setupUi

    void retranslateUi(QWidget *doctorview)
    {
        doctorview->setWindowTitle(QCoreApplication::translate("doctorview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doctorview: public Ui_doctorview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORVIEW_H
