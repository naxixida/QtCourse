#include "mainwindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QMessageBox>
#include <QInputDialog>
#include <QRegularExpression>
#include <QStack>
#include <QMenuBar>
#include <QAction>
#include <QListWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), display(new QLineEdit(this)) {
    setupUI();
}

MainWindow::~MainWindow() {
    // 自动释放内存
}

void MainWindow::setupUI() {
    setWindowTitle("Multi-Mode Calculator");

    // 设置显示区域
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setStyleSheet("QLineEdit {"
                           "    background-color: #f0f0f0; "
                           "    font-size: 24px; "
                           "    padding: 10px; "
                           "    border: 2px solid #ccc; "
                           "    border-radius: 5px; "
                           "} ");

    // 菜单栏
    QMenuBar *menuBar = this->menuBar();
    QMenu *modeMenu = menuBar->addMenu(tr("Mode"));
    QAction *standardMode = new QAction(tr("Standard"), this);
    QAction *scientificMode = new QAction(tr("Scientific"), this);
    QAction *programmerMode = new QAction(tr("Programmer"), this);
    QAction *dateMode = new QAction(tr("Date"), this);
    QAction *conversionMode = new QAction(tr("Currency/Capacity Conversion"), this);

    modeMenu->addAction(standardMode);
    modeMenu->addAction(scientificMode);
    modeMenu->addAction(programmerMode);
    modeMenu->addAction(dateMode);
    modeMenu->addAction(conversionMode);

    connect(standardMode, &QAction::triggered, this, &MainWindow::setStandardMode);
    connect(scientificMode, &QAction::triggered, this, &MainWindow::setScientificMode);
    connect(programmerMode, &QAction::triggered, this, &MainWindow::setProgrammerMode);
    connect(dateMode, &QAction::triggered, this, &MainWindow::setDateMode);
    connect(conversionMode, &QAction::triggered, this, &MainWindow::setConversionMode);

    // 历史记录按钮
    QAction *viewHistoryAction = new QAction(tr("View History"), this);
    menuBar->addAction(viewHistoryAction);
    connect(viewHistoryAction, &QAction::triggered, this, &MainWindow::showHistoryDialog);


    // 清除历史记录
    QAction *clearHistoryAction = new QAction(tr("Clear History"), this);
    menuBar->addAction(clearHistoryAction);
    connect(clearHistoryAction, &QAction::triggered, this, &MainWindow::clearHistory);

    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QGridLayout *buttonLayout = new QGridLayout;

    modeWidget = new QStackedWidget(this);
    mainLayout->addWidget(display);
    mainLayout->addWidget(modeWidget);

    // 设置模式切换界面
    setupStandardMode();
    setupScientificMode();
    setupProgrammerMode();
    setupDateMode();
    setupConversionMode();

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

// 在mainwindow.cpp中实现记录历史的函数

// 在保存历史记录时，保存当前模式
void MainWindow::addToHistory(const QString &expr, double result) {
    CalculationHistory history;
    history.expression = expr;
    history.result = result;
    history.mode = currentMode;  // 使用当前模式，而不是固定模式

    historyList.append(history);  // 添加到历史记录列表
}


// 显示历史记录的对话框
// 显示历史记录的对话框
void MainWindow::showHistoryDialog() {
    // 创建历史记录对话框
    QDialog *historyDialog = new QDialog(this);
    historyDialog->setWindowTitle(tr("History"));

    QVBoxLayout *layout = new QVBoxLayout(historyDialog);

    // 创建历史记录列表
    QListWidget *historyListWidget = new QListWidget(historyDialog);
    layout->addWidget(historyListWidget);

    // 创建并填充历史记录
    for (const CalculationHistory &history : historyList) {
        // 将表达式、结果和模式拼接为一个字符串
        QString historyItemText = QString("Expression: %1\nResult: %2\nMode: %3")
                                      .arg(history.expression)
                                      .arg(history.result)
                                      .arg(history.mode);

        historyListWidget->addItem(historyItemText);  // 添加到列表中
    }

    // 创建并连接按钮：重用选中的表达式
    QPushButton *reuseButton = new QPushButton(tr("Use Selected Expression"), historyDialog);
    layout->addWidget(reuseButton);

    connect(reuseButton, &QPushButton::clicked, this, [this, historyListWidget]() {
        QListWidgetItem *selectedItem = historyListWidget->currentItem();
        if (selectedItem) {
            // 获取选中的表达式（只取第一行）
            QString selectedExpression = selectedItem->text().split("\n").first().remove("Expression: ");

            // 恢复选择的表达式
            display->setText(selectedExpression);

            // 获取历史记录中的模式并切换到对应模式
            QString selectedMode = selectedItem->text().split("\n").last().remove("Mode: ");
            if (selectedMode == "Standard") {
                setStandardMode();
            } else if (selectedMode == "Scientific") {
                setScientificMode();
            } else if (selectedMode == "Programmer") {
                setProgrammerMode();
            } else if (selectedMode == "Date") {
                setDateMode();
            } else if (selectedMode == "Conversion") {
                setConversionMode();
            }
        }
    });

    // 显示历史记录对话框
    historyDialog->exec();
}


// 清除历史记录
void MainWindow::clearHistory() {
    historyList.clear();  // 清空历史记录
    QMessageBox::information(this, tr("History Cleared"), tr("All history records have been cleared."));
}




// 设置货币与容量转换模式
void MainWindow::setupConversionMode() {

    QWidget *conversionWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(conversionWidget);

    // 货币转换界面
    QWidget *currencyWidget = new QWidget(this);
    QVBoxLayout *currencyLayout = new QVBoxLayout(currencyWidget);

    QHBoxLayout *currencyInputLayout = new QHBoxLayout;
    currencyInputLayout->addWidget(new QLabel("Amount:"));
    QLineEdit *currencyAmount = new QLineEdit(currencyWidget);
    currencyInputLayout->addWidget(currencyAmount);
    currencyLayout->addLayout(currencyInputLayout);

    QHBoxLayout *currencyChoiceLayout = new QHBoxLayout;
    currencyChoiceLayout->addWidget(new QLabel("From:"));
    QComboBox *fromCurrencyComboBox = new QComboBox(currencyWidget);
    fromCurrencyComboBox->addItems({"USD", "EUR", "CNY"});  // 可扩展
    currencyChoiceLayout->addWidget(fromCurrencyComboBox);
    currencyChoiceLayout->addWidget(new QLabel("To:"));
    QComboBox *toCurrencyComboBox = new QComboBox(currencyWidget);
    toCurrencyComboBox->addItems({"USD", "EUR", "CNY"});  // 可扩展
    currencyChoiceLayout->addWidget(toCurrencyComboBox);
    currencyLayout->addLayout(currencyChoiceLayout);

    QPushButton *currencyConvertButton = new QPushButton("Convert", currencyWidget);
    connect(currencyConvertButton, &QPushButton::clicked, this, [this, currencyAmount, fromCurrencyComboBox, toCurrencyComboBox]() {
        double amount = currencyAmount->text().toDouble();
        QString fromCurrency = fromCurrencyComboBox->currentText();
        QString toCurrency = toCurrencyComboBox->currentText();

        double result = convertCurrency(amount, fromCurrency, toCurrency);
        display->setText(QString::number(result));
    });
    currencyLayout->addWidget(currencyConvertButton);

    layout->addWidget(currencyWidget);

    // 容量转换界面
    QWidget *capacityWidget = new QWidget(this);
    QVBoxLayout *capacityLayout = new QVBoxLayout(capacityWidget);

    QHBoxLayout *capacityInputLayout = new QHBoxLayout;
    capacityInputLayout->addWidget(new QLabel("Amount:"));
    QLineEdit *capacityAmount = new QLineEdit(capacityWidget);
    capacityInputLayout->addWidget(capacityAmount);
    capacityLayout->addLayout(capacityInputLayout);

    QHBoxLayout *capacityChoiceLayout = new QHBoxLayout;
    capacityChoiceLayout->addWidget(new QLabel("From:"));
    QComboBox *fromCapacityComboBox = new QComboBox(capacityWidget);
    fromCapacityComboBox->addItems({"L", "mL", "Gal"});  // 可扩展
    capacityChoiceLayout->addWidget(fromCapacityComboBox);
    capacityChoiceLayout->addWidget(new QLabel("To:"));
    QComboBox *toCapacityComboBox = new QComboBox(capacityWidget);
    toCapacityComboBox->addItems({"L", "mL", "Gal"});  // 可扩展
    capacityChoiceLayout->addWidget(toCapacityComboBox);
    capacityLayout->addLayout(capacityChoiceLayout);

    QPushButton *capacityConvertButton = new QPushButton("Convert", capacityWidget);
    connect(capacityConvertButton, &QPushButton::clicked, this, [this, capacityAmount, fromCapacityComboBox, toCapacityComboBox]() {
        double amount = capacityAmount->text().toDouble();
        QString fromUnit = fromCapacityComboBox->currentText();
        QString toUnit = toCapacityComboBox->currentText();

        double result = convertCapacity(amount, fromUnit, toUnit);
        display->setText(QString::number(result));
    });
    capacityLayout->addWidget(capacityConvertButton);

    layout->addWidget(capacityWidget);

    modeWidget->addWidget(conversionWidget);
}

// 设置货币转换
double MainWindow::convertCurrency(double amount, const QString &fromCurrency, const QString &toCurrency) {
    QMap<QString, QMap<QString, double>> exchangeRates;
    exchangeRates["USD"]["EUR"] = 0.85;
    exchangeRates["EUR"]["USD"] = 1.18;
    exchangeRates["USD"]["CNY"] = 6.5;
    exchangeRates["CNY"]["USD"] = 0.15;

    if (fromCurrency == toCurrency) {
        return amount;
    }

    if (exchangeRates.contains(fromCurrency) && exchangeRates[fromCurrency].contains(toCurrency)) {
        return amount * exchangeRates[fromCurrency][toCurrency];
    } else {
        QMessageBox::warning(this, "Error", "Unsupported currency conversion.");
        return 0;
    }
}

double MainWindow::convertCapacity(double amount, const QString &fromUnit, const QString &toUnit) {
    QMap<QString, double> conversionFactors = {
        {"L", 1.0},     // 升 (L)
        {"mL", 1000.0}, // 毫升 (mL)，1 升 = 1000 毫升
        {"Gal", 0.264172} // 加仑 (Gal)，1 升 = 0.264172 加仑
    };

    if (fromUnit == toUnit) {
        return amount;
    }

    if (conversionFactors.contains(fromUnit) && conversionFactors.contains(toUnit)) {
        // 正确的转换逻辑：直接按比例计算
        if (fromUnit == "L" && toUnit == "mL") {
            return amount * conversionFactors["mL"];  // 1 L = 1000 mL
        }
        if (fromUnit == "mL" && toUnit == "L") {
            return amount / conversionFactors["mL"];  // 1000 mL = 1 L
        }
        if (fromUnit == "L" && toUnit == "Gal") {
            return amount * conversionFactors["Gal"];  // 1 L = 0.264172 Gal
        }
        if (fromUnit == "Gal" && toUnit == "L") {
            return amount / conversionFactors["Gal"];  // 1 Gal = 3.78541 L
        }
        // 其他转换逻辑
        return amount * conversionFactors[fromUnit] / conversionFactors[toUnit];
    } else {
        QMessageBox::warning(this, "Error", "Unsupported unit conversion.");
        return 0;
    }
}





void MainWindow::setupStandardMode() {

    QWidget *standardWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(standardWidget);

    QStringList buttons = {"7", "8", "9", "/", "<-",
                           "4", "5", "6", "*","-",
                           "1", "2", "3", "+","",
                           "0", ".", "=", };

    int pos = 0;
    for (const QString &buttonText : buttons) {
        QPushButton *button = new QPushButton(buttonText, this);
        layout->addWidget(button, pos / 5, pos % 5);
        connect(button, &QPushButton::clicked, this, &MainWindow::on_button_clicked);
        pos++;
    }

    modeWidget->addWidget(standardWidget);
}

void MainWindow::setupScientificMode() {

    QWidget *scientificWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(scientificWidget);

    QStringList buttons = {"sin", "cos", "tan", "log", "ln", "x²", "√", "1/x", "=","<-"};

    int pos = 0;
    for (const QString &buttonText : buttons) {
        QPushButton *button = new QPushButton(buttonText, this);
        layout->addWidget(button, pos / 4, pos % 4);
        connect(button, &QPushButton::clicked, this, &MainWindow::on_button_clicked);
        pos++;
    }

    modeWidget->addWidget(scientificWidget);
}

void MainWindow::setupProgrammerMode() {

    QWidget *programmerWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(programmerWidget);

    QStringList buttons = {"Bin", "Oct", "Dec", "Hex", "&", "|", "^", "<<", ">>", "=","<-"};

    // 添加十进制转二进制按钮
    QPushButton *decimalToBinaryButton = new QPushButton(tr("Dec to Bin"), this);
    layout->addWidget(decimalToBinaryButton, 3, 0, 1, 2);  // 将按钮放在适当的位置
    connect(decimalToBinaryButton, &QPushButton::clicked, this, &MainWindow::on_decimalToBinary_clicked);

    int pos = 0;
    for (const QString &buttonText : buttons) {
        QPushButton *button = new QPushButton(buttonText, this);
        layout->addWidget(button, pos / 4, pos % 4);
        connect(button, &QPushButton::clicked, this, &MainWindow::on_button_clicked);
        pos++;
    }

    modeWidget->addWidget(programmerWidget);
}

// 十进制转二进制按钮点击处理函数
void MainWindow::on_decimalToBinary_clicked() {
    bool ok;
    int decimalValue = QInputDialog::getInt(this, tr("Enter Decimal Number"), tr("Decimal:"), 0, -2147483647, 2147483647, 1, &ok);

    if (ok) {
        QString binaryString = QString::number(decimalValue, 2); // 十进制转二进制
        display->setText(binaryString); // 显示结果
    }
}


void MainWindow::setupDateMode() {

    QWidget *dateWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(dateWidget);

    QPushButton *addButton = new QPushButton(tr("Add Days"), this);
    QPushButton *diffButton = new QPushButton(tr("Date Difference"), this);

    layout->addWidget(display);
    layout->addWidget(addButton);
    layout->addWidget(diffButton);

    connect(addButton, &QPushButton::clicked, this, [this]() {
        QDate currentDate = QDate::fromString(display->text(), "yyyy-MM-dd");
        int daysToAdd = 10;
        QDate result = currentDate.addDays(daysToAdd);
        display->setText(result.toString("yyyy-MM-dd"));
    });

    connect(diffButton, &QPushButton::clicked, this, [this]() {
        QDate date1 = QDate::fromString(display->text(), "yyyy-MM-dd");
        bool ok;
        QString secondDate = QInputDialog::getText(this, tr("Enter Second Date"), tr("Date (yyyy-MM-dd):"));
        QDate date2 = QDate::fromString(secondDate, "yyyy-MM-dd");

        if (date1.isValid() && date2.isValid()) {
            int daysDiff = date1.daysTo(date2);
            display->setText(QString::number(daysDiff) + tr(" days"));
        } else {
            QMessageBox::warning(this, tr("Invalid Date"), tr("Please enter a valid date."));
        }
    });

    modeWidget->addWidget(dateWidget);
}

void MainWindow::on_button_clicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();

        if (buttonText == "=") {
            on_equal_clicked();
        } else if (buttonText == "<-") {
            on_clear_clicked();
        } else {
            expression += buttonText;
            display->setText(expression);
        }
    }
}
void MainWindow::on_equal_clicked() {
    // 假设 calculate() 函数返回计算结果
    QString expr = display->text();  // 获取当前显示框中的表达式

    if (expr.isEmpty()) {
        return;  // 如果表达式为空，直接返回
    }

    // 计算结果（假设使用 calculate() 方法进行计算）
    double result = calculate(expr);

    // 显示计算结果
    display->setText(QString::number(result));

    // 保存历史记录，传递当前的模式
    addToHistory(expr, result);

    // 清空当前输入
    expression.clear();
}



void MainWindow::on_clear_clicked() {
    expression.clear();
    display->clear();
}

double MainWindow::calculate(const QString &expr) {
    // Standard Mode: basic operations
    if (expr.contains("+") || expr.contains("-") || expr.contains("*") || expr.contains("/")) {
        QStack<double> values;
        QStack<QChar> ops;
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
        return values.isEmpty() ? 0 : values.top();
    }
    // 科学计算模式：sin, cos, tan, log, ln, x², √, 1/x
    if (expr.startsWith("sin")) {
        QString angle = expr.mid(3);
        return sin(angle.toDouble());
    }
    if (expr.startsWith("cos")) {
        QString angle = expr.mid(3);
        return cos(angle.toDouble());
    }
    if (expr.startsWith("tan")) {
        QString angle = expr.mid(3);
        return tan(angle.toDouble());
    }
    if (expr.startsWith("log")) {
        QString value = expr.mid(3);
        return log10(value.toDouble()); // 以10为底的对数
    }
    if (expr.startsWith("ln")) {
        QString value = expr.mid(2);
        return log(value.toDouble()); // 自然对数
    }
    if (expr.startsWith("x²")) {
        QString value = expr.mid(2);
        return pow(value.toDouble(), 2); // 平方
    }
    if (expr.startsWith("√")) {
        QString value = expr.mid(1);
        return sqrt(value.toDouble()); // 平方根
    }
    if (expr.startsWith("1/x")) {
        QString value = expr.mid(3);
        return 1.0 / value.toDouble(); // 倒数
    }

    // 处理程序员模式按位运算
    if (expr.contains("&") || expr.contains("|") || expr.contains("^") || expr.contains("<<") || expr.contains(">>")) {
        // 先处理左移和右移操作符（<< 和 >>）
        QStringList tokens;
        if (expr.contains("<<") || expr.contains(">>")) {
            tokens = expr.split(QRegularExpression("\\s*(<<|>>|&|\\||\\^)\\s*"));
        } else {
            tokens = expr.split(QRegularExpression("\\s*[&|^]\\s*"));
        }
        bool ok1, ok2;
        qDebug() << "Expression: " << expr;
        qDebug() << "Tokens: " << tokens;
        int operand1 = tokens[0].toInt(&ok1, 10);  // 使用10进制解析
        int operand2 = tokens[1].toInt(&ok2, 10);  // 使用10进制解析

        if (ok1 && ok2) {
            if (expr.contains("&")) return operand1 & operand2;
            if (expr.contains("|")) return operand1 | operand2;
            if (expr.contains("^")) return operand1 ^ operand2;
            if (expr.contains("<<")) return operand1 << operand2;
            if (expr.contains(">>")) return operand1 >> operand2;
        }
    }






    // 转换功能
    if (expr.startsWith("Bin")) {
        return expr.mid(3).toInt(nullptr, 2); // 转换为二进制
    }
    if (expr.startsWith("Oct")) {
        return expr.mid(3).toInt(nullptr, 8); // 转换为八进制
    }
    if (expr.startsWith("Dec")) {
        return expr.mid(3).toInt(nullptr, 10); // 转换为十进制
    }
    if (expr.startsWith("Hex")) {
        return expr.mid(3).toInt(nullptr, 16); // 转换为十六进制
    }

    return 0;
}
// 按钮点击处理函数

void MainWindow::setStandardMode() {
     currentMode = "Standard";
    modeWidget->setCurrentIndex(0);
}

void MainWindow::setScientificMode() {
      currentMode = "Scientific";
    modeWidget->setCurrentIndex(1);
}

void MainWindow::setProgrammerMode() {
      currentMode = "Programmer";
    modeWidget->setCurrentIndex(2);
}

void MainWindow::setDateMode() {
     currentMode = "Date";
    modeWidget->setCurrentIndex(3);
}

// 切换到货币与容量转换模式
void MainWindow::setConversionMode() {
    currentMode = "Conversion";
    modeWidget->setCurrentIndex(4);
}

