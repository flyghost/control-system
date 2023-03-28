#include "frmmusicplayer.h"
#include "ui_frmmusicplayer.h"
#include <QDebug>
#include "messagedispatcher.h"

frmMusicPlayer::frmMusicPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmMusicPlayer)
{
    ui->setupUi(this);

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));

    for (int i = 1; i <= 45; i++) {
        ui->listWidget->addItem(QString("music num : %1").arg(i));
        this->itemAllNum++;
    }

    ui->curMusicText->setTextSize(20);
//    ui->curMusicText->setInterval(15);
//    ui->curMusicText->setMouseHoverStop(true);
    ui->curMusicText->setText("未选取音乐!");
    ui->curMusicText->setForeground(QColor(0, 191, 255));
    ui->curMusicText->setBackground(QColor(234, 247, 255));
    ui->curMusicText->setMoveStyle(TextMoveWidget::MoveStyle_LeftAndRight);
//    ui->curMusicText->resize(this->width(), 400 + 10);
    ui->curMusicText->setMinimumHeight(22);

//    MessageDispatcher::instance().registerReceiver(this);
}



frmMusicPlayer::~frmMusicPlayer()
{
    delete ui;
}

void frmMusicPlayer::itemClicked(QListWidgetItem *item)
{
    // 处理点击事件
//    qDebug() << "select aaaa" << item->text() << endl;
    ui->curMusicText->setText(item->text());
    this->itemSelect = item;

    this->itemIndex = ui->listWidget->row(item);
}

void frmMusicPlayer::sendIdString(int id, QString str)
{
    struct MyStruct
    {
        int id;
        QString name;
    };

    QByteArray byteArray;
    MyStruct myStruct;
    myStruct.id = id;
    myStruct.name = str;

    qDebug() << "send id" << myStruct.id;
    qDebug() << "send string" << myStruct.name;

    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << myStruct.id << myStruct.name;

    stream.device()->seek(0);

    MessageDispatcher::instance().dispatchMessage(byteArray);
}

void frmMusicPlayer::on_btnMusicUpdata_clicked()
{
//    QListWidgetItem *item = ui->listWidget->currentItem();

    sendIdString(MSG_BTN_MUSIC_UPDATE, QString("music update"));
}

void frmMusicPlayer::on_btnMusicPlay_clicked()
{  
    sendIdString(MSG_BTN_MUSIC_PLAY, QString("music play"));
}

void frmMusicPlayer::on_btnMusicStop_clicked()
{
    sendIdString(MSG_BTN_MUSIC_STOP, QString("music stop"));
}

void frmMusicPlayer::on_btnMusicLast_clicked()
{
    itemIndex = itemIndex ? itemIndex-- : itemAllNum;
    ui->listWidget->setCurrentRow(this->itemIndex);

    sendIdString(MSG_BTN_MUSIC_LAST, QString("music last"));
}

void frmMusicPlayer::on_btnMusicNext_clicked()
{
    sendIdString(MSG_BTN_MUSIC_NEXT, QString("music next"));
}
