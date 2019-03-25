#ifndef NORMALUI_CHOSEMENTHOD_H
#define NORMALUI_CHOSEMENTHOD_H

#include "chosementhod_editmenthod.h"

#include <QDir>

#include <QWidget>
#include <QDirIterator>
#include <QFile>

namespace Ui {
class NormalUI_ChoseMenthod;
}

class NormalUI_ChoseMenthod : public QWidget
{
    Q_OBJECT

public:
    explicit NormalUI_ChoseMenthod(QWidget *parent = nullptr);
    ~NormalUI_ChoseMenthod();
    void updateTop();

signals:
    void PutinSignal(QString Menthod);

    void MenthodSelectedSignal(QString Menthod);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


private:
    void RenewTable();

    Ui::NormalUI_ChoseMenthod *ui;

    ChoseMenthod_EditMenthod *EditMenthod;

    QDir dir;

    QStringList filter;

    QStringList menthodNameList;

    QFileInfoList MenthodList;


};

#endif // NORMALUI_CHOSEMENTHOD_H
