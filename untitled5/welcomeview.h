#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include <QWidget>

namespace Ui {
class welcomeview;
}

class welcomeview : public QWidget
{
    Q_OBJECT

public:
    explicit welcomeview(QWidget *parent = nullptr);
    ~welcomeview();

private slots:
    void on_btDepatrmnet_clicked();

    void on_btDoctor_clicked();

    void on_pushButton_3_clicked();

signals:
    void goDepartmentView();
    void goDoctorView();
    void goPatientView();
private:
    Ui::welcomeview *ui;
};

#endif // WELCOMEVIEW_H
