#include "welcomeview.h"
#include "ui_welcomeview.h"
#include<QDebug>
welcomeview::welcomeview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::welcomeview)
{
    qDebug()<<"create WelcomeView";
    ui->setupUi(this);
}

welcomeview::~welcomeview()
{
    qDebug()<<"destroy WelcomeView";
    delete ui;
}

void welcomeview::on_btDepatrmnet_clicked()
{
    emit goDepartmentView();
}


void welcomeview::on_btDoctor_clicked()
{
    emit goDoctorView();
}


void welcomeview::on_pushButton_3_clicked()
{
    emit goPatientView();
}

