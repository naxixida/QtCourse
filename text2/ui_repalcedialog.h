/********************************************************************************
** Form generated from reading UI file 'repalcedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPALCEDIALOG_H
#define UI_REPALCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RepalceDialog
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *searchtext;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbDown;
    QRadioButton *rbUp;
    QVBoxLayout *verticalLayout;
    QPushButton *btFindNext;
    QPushButton *btCancel;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *RepalceDialog)
    {
        if (RepalceDialog->objectName().isEmpty())
            RepalceDialog->setObjectName("RepalceDialog");
        RepalceDialog->resize(303, 107);
        horizontalLayout_5 = new QHBoxLayout(RepalceDialog);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(RepalceDialog);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        searchtext = new QLineEdit(RepalceDialog);
        searchtext->setObjectName("searchtext");

        horizontalLayout->addWidget(searchtext);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(RepalceDialog);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(RepalceDialog);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        checkBox = new QCheckBox(RepalceDialog);
        checkBox->setObjectName("checkBox");

        horizontalLayout_4->addWidget(checkBox);

        groupBox = new QGroupBox(RepalceDialog);
        groupBox->setObjectName("groupBox");
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        rbDown = new QRadioButton(groupBox);
        rbDown->setObjectName("rbDown");

        horizontalLayout_3->addWidget(rbDown);

        rbUp = new QRadioButton(groupBox);
        rbUp->setObjectName("rbUp");

        horizontalLayout_3->addWidget(rbUp);


        horizontalLayout_4->addWidget(groupBox);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btFindNext = new QPushButton(RepalceDialog);
        btFindNext->setObjectName("btFindNext");

        verticalLayout->addWidget(btFindNext);

        btCancel = new QPushButton(RepalceDialog);
        btCancel->setObjectName("btCancel");

        verticalLayout->addWidget(btCancel);

        pushButton = new QPushButton(RepalceDialog);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(RepalceDialog);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_5->addLayout(verticalLayout);


        retranslateUi(RepalceDialog);

        QMetaObject::connectSlotsByName(RepalceDialog);
    } // setupUi

    void retranslateUi(QDialog *RepalceDialog)
    {
        RepalceDialog->setWindowTitle(QCoreApplication::translate("RepalceDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RepalceDialog", "\346\237\245\346\211\276\347\233\256\346\240\207\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("RepalceDialog", "\346\233\277\346\215\242\344\270\272\357\274\232", nullptr));
        checkBox->setText(QCoreApplication::translate("RepalceDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RepalceDialog", "\346\226\271\345\220\221", nullptr));
        rbDown->setText(QCoreApplication::translate("RepalceDialog", "\345\220\221\344\270\213\357\274\210D\357\274\211", nullptr));
        rbUp->setText(QCoreApplication::translate("RepalceDialog", "\345\220\221\344\270\212\357\274\210U\357\274\211", nullptr));
        btFindNext->setText(QCoreApplication::translate("RepalceDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252\357\274\210F\357\274\211", nullptr));
        btCancel->setText(QCoreApplication::translate("RepalceDialog", "\345\217\226\346\266\210", nullptr));
        pushButton->setText(QCoreApplication::translate("RepalceDialog", "\346\233\277\346\215\242\357\274\210R\357\274\211", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RepalceDialog", "\345\205\250\351\203\250\346\233\277\346\215\242\357\274\210A\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RepalceDialog: public Ui_RepalceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPALCEDIALOG_H
