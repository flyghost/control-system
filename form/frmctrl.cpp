#include "frmctrl.h"
#include "ui_frmctrl.h"
#include "iconhelper.h"
#include "quihelper.h"
#include <QDebug>

frmCtrl::frmCtrl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmCtrl)
{
    ui->setupUi(this);

    this->initStyle();
    this->initForm();

//    ui->stackedWidget->setStyleSheet("QLabel{font:60px;}");

}

frmCtrl::~frmCtrl()
{
    delete ui;
}

void frmCtrl::initForm()
{
    //设置无边框
    QUIHelper::setFramelessForm(this);

    QFont font;
    font.setPixelSize(25);

    //ui->stackedWidget->setStyleSheet("QLabel{font:60px;}");

    QSize icoSize(32, 32);
    int icoWidth = 85;
}

void frmCtrl::getQssColor(const QString &qss, const QString &flag, QString &color)
{
    int index = qss.indexOf(flag);
    if (index >= 0) {
        color = qss.mid(index + flag.length(), 7);
    }
    //qDebug() << TIMEMS << flag << color;
}

void frmCtrl::getQssColor(const QString &qss, QString &textColor, QString &panelColor,
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
void frmCtrl::initStyle()
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
    file.close();
}
