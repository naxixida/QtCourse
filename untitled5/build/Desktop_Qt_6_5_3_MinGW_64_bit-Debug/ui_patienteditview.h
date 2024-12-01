/********************************************************************************
** Form generated from reading UI file 'patienteditview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTEDITVIEW_H
#define UI_PATIENTEDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patienteditview
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QComboBox *dbComboSex;
    QLineEdit *dbCreatedTimestamp;
    QLineEdit *dbEditIDCard;
    QLabel *label_6;
    QDateEdit *dbDateEditDOB;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *dbEditMobile;
    QLineEdit *dbEditName;
    QLabel *label_2;
    QLabel *d;
    QLineEdit *dbEditID;
    QLabel *label_3;
    QSpinBox *dbSpinWeight;
    QSpinBox *dbSpinHeight;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *patienteditview)
    {
        if (patienteditview->objectName().isEmpty())
            patienteditview->setObjectName("patienteditview");
        patienteditview->resize(454, 397);
        layoutWidget = new QWidget(patienteditview);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(12, 80, 314, 225));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(77, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        dbComboSex = new QComboBox(layoutWidget);
        dbComboSex->addItem(QString());
        dbComboSex->addItem(QString());
        dbComboSex->setObjectName("dbComboSex");

        gridLayout->addWidget(dbComboSex, 4, 2, 1, 4);

        dbCreatedTimestamp = new QLineEdit(layoutWidget);
        dbCreatedTimestamp->setObjectName("dbCreatedTimestamp");

        gridLayout->addWidget(dbCreatedTimestamp, 9, 2, 1, 4);

        dbEditIDCard = new QLineEdit(layoutWidget);
        dbEditIDCard->setObjectName("dbEditIDCard");

        gridLayout->addWidget(dbEditIDCard, 2, 2, 1, 4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 2, 1, 1, 1);

        dbDateEditDOB = new QDateEdit(layoutWidget);
        dbDateEditDOB->setObjectName("dbDateEditDOB");

        gridLayout->addWidget(dbDateEditDOB, 3, 2, 1, 4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 6, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 8, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        dbEditMobile = new QLineEdit(layoutWidget);
        dbEditMobile->setObjectName("dbEditMobile");

        gridLayout->addWidget(dbEditMobile, 8, 2, 1, 4);

        dbEditName = new QLineEdit(layoutWidget);
        dbEditName->setObjectName("dbEditName");

        gridLayout->addWidget(dbEditName, 1, 2, 1, 4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 4, 1, 1, 1);

        d = new QLabel(layoutWidget);
        d->setObjectName("d");

        gridLayout->addWidget(d, 5, 1, 1, 1);

        dbEditID = new QLineEdit(layoutWidget);
        dbEditID->setObjectName("dbEditID");
        dbEditID->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

        gridLayout->addWidget(dbEditID, 0, 2, 1, 4);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 9, 1, 1, 1);

        dbSpinWeight = new QSpinBox(layoutWidget);
        dbSpinWeight->setObjectName("dbSpinWeight");

        gridLayout->addWidget(dbSpinWeight, 6, 2, 1, 4);

        dbSpinHeight = new QSpinBox(layoutWidget);
        dbSpinHeight->setObjectName("dbSpinHeight");

        gridLayout->addWidget(dbSpinHeight, 5, 2, 1, 4);


        horizontalLayout->addLayout(gridLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 150, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(patienteditview);

        QMetaObject::connectSlotsByName(patienteditview);
    } // setupUi

    void retranslateUi(QWidget *patienteditview)
    {
        patienteditview->setWindowTitle(QCoreApplication::translate("patienteditview", "\347\274\226\350\276\221\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        dbComboSex->setItemText(0, QCoreApplication::translate("patienteditview", "\347\224\267", nullptr));
        dbComboSex->setItemText(1, QCoreApplication::translate("patienteditview", "\345\245\263", nullptr));

        label_6->setText(QCoreApplication::translate("patienteditview", "\350\272\253\344\273\275\350\257\201\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("patienteditview", "\345\247\223\345\220\215:", nullptr));
        label_7->setText(QCoreApplication::translate("patienteditview", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("patienteditview", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("patienteditview", "ID:", nullptr));
        label_4->setText(QCoreApplication::translate("patienteditview", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("patienteditview", "\346\200\247\345\210\253\357\274\232", nullptr));
        d->setText(QCoreApplication::translate("patienteditview", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("patienteditview", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("patienteditview", "\345\217\226\346\266\210", nullptr));
        pushButton->setText(QCoreApplication::translate("patienteditview", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class patienteditview: public Ui_patienteditview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTEDITVIEW_H
