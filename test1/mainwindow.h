#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    double calculateSpecialFunctions(const QString &expr);


protected:
    void keyPressEvent(QKeyEvent *event) override; // 添加这一行

private:
    void setupUI();
    void on_button_clicked();
    void on_equal_clicked();
    void on_clear_clicked();
    void on_backspace_clicked(); // 可选，添加后退键处理
    double calculate(const QString &expr);

    QLineEdit *display;
    QString expression;
};

#endif // MAINWINDOW_H
