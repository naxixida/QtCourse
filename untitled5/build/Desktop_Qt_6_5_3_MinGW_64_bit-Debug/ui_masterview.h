/********************************************************************************
** Form generated from reading UI file 'masterview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTERVIEW_H
#define UI_MASTERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MasterView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btback;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTITle;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btlogout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *MasterView)
    {
        if (MasterView->objectName().isEmpty())
            MasterView->setObjectName("MasterView");
        MasterView->resize(588, 299);
        verticalLayout = new QVBoxLayout(MasterView);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btback = new QPushButton(MasterView);
        btback->setObjectName("btback");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        btback->setIcon(icon);

        horizontalLayout->addWidget(btback);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelTITle = new QLabel(MasterView);
        labelTITle->setObjectName("labelTITle");

        horizontalLayout->addWidget(labelTITle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btlogout = new QPushButton(MasterView);
        btlogout->setObjectName("btlogout");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        btlogout->setIcon(icon1);

        horizontalLayout->addWidget(btlogout);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(MasterView);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(MasterView);

        QMetaObject::connectSlotsByName(MasterView);
    } // setupUi

    void retranslateUi(QWidget *MasterView)
    {
        MasterView->setWindowTitle(QCoreApplication::translate("MasterView", "MasterView", nullptr));
        btback->setText(QString());
        labelTITle->setText(QString());
        btlogout->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MasterView: public Ui_MasterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTERVIEW_H
