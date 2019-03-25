#ifndef NORMALUI_EXPERIMENTRESULT_H
#define NORMALUI_EXPERIMENTRESULT_H

#include <QWidget>
#include <QtCharts>
#include <chartview.h>
#include <QTimer>

namespace Ui {
class NormalUI_ExperimentResult;
}

class NormalUI_ExperimentResult : public QWidget
{
    Q_OBJECT

public:
    explicit NormalUI_ExperimentResult(QWidget *parent = nullptr);
    ~NormalUI_ExperimentResult();


    void fakeData();

    void faketimerstart();

    void faketimerstop();

private slots:
    void on_pushButton_5_clicked();

    void on_CS_clicked();

    void on_MS_clicked();

    void on_pushButton_4_clicked();

    void SearchPerS();

    void on_Compare_clicked();

private:
    Ui::NormalUI_ExperimentResult *ui;

    //图1
        QLineSeries *series;
        QChart *chart;
        QValueAxis *axisX;
        QValueAxis *axisY;

    //图2
       // QScatterSeries *series2;
        QLineSeries *series2;
        QChart *chart2;
        QValueAxis *axisX2;
        QValueAxis *axisY2;

        ChartView *testview;
        ChartView *testview2;


        QProcess *search;

        QTimer *SearchResultTimer;

        QTimer *fakeDataTimer;


        int i;


};

#endif // NORMALUI_EXPERIMENTRESULT_H
