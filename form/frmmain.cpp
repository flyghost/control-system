#pragma execution_character_set("utf-8")

#include "frmmain.h"
#include "ui_frmmain.h"
#include "iconhelper.h"
#include "quihelper.h"
#include <QDebug>

frmMain::frmMain(QWidget *parent) : QWidget(parent), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->initForm();
    this->initStyle();
}

frmMain::~frmMain()
{
    delete ui;
}

bool frmMain::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->widgetTitle) {
        if (event->type() == QEvent::MouseButtonDblClick) {
            on_btnMenu_Max_clicked();
        }
    }
    return QWidget::eventFilter(watched, event);
}

void frmMain::getQssColor(const QString &qss, const QString &flag, QString &color)
{
    int index = qss.indexOf(flag);
    if (index >= 0) {
        color = qss.mid(index + flag.length(), 7);
    }
    //qDebug() << TIMEMS << flag << color;
}

void frmMain::getQssColor(const QString &qss, QString &textColor, QString &panelColor,
                          QString &borderColor, QString &normalColorStart, QString &normalColorEnd,
                          QString &darkColorStart, QString &darkColorEnd, QString &highColor)
{
    getQssColor(qss, "TextColor:", textColor);
    getQssColor(qss, "PanelColor:", panelColor);
    getQssColor(qss, "BorderColor:", borderColor);
    getQssColor(qss, "NormalColorStart:", normalColorStart);
    getQssColor(qss, "NormalColorEnd:", normalColorEnd);
    getQssColor(qss, "DarkColorStart:", darkColorStart);
    getQssColor(qss, "DarkColorEnd:", darkColorEnd);
    getQssColor(qss, "HighColor:", highColor);
}

void frmMain::initForm()
{
    //设置无边框
    QUIHelper::setFramelessForm(this);
    //设置图标
    IconHelper::setIcon(ui->labIco, 0xf29a, 30);
    IconHelper::setIcon(ui->btnMenu_Min, 0xf068);
    IconHelper::setIcon(ui->btnMenu_Max, 0xf067);
    IconHelper::setIcon(ui->btnMenu_Close, 0xf00d);

    //ui->widgetMenu->setVisible(false);
    ui->widgetTitle->setProperty("form", "title");
    //关联事件过滤器用于双击放大
    ui->widgetTitle->installEventFilter(this);
    ui->widgetTop->setProperty("nav", "top");

    QFont font;
    font.setPixelSize(25);
    ui->labTitle->setFont(font);
    ui->labTitle->setText("人流量控制系统");
    this->setWindowTitle(ui->labTitle->text());

    ui->stackedWidget->setStyleSheet("QLabel{font:60px;}");

    QSize icoSize(32, 32);
    int icoWidth = 85;

    //设置顶部导航按钮
    // QList<QAbstractButton *> tbtns = ui->widgetTop->findChildren<QAbstractButton *>();
    // foreach (QAbstractButton *btn, tbtns) {
    //     btn->setIconSize(icoSize);
    //     btn->setMinimumWidth(icoWidth);
    //     btn->setCheckable(true);
    //     connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    // }

    // ui->btnMain->click();

    // ui->widgetLeftMain->setProperty("flag", "left");
    ui->widgetLeftConfig->setProperty("flag", "left");
    ui->page1->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(60));
    ui->page2->setStyleSheet(QString("QWidget[flag=\"left\"] QAbstractButton{min-height:%1px;max-height:%1px;}").arg(25));
}

void frmMain::initStyle()
{
    //加载样式表
    QString qss;
    QFile file(":/qss/blacksoft.css");
    if (file.open(QFile::ReadOnly)) {
        qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(paletteColor));
        qApp->setStyleSheet(qss);
        file.close();
    }

    //先从样式表中取出对应的颜色
    QString textColor, panelColor, borderColor, normalColorStart, normalColorEnd, darkColorStart, darkColorEnd, highColor;
    getQssColor(qss, textColor, panelColor, borderColor, normalColorStart, normalColorEnd, darkColorStart, darkColorEnd, highColor);

    //将对应颜色设置到控件
    this->borderColor = highColor;
    this->normalBgColor = normalColorStart;
    this->darkBgColor = panelColor;
    this->normalTextColor = textColor;
    this->darkTextColor = normalTextColor;
}

// void frmMain::buttonClick()
// {
//     QAbstractButton *b = (QAbstractButton *)sender();
//     QString name = b->text();

//     QList<QAbstractButton *> tbtns = ui->widgetTop->findChildren<QAbstractButton *>();
//     foreach (QAbstractButton *btn, tbtns) {
//         btn->setChecked(btn == b);
//     }

//     if (name == "主界面") {
//         ui->stackedWidget->setCurrentIndex(0);
//     } else if (name == "系统设置") {
//         ui->stackedWidget->setCurrentIndex(1);
//     } else if (name == "警情查询") {
//         ui->stackedWidget->setCurrentIndex(2);
//     } else if (name == "调试帮助") {
//         ui->stackedWidget->setCurrentIndex(3);
//     } else if (name == "用户退出") {
//         exit(0);
//     }
// }

void frmMain::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void frmMain::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(QUIHelper::getScreenRect());
    }

    this->setProperty("canMove", max);
    max = !max;
}

void frmMain::on_btnMenu_Close_clicked()
{
    close();
}

