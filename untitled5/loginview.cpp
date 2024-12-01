#include "loginview.h"
#include "ui_loginview.h"
#include"idatabase.h"

loginview::loginview(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::loginview)
{
    ui->setupUi(this);
}

loginview::~loginview()
{
    delete ui;
}

void loginview::on_btSignin_clicked()
{
    QString status=IDatabase:: getInstance().userLogin(ui->inputUserName->text(),ui->InputUserPassword->text());
    if(status=="loginOK")
    emit loginSuccess();
}

