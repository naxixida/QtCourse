#include "patienteditview.h"
#include "ui_patienteditview.h"
#include"idatabase.h"
#include<QSqlTableModel>
patienteditview::patienteditview(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::patienteditview)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().patientTabModel;
    dataMapper->setModel(IDatabase::getInstance().patientTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbEditID,tabModel->fieldIndex("ID"));
     dataMapper->addMapping(ui->dbEditName,tabModel->fieldIndex("NAME"));
     dataMapper->addMapping(ui->dbEditIDCard,tabModel->fieldIndex("ID_CARD"));
      dataMapper->addMapping(ui->dbSpinHeight,tabModel->fieldIndex("HEIGHT"));
      dataMapper->addMapping(ui->dbSpinWeight,tabModel->fieldIndex("WEIGHT"));
       dataMapper->addMapping(ui->dbEditMobile,tabModel->fieldIndex("MOBILEPHONE"));
       dataMapper->addMapping(ui->dbDateEditDOB,tabModel->fieldIndex("DOB"));
        dataMapper->addMapping(ui->dbComboSex,tabModel->fieldIndex("SEX"));
        dataMapper->addMapping(ui->dbCreatedTimestamp,tabModel->fieldIndex("CREATEDTIMESTAMP"));


        dataMapper->setCurrentIndex(index);
        ui->dbEditID->setFocus();

}

patienteditview::~patienteditview()
{
    delete ui;
}

void patienteditview::on_pushButton_clicked()
{
    IDatabase::getInstance().sumbitPatientEdit();
    emit goPreviousView();
}


void patienteditview::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertPatientEdit();
    emit goPreviousView();
}

