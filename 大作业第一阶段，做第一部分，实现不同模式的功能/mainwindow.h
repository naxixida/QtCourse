#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QMenuBar>
#include <QStackedWidget>
#include <QDate>
#include <QComboBox>
#include <QLabel>


struct CalculationHistory {
    QString expression;
    double result;
    QString mode;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    double calculateSpecialFunctions(const QString &expr);
    double calculate(const QString &expr);

    QString currentMode = "Standard";
    void setupUI();
    void on_button_clicked();
    void on_equal_clicked();
    void on_clear_clicked();
    void on_backspace_clicked();
    void on_undo_clicked();

    void setStandardMode();
    void setScientificMode();
    void setProgrammerMode();
    void setDateMode();
    void setConversionMode();  // 添加声明

    void setupStandardMode();
    void setupScientificMode();
    void setupProgrammerMode();
    void setupDateMode();
    void setupConversionMode();  // 添加声明
    void on_decimalToBinary_clicked();
    void reuseHistoryItem();
    double convertCurrency(double amount, const QString &fromCurrency, const QString &toCurrency);
    double convertCapacity(double amount, const QString &fromUnit, const QString &toUnit);

    // 在mainwindow.h中添加

    QList<CalculationHistory> historyList;  // 历史记录列表
      void addToHistory(const QString &expr, double result);
    void clearHistory();
 void showHistoryDialog();  // 声明 showHistoryDialog 函数
    QLineEdit *display;
    QString expression;
    QStackedWidget *modeWidget;
};

#endif // MAINWINDOW_H
