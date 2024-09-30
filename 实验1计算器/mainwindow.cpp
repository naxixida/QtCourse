#include "mainwindow.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QKeyEvent>
#include <QStack>
#include <QRegularExpression>
#include <QPushButton>
#include <cmath> // 引入cmath库以使用数学函数

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), display(new QLineEdit(this)) {

    setupUI();
}

MainWindow::~MainWindow() {
    // 自动释放内存
}

void MainWindow::setupUI() {
    setWindowTitle("Calculator");

    // 设置显示区域
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setStyleSheet("QLineEdit {"
                           "    background-color: #f0f0f0;"
                           "    font-size: 24px;"
                           "    padding: 10px;"
                           "    border: 2px solid #ccc;"
                           "    border-radius: 5px;"
                           "}");

    // 创建布局
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QGridLayout *buttonLayout = new QGridLayout;

    // 添加按钮，包括新添加的按钮
    QStringList buttons = {
        "7", "8", "9", "<-",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "/", "0", "1/x", "+",
        ".", "x²", "√", "=" // 新增按钮
    };

    int pos = 0;
    for (const QString &buttonText : buttons) {
        QPushButton *button = new QPushButton(buttonText, this);

        // 为按钮设置样式
        button->setStyleSheet("QPushButton {"
                              "    background-color: #4CAF50;"
                              "    color: white;"
                              "    font-size: 18px;"
                              "    padding: 10px;"
                              "    border-radius: 5px;"
                              "    border: 1px solid #4CAF50;"
                              "}"
                              "QPushButton:hover {"
                              "    background-color: #45a049;"
                              "}"
                              "QPushButton:pressed {"
                              "    background-color: #388E3C;"
                              "}");

        buttonLayout->addWidget(button, pos / 4, pos % 4);
        connect(button, &QPushButton::clicked, this, &MainWindow::on_button_clicked);
        pos++;
    }

    // 将显示区域和按钮布局添加到主布局中
    mainLayout->addWidget(display);
    mainLayout->addLayout(buttonLayout);

    // 设置主窗口的中心小部件
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // 为主窗口添加样式
    centralWidget->setStyleSheet("QWidget {"
                                 "    background-color: #f8f8f8;"
                                 "    font-family: Arial, sans-serif;"
                                 "}");
}

void MainWindow::on_button_clicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();

        if (buttonText == "<-") {
            on_clear_clicked();
        } else if (buttonText == "=") {
            on_equal_clicked();
        } else if (buttonText == "x²" || buttonText == "√" || buttonText == "1/x") {
            // 处理特殊计算函数
            double result = calculateSpecialFunctions(display->text() + buttonText);
            display->setText(QString::number(result));
            expression.clear(); // 清空表达式
        } else {
            expression += buttonText;
            display->setText(expression);
        }
    }
}


void MainWindow::on_equal_clicked() {
    double result = calculate(expression);
    display->setText(QString::number(result));
    expression.clear();
}

void MainWindow::on_clear_clicked() {
    expression.clear();
    display->clear();
}

double MainWindow::calculate(const QString &expr) {
    QStack<double> values; // 存储数字
    QStack<QChar> ops;     // 存储运算符

    QRegularExpression re("([0-9]+\\.?[0-9]*|[-+*/])");
    QRegularExpressionMatchIterator i = re.globalMatch(expr);

    while (i.hasNext()) {
        QString token = i.next().captured(0);
        if (token.toDouble() || token == "0") {
            values.push(token.toDouble());
        } else {
            while (!ops.isEmpty() && (ops.top() == '*' || ops.top() == '/') &&
                   (token == "+" || token == "-")) {
                double right = values.pop();
                double left = values.pop();
                QChar op = ops.pop();
                if (op == '*') values.push(left * right);
                if (op == '/') values.push(left / right);
            }
            ops.push(token[0]);
        }
    }

    // 处理剩余的运算符
    while (!ops.isEmpty()) {
        double right = values.pop();
        double left = values.pop();
        QChar op = ops.pop();
        if (op == '+') values.push(left + right);
        if (op == '-') values.push(left - right);
        else if (op == '*') values.push(left * right);
        else if (op == '/') values.push(left / right);
    }

    return values.isEmpty() ? 0 : values.pop();
}

// 键盘事件
void MainWindow::keyPressEvent(QKeyEvent *event) {
    QString keyText = event->text();

    if (keyText.isEmpty()) {
        return; // 忽略无效按键
    }

    if (keyText >= "0" && keyText <= "9" || keyText == ".") {
        expression += keyText;
        display->setText(expression);
    } else if (keyText == "+" || keyText == "-" || keyText == "*" || keyText == "/") {
        expression += keyText;
        display->setText(expression);
    } else if (keyText == "=" || keyText == "\n") {
        on_equal_clicked();
    } else if (keyText == "<-") {
        on_clear_clicked();
    } else if (keyText == "\b") { // 退格键
        on_backspace_clicked();
    }
}

void MainWindow::on_backspace_clicked() {
    if (!expression.isEmpty()) {
        expression.chop(1);
        display->setText(expression);
    }
}

// 计算逻辑
double MainWindow::calculateSpecialFunctions(const QString &expr) {
    if (expr.endsWith("x²")) {
        double value = expr.left(expr.length() - 2).toDouble();
        return value * value;
    } else if (expr.endsWith("√")) {
        double value = expr.left(expr.length() - 1).toDouble();
        return std::sqrt(value);
    } else if (expr.endsWith("1/x")) {
        double value = expr.left(expr.length() - 3).toDouble();
        return 1.0 / value;
    }
    return 0;
}
