/********************************************************************************
** Form generated from reading UI file 'patientview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTVIEW_H
#define UI_PATIENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patientview
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtSearch;
    QPushButton *btSearch;
    QPushButton *btAdd;
    QPushButton *btDelete;
    QPushButton *btEdit;
    QTableView *tableView;

    void setupUi(QWidget *patientview)
    {
        if (patientview->objectName().isEmpty())
            patientview->setObjectName("patientview");
        patientview->resize(400, 300);
        verticalLayout = new QVBoxLayout(patientview);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        txtSearch = new QLineEdit(patientview);
        txtSearch->setObjectName("txtSearch");

        horizontalLayout->addWidget(txtSearch);

        btSearch = new QPushButton(patientview);
        btSearch->setObjectName("btSearch");

        horizontalLayout->addWidget(btSearch);

        btAdd = new QPushButton(patientview);
        btAdd->setObjectName("btAdd");

        horizontalLayout->addWidget(btAdd);

        btDelete = new QPushButton(patientview);
        btDelete->setObjectName("btDelete");

        horizontalLayout->addWidget(btDelete);

        btEdit = new QPushButton(patientview);
        btEdit->setObjectName("btEdit");

        horizontalLayout->addWidget(btEdit);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(patientview);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(patientview);

        QMetaObject::connectSlotsByName(patientview);
    } // setupUi

    void retranslateUi(QWidget *patientview)
    {
        patientview->setWindowTitle(QCoreApplication::translate("patientview", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
        txtSearch->setPlaceholderText(QCoreApplication::translate("patientview", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215\346\237\245\346\211\276", nullptr));
        btSearch->setText(QCoreApplication::translate("patientview", "\346\237\245\346\211\276", nullptr));
        btAdd->setText(QCoreApplication::translate("patientview", "\346\267\273\345\212\240", nullptr));
        btDelete->setText(QCoreApplication::translate("patientview", "\345\210\240\351\231\244", nullptr));
        btEdit->setText(QCoreApplication::translate("patientview", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class patientview: public Ui_patientview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTVIEW_H
