#ifndef NORMALUI_HISTORICALDATA_H
#define NORMALUI_HISTORICALDATA_H

#include <QWidget>
#include <QDir>
#include <QDirIterator>

namespace Ui {
class NormalUI_HistoricalData;
}

class NormalUI_HistoricalData : public QWidget
{
    Q_OBJECT

public:
    explicit NormalUI_HistoricalData(QWidget *parent = nullptr);
    ~NormalUI_HistoricalData();

private slots:
    void on_pushButton_7_clicked();

    void RenewTable();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_SelectDate_clicked();

    void on_Reject_clicked();

    void on_Accept_clicked();

private:
    Ui::NormalUI_HistoricalData *ui;

    QDir dir;

    QStringList filter;

    QStringList DataNameList;

    QStringList DataBirthTimeList;

    QFileInfoList DataList;

    void  FindRecentFlie(int Day);

    QFileInfoList GetFileList();
};

#endif // NORMALUI_HISTORICALDATA_H
