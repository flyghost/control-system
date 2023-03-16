#include "frmmain.h"
#include "quihelper.h"
#include "ui_frmmain.h"
#include <QtCore>
#include <QtGui>

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif

#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
#include <QtCore5Compat>
#endif

#pragma execution_character_set("utf-8")

frmMain::frmMain(QWidget *parent) : QMainWindow(parent), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->initForm();
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::initForm()
{
    ui->rbtn1->setChecked(true);
    ui->ck2->setChecked(true);
    ui->ck3->setCheckState(Qt::PartiallyChecked);

    ui->textEdit->setText("www.creekwater.cn");
    ui->treeWidget->expandAll();

    int rowHeight = 23;
    ui->tableWidget->horizontalHeader()->setFixedHeight(rowHeight);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(rowHeight);

    //加载鼠标右键菜单翻译文件
    QTranslator *translator1 = new QTranslator(qApp);
    if (translator1->load(":/qm/qt_zh_CN.qm")) {
        qApp->installTranslator(translator1);
    }

    //加载富文本框鼠标右键菜单翻译文件
    QTranslator *translator2 = new QTranslator(qApp);
    if (translator2->load(":/qm/widgets.qm")) {
        qApp->installTranslator(translator2);
    }

    on_btnStyle1_clicked();
}

void frmMain::on_btnStyle1_clicked()
{
    QUIHelper::loadStyle(":/qss/lightblue.css");
}

void frmMain::on_btnStyle2_clicked()
{
    QUIHelper::loadStyle(":/qss/flatgray.css");
}

void frmMain::on_btnStyle3_clicked()
{
    QUIHelper::loadStyle(":/qss/blacksoft.css");
}

void frmMain::on_btnInfo_clicked()
{
    //QFileDialog::getOpenFileName(this, "", "", "", 0, QFileDialog::DontUseNativeDialog);
    //QFileDialog::getExistingDirectory(0, "", "", QFileDialog::DontUseNativeDialog);
}

