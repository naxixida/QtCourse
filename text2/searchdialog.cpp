#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    ui->rbDown->setChecked(true);  // 默认向下搜索
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_btFindNext_clicked()
{
    QString searchText = ui->searchtext->text();
    bool caseSensitive = ui->checkBox->isChecked();
    bool searchDown = ui->rbDown->isChecked();

    emit findText(searchText, caseSensitive, searchDown);
}
