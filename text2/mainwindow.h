#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPlainTextEdit>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class LineNumberArea;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void lineNumberAreaPaintEvent(QPaintEvent *event); // 用于绘制行号
    int lineNumberAreaWidth(); // 行号区域宽度
signals:
    void replaceText(const QString &searchText, const QString &replaceText, bool caseSensitive, bool replaceAll, bool searchDown);


private slots:

void updateCursorStatus();

    void handleFindText(const QString &text, bool caseSensitive, bool searchDown);

    void on_actionNew_triggered();
    void on_actionOPEN_triggered();
    void on_actionDD_triggered();
    void on_actionFind_triggered();
    void handleReplaceText(const QString &searchText, const QString &replaceText, bool caseSensitive, bool replaceAll, bool searchDown);
    void on_actionFont_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_action_L_triggered();
    void on_actionfontcolor_triggered();
    void on_actionbackgroundcolor_triggered();
    void on_actionabout_triggered();

void on_actionReplace_triggered();


    void on_actionSaveAs_triggered();

    void on_action_T_triggered(); // 工具栏
    void on_action_S_triggered(); // 状态栏
    void on_actionSelectAll_triggered();

    void on_actionfontbackgroundcolor_triggered();
    void toggleLineWrap(bool checked);
private:
    Ui::MainWindow *ui;
    QPlainTextEdit *textEdit;
    QLabel statusCursorLabel;
    QLabel statusLabel;
void updateStatus(); // 声明 updateStatus 函数

};








#endif // MAINWINDOW_H
