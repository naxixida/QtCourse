/********************************************************************************
** Form generated from reading UI file 'welcomeview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEVIEW_H
#define UI_WELCOMEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcomeview
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btDepatrmnet;
    QPushButton *btDoctor;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *welcomeview)
    {
        if (welcomeview->objectName().isEmpty())
            welcomeview->setObjectName("welcomeview");
        welcomeview->resize(400, 300);
        verticalLayout = new QVBoxLayout(welcomeview);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 111, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btDepatrmnet = new QPushButton(welcomeview);
        btDepatrmnet->setObjectName("btDepatrmnet");
        btDepatrmnet->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(btDepatrmnet);

        btDoctor = new QPushButton(welcomeview);
        btDoctor->setObjectName("btDoctor");
        btDoctor->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(btDoctor);

        pushButton_3 = new QPushButton(welcomeview);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(50, 50));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 111, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(welcomeview);

        QMetaObject::connectSlotsByName(welcomeview);
    } // setupUi

    void retranslateUi(QWidget *welcomeview)
    {
        welcomeview->setWindowTitle(QCoreApplication::translate("welcomeview", "\346\254\242\350\277\216", nullptr));
        btDepatrmnet->setText(QCoreApplication::translate("welcomeview", "\347\247\221\345\256\244\347\256\241\347\220\206", nullptr));
        btDoctor->setText(QCoreApplication::translate("welcomeview", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("welcomeview", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcomeview: public Ui_welcomeview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEVIEW_H
