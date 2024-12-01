#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include"loginview.h"
#include"doctorview.h"
#include"departmentview.h"
#include"patienteditview.h"
#include"welcomeview.h"
#include"patientview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MasterView;
}
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goDepartmentView();
    void goPatientEditView(int rowNo);
    void goPatientView();
    void goPreviousView();
private slots:
    void on_btback_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btlogout_clicked();

private:
    Ui::MasterView *ui;

    void pushWidgetToStackView(QWidget *widget);
    welcomeview *welcomeView;
    doctorview *doctorView;
    patientview *patientView;
    departmentview *departmentView;
    loginview *loginView;
    patienteditview *patienteditView;



};
#endif // MASTERVIEW_H
