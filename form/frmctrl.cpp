#include "frmctrl.h"
#include "ui_frmctrl.h"
#include "iconhelper.h"
#include "quihelper.h"
#include <QDebug>
#include "savelog.h"
#include "frmmusicplayer.h"

#include "messagedispatcher.h"

#pragma execution_character_set("utf-8")
frmCtrl::frmCtrl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmCtrl)
{
    ui->setupUi(this);
    this->initForm();

    ui->musicWidget->addWidget(new frmMusicPlayer);
    ui->errLedText->setStep(2);
//    ui->errLedText->setBackground(QColor(0, 255, 255));
    ui->errLedText->setForeground(QColor(111, 111, 255));
    ui->errLedText->setText("0x00");

    MessageDispatcher::instance().registerReceiver(this);
}

#define MSG_BTN_MUSIC_UPDATE        (1)
#define MSG_BTN_MUSIC_PLAY          (2)
#define MSG_BTN_MUSIC_STOP          (3)
#define MSG_BTN_MUSIC_LAST          (4)
#define MSG_BTN_MUSIC_NEXT          (5)

void frmCtrl::onMessageReceived(const QByteArray& message)
{
    QByteArray bytearray = message;
    QDataStream stream(&bytearray, QIODevice::ReadWrite);
//    quint16 value;
//    stream >> value;

    int id;
    QString name;

    stream >> id >> name;

    qDebug() << "receive music button clicked "<< id << "string is : " << name;
 }

frmCtrl::~frmCtrl()
{
    delete ui;
}

void frmCtrl::appendLog(const QString &flag)
{
    QString str2 = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString str3 = flag.isEmpty() ? "自动插入消息" : flag;
    QString msg = QString("[%2] : %3").arg(str2).arg(str3);

    ui->txtMain->append(msg);
}

void frmCtrl::initForm()
{
    //设置无边框
    QUIHelper::setFramelessForm(this);

    //设置图标
//    IconHelper::setIcon(ui->labIco, 0xf29a, 30);
    IconHelper::setIcon(ui->btnFreqDecrease, 0xf063);
    IconHelper::setIcon(ui->btnFreqIncrease, 0xf062);
    IconHelper::setIcon(ui->btnRangeDecrease, 0xf063);
    IconHelper::setIcon(ui->btnRangeIncrease, 0xf062);
//    IconHelper::setIcon(ui->btnMenu_Close, 0xf00d);


    QFont font;
    font.setPixelSize(25);

    //ui->stackedWidget->setStyleSheet("QLabel{font:60px;}");

    QSize icoSize(32, 32);
    int icoWidth = 85;

    SaveLog::Instance()->setUseContext(false);
        //设置文件存储目录
    SaveLog::Instance()->setPath(qApp->applicationDirPath() + "/log");

    ui->widgetIP->setIP("192.168.1.56");

    for (int i = 1; i <= 45; i++) {
        this->appendLog(QString(" %1 ").arg(i));
    }
}

