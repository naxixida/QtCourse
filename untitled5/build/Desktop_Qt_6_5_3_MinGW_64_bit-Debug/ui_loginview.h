/********************************************************************************
** Form generated from reading UI file 'loginview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINVIEW_H
#define UI_LOGINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginview
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *inputUserName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *InputUserPassword;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btSignup;
    QPushButton *btSignin;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *loginview)
    {
        if (loginview->objectName().isEmpty())
            loginview->setObjectName("loginview");
        loginview->resize(588, 405);
        verticalLayout_2 = new QVBoxLayout(loginview);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer = new QSpacerItem(20, 57, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(loginview);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_4 = new QLabel(loginview);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        verticalSpacer_2 = new QSpacerItem(20, 57, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(loginview);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        inputUserName = new QLineEdit(loginview);
        inputUserName->setObjectName("inputUserName");

        horizontalLayout_2->addWidget(inputUserName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(loginview);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        InputUserPassword = new QLineEdit(loginview);
        InputUserPassword->setObjectName("InputUserPassword");
        InputUserPassword->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_3->addWidget(InputUserPassword);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btSignup = new QPushButton(loginview);
        btSignup->setObjectName("btSignup");

        horizontalLayout->addWidget(btSignup);

        btSignin = new QPushButton(loginview);
        btSignin->setObjectName("btSignin");

        horizontalLayout->addWidget(btSignin);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 57, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_3);


        retranslateUi(loginview);

        QMetaObject::connectSlotsByName(loginview);
    } // setupUi

    void retranslateUi(QWidget *loginview)
    {
        loginview->setWindowTitle(QCoreApplication::translate("loginview", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("loginview", "\346\254\242\350\277\216\344\275\277\347\224\250\350\257\212\346\226\255\346\265\213\350\257\225\347\263\273\347\273\237", nullptr));
        label_4->setText(QCoreApplication::translate("loginview", "\345\274\200\345\217\221\350\200\205\357\274\232\351\203\255\346\265\251\346\226\207 \345\255\246\345\217\267\357\274\2322022414120207", nullptr));
        label_2->setText(QCoreApplication::translate("loginview", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("loginview", "\345\257\206\347\240\201", nullptr));
        btSignup->setText(QCoreApplication::translate("loginview", "\346\263\250\345\206\214", nullptr));
        btSignin->setText(QCoreApplication::translate("loginview", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginview: public Ui_loginview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINVIEW_H
