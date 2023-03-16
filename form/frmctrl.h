#ifndef TEST_H
#define TEST_H

#include <QWidget>

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
    void initStyle();
    void initForm();
    void getQssColor(const QString &qss, const QString &flag, QString &color);
    void getQssColor(const QString &qss, QString &textColor,
                     QString &panelColor, QString &borderColor,
                     QString &normalColorStart, QString &normalColorEnd,
                     QString &darkColorStart, QString &darkColorEnd,
                     QString &highColor);
};

#endif // TEST_H
