#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr);
    ~ReplaceDialog();

signals:
    void rreplaceText(const QString searchText, const QString replaceText, bool caseSensitive, bool replaceAll, bool searchDown);

private slots:
    void on_btFindNext_clicked();
    void on_btReplace_clicked();
    void on_btReplaceall_clicked();
    void on_btCancel_clicked();

private:
    Ui::ReplaceDialog *ui;
};

#endif // REPLACEDIALOG_H
