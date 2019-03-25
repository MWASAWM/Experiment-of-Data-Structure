#ifndef SIGCOLLETFORM_H
#define SIGCOLLETFORM_H

#include <QWidget>
#include <QDialog>
#include <QTimer>
#include "chartview.h"
#include "callout.h"
#include "setdialog.h"
#include "crcchecksum.h"
#include "dataacquirethread.h"
#include "searchpeak.h"


#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarCategoryAxis>

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class SigColletForm;
}

class SigColletForm : public QWidget
{
    Q_OBJECT

public:
    explicit SigColletForm(QWidget *parent = 0);
    ~SigColletForm();




public slots:



private slots:


private:


};

#endif // SIGCOLLETFORM_H
