#ifndef NORMALUI_H
#define NORMALUI_H

#include <QWidget>
#include <normalui_chosementhod.h>
#include <normalui_instrumentstatus.h>
#include <normalui_historicaldata.h>
#include <normalui_experimentresult.h>
#include <QTimer>
#include <messagedialog.h>
#include "ui_top_para.h"

namespace Ui {
class NormalUI;
}

class NormalUI : public QWidget
{
    Q_OBJECT

public:
    explicit NormalUI(QWidget *parent = nullptr);
    ~NormalUI();

    void showMessage(QString mess);

signals:

    void startFakeData();

    void showAdvanceUI();

    void SetMenthodSignal(QString MenthodName);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void SetSelectedMenthodOnUi(QString MenthodName);

    void RenewDateTime();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::NormalUI *ui;
    NormalUI_ChoseMenthod *ChoseMenthod;
    NormalUI_InstrumentStatus *InstrumentStatus;
    NormalUI_HistoricalData *HistoricalData;
    NormalUI_ExperimentResult *ExperimentResult;

    QTimer *timer;
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yy.MM.dd hh:mm");



};

#endif // NORMALUI_H
