#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class frmCtrl;
}

class frmCtrl : public QWidget
{
    Q_OBJECT

public:
    explicit frmCtrl(QWidget *parent = nullptr);
    ~frmCtrl();

private:
    Ui::frmCtrl *ui;
    QString borderColor;
    QString normalBgColor;
    QString darkBgColor;
    QString normalTextColor;
    QString darkTextColor;
    void initForm();
    void appendLog(const QString &flag);

private slots:
    void onMessageReceived(const QByteArray& message);
};

#endif // TEST_H
