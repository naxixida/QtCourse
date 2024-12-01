#include "idatabase.h"
#include<QUuid>
void IDatabase::ininDatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile="C:/Users/郭浩文/Desktop/qt/lab4a.db";
    database.setDatabaseName(aFile);//设置数据库名称


    if(!database.open()){
        qDebug()<<"failed to open database";
    }else
        qDebug()<<"open database is ok";
}

bool IDatabase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);
    if(!(patientTabModel->select()))//查询数据
        return false;

    thePatientSelection =new QItemSelectionModel(patientTabModel);
    return true;
}

int IDatabase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex());//在末尾添加记录
    QModelIndex curIndex =patientTabModel->index(patientTabModel->rowCount()-1,1);

    int curRecNo =curIndex.row();
    QSqlRecord curRec =patientTabModel->record(curRecNo);
    curRec.setValue("CREATEDTIMESTAMP",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));

    patientTabModel->setRecord(curRecNo,curRec);
    return  curIndex.row();

}

bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex =thePatientSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool IDatabase::sumbitPatientEdit()
{
    return patientTabModel->submitAll();
}

void IDatabase::revertPatientEdit()
{
      return patientTabModel->revertAll();
}





QString IDatabase::userLogin(QString userName, QString password)
{
  //  return "loginFaied";
    QSqlQuery query;
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER",userName);
    query.exec();
    if(query.first() && query.value("username").isValid()){
        QString passwd = query.value("password").toString();
        if(passwd == password){
            qDebug()<<"login ok";
            return "loginOK";

        }
        else{
            qDebug()<<"wrong password";
            return "wrongPassword";
        }
    }else{
        qDebug()<<"no such user";
        return "wrongUsername";
    }
}


IDatabase::IDatabase(QObject *parent) : QObject{parent}
{
    ininDatabase();
}
