#ifndef FRMMUSICPLAYER_H
#define FRMMUSICPLAYER_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class frmMusicPlayer;
}

class frmMusicPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit frmMusicPlayer(QWidget *parent = nullptr);
    ~frmMusicPlayer();

private:
    Ui::frmMusicPlayer *ui;
    QListWidgetItem *itemSelect;
    QListWidgetItem *itemPlaying;
    int itemAllNum;
    int itemIndex;
    void sendIdString(int id, QString str);

private slots:
    void on_btnMusicUpdata_clicked();
    void on_btnMusicPlay_clicked();
    void on_btnMusicStop_clicked();
    void on_btnMusicLast_clicked();
    void on_btnMusicNext_clicked();
    void itemClicked(QListWidgetItem *item);
};

#endif // FRMMUSICPLAYER_H
