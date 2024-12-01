#include "masterview.h"
#include "ui_masterview.h"
#include <QDebug>
#include"idatabase.h"
MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);

    goLoginView();
    IDatabase::getInstance();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    loginView = new loginview(this);
    ui->stackedWidget->addWidget(loginView);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count - 1);//总是显示最新加入的View
    ui->labelTITle->setText(loginView->windowTitle());

    connect(loginView,SIGNAL(loginSuccess()),this,SLOT(goWelcomeView()));
}


void MasterView::goWelcomeView()
{
   welcomeView = new welcomeview(this);
   pushWidgetToStackView(welcomeView);
   connect(welcomeView,SIGNAL(goDoctorView()),this,SLOT(goDoctorView()));
   connect(welcomeView,SIGNAL(goDepartmentView()),this,SLOT(goDepartmentView()));
   connect(welcomeView,SIGNAL(goPatientView()),this,SLOT(goPatientView()));
}

void MasterView::goDoctorView()
{

    doctorView = new  doctorview(this);
    pushWidgetToStackView( doctorView);
}

void MasterView::goDepartmentView()
{

    departmentView = new departmentview(this);
    pushWidgetToStackView(departmentView);
}

void MasterView::goPatientEditView(int rowNo)
{
    qDebug()<<"goPatientEditView";
   patienteditView = new patienteditview(this,rowNo);
    pushWidgetToStackView(patienteditView);
   connect(patienteditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goPatientView()
{

    patientView = new patientview(this);
    pushWidgetToStackView(patientView);

      connect(patientView,SIGNAL(goPatientEditView(int)),this,SLOT(goPatientEditView(int)));
}

void MasterView::goPreviousView()
{
    int count = ui->stackedWidget->count();
    if(count>1){
        ui->stackedWidget->setCurrentIndex(count - 2);
        ui->labelTITle->setText(ui->stackedWidget->currentWidget()->windowTitle());

        QWidget *widget =ui->stackedWidget->widget(count - 1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }
}


void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count - 1);//总是显示最新加入的View
    ui->labelTITle->setText(widget->windowTitle());
}

void MasterView::on_btback_clicked()
{
    goPreviousView();
}


void MasterView::on_stackedWidget_currentChanged(int arg1)
{
    int count = ui->stackedWidget->count();
    if(count>1)
        ui->btback->setEnabled(true);
    else
        ui->btback->setEnabled(false);
    QString title = ui->stackedWidget->currentWidget()->windowTitle();
    if(title == "欢迎"){
        ui->btlogout->setEnabled(true);
            ui->btback->setEnabled(false);

    }else if(title == "登录")
    {
        ui->btlogout->setEnabled(false);
         ui->btback->setEnabled(false);
    }
    else
     ui->btlogout->setEnabled(false);



}


void MasterView::on_btlogout_clicked()
{
    goPreviousView();
}

