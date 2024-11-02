#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "searchdialog.h"
#include "replacedialog.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
 textEdit = ui->TextEdit;
    connect(ui->action_T, &QAction::triggered, this, &MainWindow::on_action_T_triggered);
    connect(ui->action_S, &QAction::triggered, this, &MainWindow::on_action_S_triggered);
    connect(ui->action_T, &QAction::triggered, this, &MainWindow::on_action_T_triggered);
    connect(ui->action_S, &QAction::triggered, this, &MainWindow::on_action_S_triggered);
    connect(ui->actionWrap, &QAction::toggled, this, &MainWindow::toggleLineWrap);

    // 初始化状态栏
    statusLabel.setMaximumWidth(150);
    statusLabel.setText("length: 0  lines: 1");
    ui->statusbar->addPermanentWidget(&statusLabel);

    statusCursorLabel.setMaximumWidth(150);
    statusCursorLabel.setText("Ln: 1  Col: 1");
    ui->statusbar->addPermanentWidget(&statusCursorLabel);

    QLabel *author = new QLabel(ui->statusbar);
    author->setText(tr("郭浩文"));
    ui->statusbar->addPermanentWidget(author);
    ui->toolBar->setVisible(false);
    ui->statusbar->setVisible(false);



    // 连接编辑器信号和槽，用于更新行列状态
    connect(ui->TextEdit, &QPlainTextEdit::cursorPositionChanged, this, &MainWindow::updateCursorStatus);




}

// 槽函数：切换自动换行
void MainWindow::toggleLineWrap(bool checked)
{
    if (checked) {
        ui->TextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth); // 开启自动换行
    } else {
        ui->TextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);      // 关闭自动换行
    }
}




MainWindow::~MainWindow()
{
    delete ui;
}











// 更新行列信息
void MainWindow::updateCursorStatus()
{
    QTextCursor cursor = ui->TextEdit->textCursor();
    int line = cursor.blockNumber() + 1;
    int column = cursor.columnNumber() + 1;
    statusCursorLabel.setText("Ln: " + QString::number(line) + "  Col: " + QString::number(column));
}

// 新建文件
void MainWindow::on_actionNew_triggered()
{
    if (!ui->TextEdit->document()->isEmpty()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "新建文件", "当前内容未保存，是否继续？",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) {
            return;
        }
    }
    ui->TextEdit->clear();
    setWindowTitle("好用文本编辑器");
    statusLabel.setText("length: 0  lines: 1");
    statusCursorLabel.setText("Ln: 1  Col: 1");
}
//全选
void MainWindow::on_actionSelectAll_triggered()
{
    ui->TextEdit->selectAll();  // 调用 QPlainTextEdit 的 selectAll 方法
}
// 打开文件
void MainWindow::on_actionOPEN_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", "", "Text Files (*.txt);;All Files (*.*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&file);
            ui->TextEdit->setPlainText(in.readAll());
            file.close();
            setWindowTitle(fileName + " - 文本编辑器");
            updateStatus();
        }
    }
}

// 保存文件
void MainWindow::on_actionDD_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "", "Text Files (*.txt);;All Files (*.*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream out(&file);
            out << ui->TextEdit->toPlainText();
            file.close();
            setWindowTitle(fileName + " - 文本编辑器");
        }
    }
}
//另存为
void MainWindow::on_actionSaveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "另存为", "", "Text Files (*.txt);;All Files (*.*)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream out(&file);
            out << ui->TextEdit->toPlainText();
            file.close();
            setWindowTitle(fileName + " - 文本编辑器");
        }
    }
}


// 查找功能

void MainWindow::on_actionFind_triggered()
{
    SearchDialog *searchDialog = new SearchDialog(this);
    connect(searchDialog, &SearchDialog::findText, this, &MainWindow::handleFindText);
    searchDialog->exec();
}

void MainWindow::handleFindText(const QString &text, bool caseSensitive, bool searchDown)
{
    QTextDocument::FindFlags options;
    if (caseSensitive) {
        options |= QTextDocument::FindCaseSensitively;
    }
    if (!searchDown) {
        options |= QTextDocument::FindBackward;
    }

    bool found = ui->TextEdit->find(text, options);
    if (!found) {
        // 提示未找到
        QMessageBox::information(this, "查找", "未找到目标内容");
    }
}



void MainWindow::on_actionReplace_triggered()
{
    ReplaceDialog dig;
    connect(&dig, &ReplaceDialog::rreplaceText, this, &MainWindow::handleReplaceText);
    dig.exec();
}

void MainWindow::handleReplaceText(const QString &searchText, const QString &replaceText, bool caseSensitive, bool replaceAll, bool searchDown)
{
    QTextDocument *doc = ui->TextEdit->document();
    QTextCursor cursor = ui->TextEdit->textCursor();

    // 设置查找选项
    QTextDocument::FindFlags flags;
    if (caseSensitive) {
        flags |= QTextDocument::FindCaseSensitively;
    }

    if (searchDown) {
        cursor = doc->find(searchText, cursor, flags);
    } else {
        cursor = doc->find(searchText, cursor, flags | QTextDocument::FindBackward);
    }

    if (!cursor.isNull()) {
        ui->TextEdit->setTextCursor(cursor);
        if (!replaceText.isEmpty()) {
            cursor.insertText(replaceText);
            if (!replaceAll) {
                return; // 如果只是查找下一个，不进行替换
            }
        }
    } else if (replaceAll) {
        // 如果是全部替换，重置光标并查找所有
        cursor = doc->find(searchText, cursor, flags);
        while (!cursor.isNull()) {
            cursor.insertText(replaceText);
            cursor = doc->find(searchText, cursor, flags);
        }
    } else {
        QMessageBox::information(this, "查找", "未找到指定文本。");
    }
}
void MainWindow::on_actionabout_triggered()
{
    AboutDialog  dig;
    dig.exec();
}
// 字体设置
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        ui->TextEdit->setFont(font);
    }
}





// 撤销
void MainWindow::on_actionUndo_triggered()
{
    ui->TextEdit->undo();
}

// 恢复
void MainWindow::on_actionRedo_triggered()
{
    ui->TextEdit->redo();
}

// 剪切
void MainWindow::on_actionCut_triggered()
{
    ui->TextEdit->cut();
}

// 复制
void MainWindow::on_actionCopy_triggered()
{
    ui->TextEdit->copy();
}

// 粘贴
void MainWindow::on_actionPaste_triggered()
{
    ui->TextEdit->paste();
}

// 显示/隐藏行号
void MainWindow::on_action_L_triggered() {

}


// 更改字体颜色
void MainWindow::on_actionfontcolor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "选择字体颜色");
    if (color.isValid()) {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        QTextCursor cursor = ui->TextEdit->textCursor();
        cursor.mergeCharFormat(fmt);
        ui->TextEdit->mergeCurrentCharFormat(fmt);
    }
}

// 更改背景颜色
void MainWindow::on_actionbackgroundcolor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "选择背景颜色");
    if (color.isValid()) {
        QPalette palette = ui->TextEdit->palette();
        palette.setColor(QPalette::Base, color);
        ui->TextEdit->setPalette(palette);
    }
}

// 更新状态栏信息
void MainWindow::updateStatus()
{
    int length = ui->TextEdit->toPlainText().length();
    int lines = ui->TextEdit->document()->blockCount();
    statusLabel.setText("length: " + QString::number(length) + "  lines: " + QString::number(lines));
}
void MainWindow::on_actionfontbackgroundcolor_triggered()
{
    // 打开颜色选择对话框
    QColor color = QColorDialog::getColor(Qt::white, this, "选择字体背景色");

    // 检查用户是否选择了有效的颜色
    if (color.isValid()) {
        QTextCharFormat fmt;
        fmt.setBackground(color);  // 设置背景色
        QTextCursor cursor = ui->TextEdit->textCursor();
        cursor.mergeCharFormat(fmt);  // 将格式合并到当前文本光标位置
        ui->TextEdit->mergeCurrentCharFormat(fmt);  // 应用到文本编辑器
    }
}


void MainWindow::on_action_T_triggered()
{
    // 切换工具栏的可见性
    bool isVisible = ui->toolBar->isVisible();
    ui->toolBar->setVisible(!isVisible);
}




void MainWindow::on_action_S_triggered()
{
    bool isVisible = ui->statusbar->isVisible();
    ui->statusbar->setVisible(!isVisible);
}



