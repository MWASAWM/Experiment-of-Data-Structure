#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QTimer>
#include "chartview.h"
#include "callout.h"
#include "setdialog.h"
#include "crcchecksum.h"
#include "searchpeak.h"
#include "normalui.h"
#include "menthodparameter.h"
#include "keyboard.h"

#include <QtCharts>
#include <QPen>

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <instruction.h>


#include <QSerialPort>
#include <QSerialPortInfo>
#include <ringbuffer.h>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Initailization();
    void SendInstrcution(QString message);
    void SendPulseInstrcution(QString message);

    QString tempDeleteZero(QString message);
    QString spdDeleteZero(QString message);
    QString voltageDeleteZero(QString message);
    QString currentDeleteZero(QString message);
    QString showvaccum(QString message);


    void getarray(QList<QPointF> CSarray);


public slots:

    void getpara(SetParameter* SetPara);

    void showthisUI();


    void CommunicationTest();

    void ShowDialog();

private slots:

    void insGrpFirst();
    void insGrpSecond();
    void insGrpEighth();

    void AutoDataRequest();

    void acceptConnnection() ;

    void readclient();

    void readPulse();

    void tipSlot(QPointF position, bool isHovering);

    void tipSlot2(QPointF position, bool isHovering);

    void socketdisconnect();

    void on_MenthodSet_clicked();

    void on_PumpStart_clicked();

    void on_TempStart_clicked();

    void on_ExperimentStart_clicked();

    void on_VoltageSet_clicked();

    void on_TemperatureSave_clicked();

    void PulseTimeOut();



    void showMonitorWidget();

    void showVacuumWidget();


    void on_FilamentOn_clicked();

    void on_EFCFlowSpeedDetermine_clicked();

    void ShowMessage(QString mess);



    void on_FilamentSwitch_clicked();


    void setMenthodfromUI(QString MenthodName);

    void setMenthodADUI(QString path);

    void readData2vacrb();

    void vacRequest();

    QString sendVacMessage(QString send);

    void  sendGCMessage(QByteArray send);

    void  sendGaugeMessage(QByteArray send);

    void sendPumpON();

    void sendPumpOFF();

    void on_saveData_clicked();

    void on_pushButton_clicked();

    void savetoMatlab();

private:

    Ui::MainWindow *ui;


//与下位机用以太网tcp/ip协议通讯，使用socket，上位机为server；
    QTcpServer *server;
    QTcpSocket *PulseSocket;
    QTcpSocket *socket;

//图1
    QSplineSeries *series;
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;

//图2
    QScatterSeries *series2;
    //QLineSeries *series2;
    QChart *chart2;
    QValueAxis *axisX2;
    QValueAxis *axisY2;

// chartview
    ChartView *testview;
    ChartView *testview2;

//数据呼出框
    Callout *tip;
    Callout *tip2;

//五秒钟超时时间的心跳定时器
    QTimer *PulseTimer;

    SetDialog *Dialog_Page;

//连接下位机消息框

    MessageDialog *connectMessgae;

    crcCheckSum check;

    QList<QPointF> MSarray[40000];
    QList<QPointF> MSshow[40000];
    QList<QPointF> CSarray;

    SearchPeak *searchpeak;

    NormalUI *normalUI;

    int *data;
    int *avedata;
    int *sumdata;

    int j=0;
    int i=0;
    int n;

    int socketcount=0;
    int FrameIndeed=1;
    
    MenthodParameter menthod;

    int  mth_period;

    MessageDialog *messdialog;

    //默认仪器状态:未准备
    enum InstrumentStatus{NotReady,IsReady};
    InstrumentStatus currentStatus=NotReady;

    //指令类定义
    Instruction ins;

    //分子泵串口相关声明定义
    QSerialPort *vacSerial;
    QTimer *vacTimer;
    RingBuffer vacrb;
    QString completevacuum;
    QString completeGC;
    enum COMSwitcn{pumpflag,gaugeflag,GCflag};
    COMSwitcn comSendStatus=pumpflag;



    KeyBoard *vkb;



};


#endif // MAINWINDOW_H
