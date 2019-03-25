#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStringList>
#include <QDataStream>

#include <QFileDialog>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

#include <QtWidgets/QListWidgetItem>
#include "setdialog.h"
#include "chartview.h"
#include "callout.h"
#include <QTimer>
#include <QList>
#include <QPointF>
#include <QFile>
#include <QtNetwork>

#include <messagedialog.h>
#include <QtVirtualKeyboard>

#include "instruomentpara.h"

#include "crcchecksum.h"

#include <dataacquirethread.h>

#include <QDockWidget>

#include <instruction.h>




using namespace std;

QString InsNumber;
QString CheckResult;

//主动上传第一命令组
//0x01
QString SixWayVavle ;//通阀
QString Detector ;//到探测器（气质接口）
QString Diverter ;//分流器
QString Probe ;//探头
QString EnrichmentTube; //富集管
QString LTMTemperature; //LTM柱

//0x03

QString MultiplierTubeVoltage;//富集管高压
QString FilamentCurrent;//灯丝电流
QString BiasVoltage;//BIAS高压


//0x05

QString Vacuum;

QString PumpSpeed;
QString PumpCurrent;
QString PumpVoltage;
QString PumpElecTemperature;
QString PumpVacuum;

//参数控制
QString flowspeed1;
QString flowspeed2;
QString pressure1;
QString pressure2;
QString pressure3;
QString ActiveTime;

QString ErrorCode;

//参数控制返回消息
QString InsFirstCode[5];
QString InsSecondCode[5];
int insFailCount[5];
QString InsMenthodCode;
int MenthodFailCount;
QString InsReady;
QString InsParaCode;

int Valve[4];
int Fan[3];
int SampalePump;

//手柄消息
lightingstatus samplestautslast=lightingoff;
lightingstatus samplestautsnow=lightingoff;
QString samplereply;

//波形参数
int ionMoudle;
int scanMoudle;
int rampTime;
int rampFreq;
int rampNumber;
int IonSaveVoltage;//离子化存储水平
int LowWeight;//Ramp 低电压
int HighWeight;//ramp高电压
int IonTime;//离子化时间
int ScanTime;//扫描时间
int AmpLow;
int AmpHigh;
int eGateTime;//电子门开启时间



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //显示连接提醒
    connectMessgae =new MessageDialog;
    connectMessgae->SetMessage("正在连接仪器中,请稍候");
    connectMessgae->setWindowFlag(Qt::WindowStaysOnTopHint);
    connectMessgae->show();

    //建立tcp链接
    server=new QTcpServer();
    server->listen(QHostAddress::Any,6000);
    connect(server,SIGNAL(newConnection()),this,SLOT(acceptConnnection()));



    connect(ui->inssetting,&QAction::triggered,this,&MainWindow::showMonitorWidget);
    connect(ui->Vaccum,&QAction::triggered,this,&MainWindow::showVacuumWidget);

    //callout初始化
    tip=nullptr;
    tip2=nullptr;

    //创建设置页面
    Dialog_Page=new SetDialog(this);
    connect(ui->newmenthod,&QAction::triggered,this,&MainWindow::ShowDialog);
    connect(Dialog_Page,&SetDialog::setPara,this,&MainWindow::getpara);


    //质谱图
    series=new QSplineSeries;
    chart = new QChart();
    axisX = new QValueAxis;
    axisY = new QValueAxis;

    //建立图表及其各项细节
    chart->legend()->setAlignment(Qt::AlignRight);
    QFont font("楷体",14,QFont::Normal,false);
    chart->legend()->setFont(font);

    axisX->setRange(0,1000);
    axisX->setLabelFormat("%.1f");
    axisX->setGridLineVisible(false);
    //axisX->setTickCount(21);
    //axisX->setMinorTickCount(4);

    axisY->setRange(0,70000);
    axisY->setLabelFormat("%.1f");
    axisY->setGridLineVisible(false);
    //axisY->setTickCount(13);
    //axisY->setMinorTickCount(4);
    //axisY->setLinePenColor(series->pen().color());

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // series->setColor("green");
    series->setName("质谱图");
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);


    axisX->setTitleFont(QFont("苹方 常规",8, QFont::Normal, true));
    axisY->setTitleFont(QFont("苹方 常规",8, QFont::Normal, true));
    axisX->setTitleText("质量数(m/z)");
    axisY->setTitleText("百分比(%)");

    //色谱图
    series2=new QScatterSeries();
    chart2 = new QChart();
    axisX2 = new QValueAxis;
    axisY2 = new QValueAxis;

    //建立图表及其各项细节
    chart2->legend()->setAlignment(Qt::AlignRight);
    chart2->legend()->setFont(font);

    axisX2->setRange(0, 2000);
    axisX2->setLabelFormat("%d");
    axisX2->setGridLineVisible(false);
    //axisX2->setTickCount(11);
    //axisX->setMinorTickCount(4);

    axisY2->setRange(0,70000);
    axisY2->setLabelFormat("%.1f");
    axisY2->setGridLineVisible(false);
    //axisY->setTickCount(13);
    //axisY->setMinorTickCount(4);
    //axisY->setLinePenColor(series->pen().color());

    chart2->addAxis(axisX2, Qt::AlignBottom);
    chart2->addAxis(axisY2, Qt::AlignLeft);

    //series2->setColor("blue");
    series2->setName("色谱图");
    chart2->addSeries(series2);
    series2->attachAxis(axisX2);
    series2->attachAxis(axisY2);


    axisX2->setTitleFont(QFont("苹方 常规", 8, QFont::Normal, true));
    axisY2->setTitleFont(QFont("苹方 常规",8 , QFont::Normal, true));
    axisX2->setTitleText("时间/min");
    axisY2->setTitleText("响应值");

    //设置质谱图中线条
    QPen pen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    series->setPen(pen);


    testview=new ChartView(chart);
    testview->setRenderHint(QPainter::Antialiasing);
    //ui->Layout->addWidget(testview);
    ui->MSlayout->addWidget(testview);

    testview2=new ChartView(chart2);
    testview2->setRenderHint(QPainter::Antialiasing);
    //ui->Layout2->addWidget(testview2);
    ui->CSlayout->addWidget(testview2);

    connect(series, SIGNAL(hovered(QPointF, bool)), this, SLOT(tipSlot(QPointF,bool)));
    connect(series2, SIGNAL(hovered(QPointF, bool)), this, SLOT(tipSlot2(QPointF,bool)));
   // connect(series2, SIGNAL(pressed(QPointF)), this, SLOT(showMS(QPointF)));




    //接收数据线程（未启用）
    searchpeak= new SearchPeak();


    PulseTimer=new QTimer();
    connect(PulseTimer,&QTimer::timeout,this,&MainWindow::PulseTimeOut);


    //数据接收和处理数组
    data=new int [40000];
    avedata=new int [40000];
    sumdata=new int [40000];

    //数据保存
    /*
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    QVector<double> indata;
    in>>indata;
    file.close();
    */


    ui->MSWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    ui->CSWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);

    addDockWidget(Qt::LeftDockWidgetArea, ui->MSWidget);
    addDockWidget(Qt::LeftDockWidgetArea, ui->CSWidget);

    ui->VacuumPumpWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    ui->MonitorWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    ui->dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);

    testview2->setMinimumSize(500,250);
    testview->setMinimumSize(500,250);

    addDockWidget(Qt::RightDockWidgetArea,ui->MonitorWidget);
    addDockWidget(Qt::RightDockWidgetArea,ui->VacuumPumpWidget);
    addDockWidget(Qt::RightDockWidgetArea, ui->dockWidget);

    ui->MonitorWidget->setMinimumSize(460,600);
    ui->VacuumPumpWidget->setMinimumSize(500,600);
    ui->dockWidget->setMinimumSize(500,600);

    tabifyDockWidget(ui->CSWidget,ui->MSWidget);
    tabifyDockWidget(ui->MonitorWidget,ui->VacuumPumpWidget);
    tabifyDockWidget(ui->VacuumPumpWidget,ui->dockWidget);




    //普通用户界面初始化
    normalUI=new NormalUI();
    normalUI->show();
    connect(normalUI,&NormalUI::showAdvanceUI,this,&MainWindow::showthisUI);
    connect(normalUI,&NormalUI::SetMenthodSignal,this,&MainWindow::setMenthodfromUI);

    //分子泵真空相关串口初始化
    vacSerial = new QSerialPort;
    vacTimer = new QTimer;
    connect(vacSerial,&QSerialPort::readyRead,this,&MainWindow::readData2vacrb);
    vacSerial->setPortName("COM4");
    vacSerial->setBaudRate(QSerialPort::Baud9600);
    vacSerial->setDataBits(QSerialPort::Data8);
    vacSerial->setParity(QSerialPort::NoParity);
    vacSerial->setStopBits(QSerialPort::OneStop);
    vacSerial->setFlowControl(QSerialPort::NoFlowControl);
    if(vacSerial->open(QIODevice::ReadWrite))
    {
    QString current="0010031002=?099\r";
    current=sendVacMessage(current.toStdString().c_str());
    if(current.mid(10,6).toInt()>0)
    ui->PumpStart->setText("分子泵关闭");
    connect(vacTimer,&QTimer::timeout,this,&MainWindow::vacRequest);
    vacTimer->start(1000);
    }


}
void MainWindow::vacRequest()
{

    QString pinamipre="@253PR1?;FF";
    sendGaugeMessage(pinamipre.toLatin1());

    QString rspeed="0010039802=?115\r";
    QString current="0010031002=?099\r";
    QString voltage="0010031302=?102\r";
    QString electemperature="0010032602=?106\r";
    QString bottomtemperature="0010033002=?101\r";
    QString motortemperature="0010034602=?108\r";


    rspeed=sendVacMessage(rspeed.toStdString().c_str());
    current=sendVacMessage(current.toStdString().c_str());
    voltage=sendVacMessage(voltage.toStdString().c_str());

    motortemperature=sendVacMessage(motortemperature.toStdString().c_str());
    bottomtemperature=sendVacMessage(bottomtemperature.toStdString().c_str());
    electemperature=sendVacMessage(electemperature.toStdString().c_str());

    rspeed=rspeed.mid(10,6);
    motortemperature=motortemperature.mid(10,6);
    bottomtemperature=bottomtemperature.mid(10,6);
    electemperature=electemperature.mid(10,6);
    current=current.mid(10,6);
    voltage=voltage.mid(10,6);

    bottomtemperature=tempDeleteZero(bottomtemperature);
    motortemperature=tempDeleteZero(motortemperature);
    electemperature=tempDeleteZero(electemperature);
    rspeed=spdDeleteZero(rspeed);
    voltage=voltageDeleteZero(voltage);
    current=currentDeleteZero(current);

    ui->pumpcurrent->setText(current);
    ui->pumpspeed->setText(rspeed);
    ui->pumpelectemp->setText(electemperature);
    ui->pumpvoltage->setText(voltage);


}
void MainWindow::readData2vacrb(void)
{
    switch (comSendStatus)
    {
    case pumpflag:

        if(vacSerial->isOpen())
        {
            QByteArray data = vacSerial->readAll();
            for(int i=0;i<data.size();i++) vacrb.putch(data[i]);
        }
        break;

    case gaugeflag:
        if(vacSerial->isOpen())
        {
        QByteArray data = vacSerial->readAll();
        QString pina=QString(data);
        completevacuum.append(pina);
        if(completevacuum.size()>=17)
        {
        ui->pumpvaccum->setText(completevacuum.mid(7,7));
        completevacuum.clear();
        }
        }
        break;

    case GCflag:
        if(vacSerial->isOpen())
        {
        QByteArray data = vacSerial->readAll();
        QString GCdata=QString(data);
        completeGC.append(GCdata);
        }
        if(completeGC.length()>=16)
        {

        int datalength=completeGC.mid(6,4).toInt(nullptr,16);
        if(completeGC.length()==datalength*2+14)
        {
            int datalength=completeGC.mid(6,4).toInt(nullptr,16);
            QByteArray check=QByteArray::fromHex(completeGC.toLatin1().data());
            for(i=0;i<datalength+4;i++)
            check[0]=check[0]+check[i+1];
            if(check[0]!=check[datalength+4+1])
                return;
            int ValveandFan;
            switch (completeGC.mid(0,6).toInt())

            {
            case 552201:
            break;
            case 552202:
            break;
            case 552203:
            break;
            case 552211:
            break;
            case 552212:
            break;
            case 552221:
            break;
            case 552222:
                SixWayVavle=completeGC.mid(10,4);
                Detector=completeGC.mid(14,4);
                Diverter=completeGC.mid(18,4);
                Probe=completeGC.mid(22,4);
                EnrichmentTube=completeGC.mid(26,4);
                LTMTemperature=completeGC.mid(30,4);
                flowspeed1=completeGC.mid(34,4);
                flowspeed2=completeGC.mid(38,4);
                pressure1=completeGC.mid(42,4);
                pressure2=completeGC.mid(46,4);
                pressure3=completeGC.mid(50,4);
                ValveandFan=completeGC.mid(54,2).toInt(nullptr,16);
                Valve[0]=ValveandFan&0x01;
                Valve[1]=ValveandFan>>1&0x01;
                Valve[2]=ValveandFan>>2&0x01;
                Valve[3]=ValveandFan>>3&0x01;
                Fan[0]=ValveandFan>>4&0x01;
                Fan[1]=ValveandFan>>5&0x01;
                Fan[2]=ValveandFan>>6&0x01;
                SampalePump=ValveandFan>>7&0x01;

            break;
            case 553301:
                samplestautsnow=static_cast<lightingstatus>(completeGC.mid(12,2).toInt(nullptr,16));
                if(samplestautsnow==lighting&&samplestautslast==lightingoff)
                {

                }

                break;
            case 553302:

                samplereply=completeGC.mid(10,2);
                break;

            }

        }

        }








        break;




    }


}
void MainWindow::sendGCMessage(QByteArray send)
{
    comSendStatus=GCflag;
    if(vacSerial->isOpen())
    vacSerial->write(send.toStdString().c_str());

}

void MainWindow::sendGaugeMessage(QByteArray send)
{
    comSendStatus=gaugeflag;
    if(vacSerial->isOpen())
    vacSerial->write(send.toStdString().c_str());
}


QString MainWindow::sendVacMessage(QString message)
{
    comSendStatus=pumpflag;
    QString res;
   // qDebug()<<"vacsend:"<<message;
     for(int i=0;i<2;i++)
    {
        vacrb.clear();
        if (vacSerial->isOpen()) vacSerial->write(message.toStdString().c_str());
        vacrb.waitforline(1000);
        if(vacrb.numLines() >= 1)
       {
            res = vacrb.getline();
           // qDebug()<<"vaceceive:"<<res;
            if(res != "") return res;
        }
    }
    return res;
}
void MainWindow::PulseTimeOut()
{
    PulseSocket->close();
    socket->close();
    ShowMessage("无心跳，socket连接已断开");
    qDebug()<<"无心跳，socket连接已断开";
    PulseTimer->stop();

}

void MainWindow::getarray(QList<QPointF> array)
{

    series->replace(array);

}
void MainWindow::insGrpFirst()
{

    QString moduleinstruction2="551002";

    QString moduleinstruction5="55100500080101000000000000CCCCAA";
                                              //这个1是第14位

    //0x01

    int Vavle = 100;//通阀
    int Detector = 100;//到探测器
    int Diverter = 100;//分流器
    int Probe = 100;//探头
    int EnrichmentTube =100; //富集管

    //0x03

    int MultiplierTubeVoltage=3000;
    int FilamentCurrent=200;
    int BiasVoltage=100;


    //0x05
    int flowspeed1=100;
    int flowspeed2=100;
    int ActiveTime=100;



    moduleinstruction5.replace(14,4,QString("%1").arg(flowspeed1,4,16,QLatin1Char('0')).toUpper());
    moduleinstruction5.replace(18,4,QString("%1").arg(flowspeed2,4,16,QLatin1Char('0')).toUpper());
    moduleinstruction5.replace(22,4,QString("%1").arg(ActiveTime,4,16,QLatin1Char('0')).toUpper());//k为int型或char型都可


    int tmp[5];
    tmp[0]=Vavle;
    tmp[1]=Detector;
    tmp[2]=Diverter;
    tmp[3]=Probe;
    tmp[4]=EnrichmentTube;


    ins.temperatureSet(tmp);


    int vol[3];
    vol[0]=MultiplierTubeVoltage;
    vol[1]=FilamentCurrent;
    vol[2]=BiasVoltage;

    ins.voltageSet(vol);



    menthod.HeatCount=1;
    menthod.Heat[0].EndTemperature=1;
    menthod.Heat[0].StorageTime=1;
    menthod.Heat[0].HeatRate=1;

    int N=menthod.HeatCount;

    int X=2*N;
    moduleinstruction2.append(QString("%1").arg(X*4+3,4,16,QLatin1Char('0')));
    moduleinstruction2.append("0101");
    moduleinstruction2.append(QString("%1").arg(X,2,16,QLatin1Char('0')));
    for(int i=0;i<X/2;i++)
    {
        int RiseTime=static_cast<int>(menthod.Heat[i].EndTemperature*1.0/menthod.Heat[i].HeatRate*600);
        moduleinstruction2.append(QString("%1").arg(RiseTime,4,16,QLatin1Char('0')));
        moduleinstruction2.append(QString("%1").arg(menthod.Heat[i].EndTemperature,4,16,QLatin1Char('0')));
        moduleinstruction2.append(QString("%1").arg(menthod.Heat[i].StorageTime*600,4,16,QLatin1Char('0')));
        moduleinstruction2.append(QString("%1").arg(menthod.Heat[i].EndTemperature,4,16,QLatin1Char('0')));
    }

    crcCheckSum crccheck;
    quint16 result2=crccheck.crc16ForModbus(QByteArray::fromHex(moduleinstruction2.mid(2,2*(8*N+9)).toLatin1().data()));
    moduleinstruction2.append(QString("%1").arg(result2,4,16,QLatin1Char('0')));
    moduleinstruction2.append("AA");

    qDebug()<<moduleinstruction2;

    int *ltmdata=new int[2*X+1];

    ltmdata[0]=X;

    for(int i=0;i<X/2;i++)
    {
        int RiseTime=static_cast<int>(menthod.Heat[i].EndTemperature*1.0/menthod.Heat[i].HeatRate*600);

        ltmdata[i+1]=RiseTime;
        ltmdata[i+2]=menthod.Heat[i].EndTemperature;
        ltmdata[i+3]=menthod.Heat[i].StorageTime*600;
        ltmdata[i+4]=menthod.Heat[i].EndTemperature;
    }

    qDebug()<<ins.LTMSet(X,ltmdata).toHex();

    delete[]  ltmdata;


}
void MainWindow::insGrpSecond()
{




}
void MainWindow::insGrpEighth()
{
    ionMoudle=1;
    scanMoudle=1;
    rampTime=200;
    rampFreq=100;
    rampNumber=100;

    IonSaveVoltage=800;
    IonTime=10;

    AmpLow=200;
    AmpHigh=500;

    eGateTime=200;
    LowWeight=1000;
    HighWeight=1500;

}


void MainWindow::AutoDataRequest()
{

    crcCheckSum check;
    QString Request[6];
    Request[0]=QString("5501010003010111CCCCAA");
    Request[1]=QString("5501030003010111CCCCAA");
    Request[2]=QString("5501050003010111CCCCAA");
    Request[3]=QString("5501060003010111CCCCAA");
    Request[4]=QString("5501800003010111CCCCAA");
    Request[5]=QString("5501900003010111CCCCAA");

    for(int i=0;i<6;i++)
    {
    QByteArray crcarray= QByteArray::fromHex(Request[i].mid(2,14).toLatin1().data());
    int ret=check.crc16ForModbus(crcarray);
    Request[i].replace(16,4,QString("%1").arg(ret,4,16,QLatin1Char('0')).toUpper());
    qDebug()<<Request[i];
   // SendInstrcution(Request[i]);
    }

}

void MainWindow::CommunicationTest()
{
    crcCheckSum crccheck;
    QString test="5550110003010111CCCCAA";
    QByteArray crcarray=QByteArray::fromHex(test.mid(2,14).toLatin1().data());
    int crc=check.crc16ForModbus(crcarray);
    test.replace(16,4,QString("%1").arg(crc,4,16,QLatin1Char('0')).toUpper());
    SendInstrcution(test);
}

void MainWindow::acceptConnnection()
{
    if(socketcount==0)
    {
    PulseSocket=server->nextPendingConnection();
    connect(PulseSocket,SIGNAL(readyRead()),this,SLOT(readPulse()));
    qDebug()<<"connected 0!";
    socketcount++;
    }
    else
    {
    socket=server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readclient()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(socketdisconnect()));
    server->close();
    qDebug()<<"connected 1!";
    socketcount=0;
    connectMessgae->SetMessage("仪器连接成功！");
    connectMessgae->show();
    }


}

void MainWindow::socketdisconnect()
{
    qDebug()<<"远程socket连接已断开";
    server->listen(QHostAddress::Any,6000);
}
void MainWindow::readclient()
{
    QByteArray str=socket->readAll();
    QString readdata = str.toHex().data();
    qDebug()<<"receive:"<<readdata;
    crcCheckSum check;
    int length=readdata.mid(6,4).toInt(nullptr,16);
    int ret=check.crc16ForModbus(QByteArray::fromHex(readdata.mid(2,8+length*2).toLatin1().data()));
    if(readdata.mid(10+length*2,4).toInt(nullptr,16)!=ret)
    {
        ShowMessage("CRC校验错误通讯失败");
        return;
    }
    if(readdata.startsWith("5520A0"))

    {

         qDebug()<<"WaringCode:"<<readdata.mid(14,4);
         return;
    }


    switch (readdata.left(6).toInt())
    {

    case 550180:
        InsNumber = readdata.mid(14,30);
       break;

    case 550190:
        CheckResult=readdata.mid(14,4);
        break;

    case 550101:
        SixWayVavle=readdata.mid(14,4);
        Detector=readdata.mid(18,4);
        Diverter=readdata.mid(22,4);
        Probe=readdata.mid(26,4);
        EnrichmentTube=readdata.mid(30,4);
        LTMTemperature=readdata.mid(34,4);


        break;


    case 550103:

        MultiplierTubeVoltage=readdata.mid(14,4);
        FilamentCurrent=readdata.mid(18,4);
        BiasVoltage=readdata.mid(22,4);
        break;


    case 550105 :
        PumpSpeed=readdata.mid(15,1);
        for(int i=17;i<(17+10);i=i+2) PumpSpeed.append(readdata.mid(i,1));
        PumpCurrent=readdata.mid(27,1);
        for(int i=29;i<(29+6);i=i+2) PumpCurrent.append(readdata.mid(i,1));
        PumpVoltage=readdata.mid(39,1);
        for(int i=37;i<(37+6);i=i+2) PumpVoltage.append(readdata.mid(i,1));
        PumpElecTemperature=readdata.mid(51,1);
        for(int i=45;i<(45+6);i=i+2) PumpElecTemperature.append(readdata.mid(i,1));
        PumpVacuum=readdata.mid(63,1);
        for(int i=53;i<(53+8);i=i+2) PumpVacuum.append(readdata.mid(i,1));

        ui->pumpcurrent->setText(PumpCurrent);
        ui->pumpspeed->setText(PumpSpeed);
        ui->pumpelectemp->setText(PumpElecTemperature);
        ui->pumpvoltage->setText(PumpVoltage);
        ui->pumpvaccum->setText(PumpVacuum);

        break;


    case 550106:
        ErrorCode=readdata.mid(14,4);
        break;

    case 551001 :
        InsFirstCode[0]=readdata.mid(14,2);
        if(InsFirstCode[0]=="12"&&insFailCount[0]<2)
        {
        insFailCount[0]++;
        SendPulseInstrcution("");
        }
        if(insFailCount[0]==2)
        {
            ShowMessage("设置失败");
            insFailCount[0]=0;
        }

        break;

    case 551002 :
        InsFirstCode[1]=readdata.mid(14,2);
        if(InsFirstCode[1]=="12"&&insFailCount[1]<2)
        {
        insFailCount[1]++;
        SendPulseInstrcution("");
        }
        if(insFailCount[1]==2)
        {
            ShowMessage("设置失败");
            insFailCount[1]=0;
        }
        break;

    case 551003 :
        InsFirstCode[2]=readdata.mid(14,2);
        if(InsFirstCode[2]=="12"&&insFailCount[2]<2)
        {
        insFailCount[2]++;
        SendPulseInstrcution("");
        }
        if(insFailCount[2]==2)
        {
            ShowMessage("设置失败");
            insFailCount[2]=0;
        }
        break;

    case 551005:
        InsFirstCode[4]=readdata.mid(14,2);
        if(InsFirstCode[4]=="12"&&insFailCount[4]<2)
        {
        insFailCount[4]++;
        SendPulseInstrcution("");
        }
        if(insFailCount[4]==2)
        {
            ShowMessage("设置失败");
            insFailCount[4]=0;
        }
        break;


    case 551011:
        InsSecondCode[0]=readdata.mid(14,2);
        break;


    case 551012:
        InsSecondCode[1]=readdata.mid(14,2);
        break;

    case 551013:
        InsSecondCode[2]=readdata.mid(14,2);
        break;

    case 551014:
        InsSecondCode[3]=readdata.mid(14,2);
        break;

    case 551015:
        InsSecondCode[4]=readdata.mid(14,2);
        break;

    case 551081:
        InsMenthodCode=readdata.mid(14,2);
        if(InsMenthodCode=="11")
        ShowMessage("方法设置成功");
        if(InsMenthodCode=="12"&&MenthodFailCount<2)
        {
        MenthodFailCount++;
        SendPulseInstrcution("");
        }
        if(MenthodFailCount==2)
        {
            ShowMessage("方法设置失败");
            MenthodFailCount=0;
        }
        break;

    case 551082:
        InsReady=readdata.mid(14,2);
        if(InsReady=="11")
        {

           ShowMessage("设备已经准备完成，可以开始实验");

        }

        break;


    }


}


void MainWindow::readPulse()
{

    QByteArray str=PulseSocket->readAll();
    PulseTimer->start(10000);
    int ValveandFan;
    QString readdata = str.toHex().data();
    qDebug()<<"Pulsereceive:"<<readdata;
    crcCheckSum check;
    int length=readdata.mid(6,4).toInt(nullptr,16);
    int ret=check.crc16ForModbus(QByteArray::fromHex(readdata.mid(2,8+length*2).toLatin1().data()));
    /*
     * int length2=str.at(3);
     * int ret2=check.crc16ForModbus(str.mid(1,4+length2));
    if((str[length2+5]*16+str[length2+6])!=ret2)
    {
        ShowMessage("CRC校验错误通讯失败");
        return;
    }
    */

    if(readdata.mid(10+length*2,4).toInt(nullptr,16)!=ret)
    {
        //ShowMessage("CRC校验错误通讯失败");
        return;
    }
    if(readdata.startsWith("5520A0"))

    {

         qDebug()<<"WaringCode:"<<readdata.mid(14,4);
         return;
    }


    switch (readdata.left(6).toInt())
    {


    case 552001:

        SixWayVavle=readdata.mid(14,4);
        Detector=readdata.mid(18,4);
        Diverter=readdata.mid(22,4);
        Probe=readdata.mid(26,4);
        EnrichmentTube=readdata.mid(30,4);
        LTMTemperature=readdata.mid(34,4);
        MultiplierTubeVoltage=readdata.mid(38,4);
        FilamentCurrent=readdata.mid(42,4);

        ui->SixWayValve_2->setText(SixWayVavle);
        ui->Detecor_2->setText(Detector);
        ui->Diverter_2->setText(Diverter);
        ui->Probe_2->setText(Probe);
        ui->EnrichmentTube_2->setText(EnrichmentTube);
        ui->LTM->setText(LTMTemperature);
        ui->TubeHighVoltageAcutal->setText(MultiplierTubeVoltage);
        ui->FilameCurrentAcutal->setText(FilamentCurrent);

        ValveandFan=readdata.mid(46,4).toInt(nullptr,16);
        Valve[0]=ValveandFan&0x01;
        Valve[1]=ValveandFan>>1&0x01;
        Valve[2]=ValveandFan>>2&0x01;
        Valve[3]=ValveandFan>>3&0x01;
        Fan[0]=ValveandFan>>4&0x01;
        Fan[1]=ValveandFan>>5&0x01;
        Fan[2]=ValveandFan>>6&0x01;
        SampalePump=ValveandFan>>7&0x01;
        break;

    case 552009:
        //气压未定

    case 552082:
        InsReady=readdata.mid(14,2);
        if(InsReady=="11")
        {
        currentStatus=IsReady;
        ui->ExperimentStart->setEnabled(true);
        }
        else
        {
        currentStatus=NotReady;
        }
        break;
    case 552081:
        /*
        int count1=str.at(3);
        int count2=str.at(4);
        int countall=count1*16*16+2*count2;
        */

        int  count=readdata.mid(6,4).toUShort(nullptr,16);
        int  present=readdata.mid(10,4).toUShort(nullptr,16);

        if(present!=FrameIndeed)
        {
            CSarray.append(QPointF(present,35000));
            series2->replace(CSarray);
            FrameIndeed=present;
            if(j%20==0&&j!=0)
            {
                for(int a=0;a<mth_period;a++)
                {
                   avedata[a]=sumdata[a]/20;
                   MSshow[j].append(QPointF(a, avedata[a]));
                }

            series->replace(MSshow[j]);
            }

            j++;
            n=0;
           }

        for(int i=0;i<(count-2)/2;i++)
        {

            data[n]=readdata.mid(14+4*i,4).toInt(nullptr,16);
            sumdata[n]+=data[n];
            MSarray[j].append(QPointF(n, data[n]));
            n++;

        }
        break  ;


    }
    if(readdata.left(6).toInt()!=552081)
     PulseSocket->write("ok");

}

void MainWindow::getpara(SetParameter *SetPara)
{


    ionMoudle=SetPara->ionmodule+1;
    scanMoudle=SetPara->scanmoudle+1;
    int period=SetPara->length[0];

    rampFreq=100;
    rampTime=200;
    rampNumber=period*60*1000/200;

    eGateTime=1000;

    HighWeight=SetPara->EW[0]*5;
    LowWeight=SetPara->SW[0]*5;
    IonTime =SetPara->PreIonTime;
    ScanTime=static_cast<int>((HighWeight-LowWeight)*1.0/SetPara->ScanRate*1000);
    AmpLow=0;
    AmpHigh=0;


}


void MainWindow::SendInstrcution(QString message)
{

    if(socket==nullptr)
        return;
    QByteArray sendmessage=QByteArray::fromHex(message.toLatin1().data());
    if(socket->isOpen())
    {
        socket->write(sendmessage);
        qDebug()<<"send:"<<sendmessage.toHex().toUpper();
        if(!socket->waitForReadyRead(1000))
        ShowMessage("通讯超时");
    }
}
void MainWindow::SendPulseInstrcution(QString message)
{
    if(PulseSocket==nullptr)
        return;
    QByteArray sendmessage=QByteArray::fromHex(message.toLatin1().data());
    if(PulseSocket->isOpen())
    {
        PulseSocket->write(sendmessage);
        qDebug()<<"Pulsesend:"<<sendmessage.toHex().toUpper();
        if(!PulseSocket->waitForReadyRead(1000))
        ShowMessage("主动信息上传超时");
    }
}

void MainWindow::on_MenthodSet_clicked()
{


    ionMoudle=1;
    scanMoudle=1;
    rampTime=200;
    rampFreq=100;
    rampNumber=100;

    IonSaveVoltage=800;
    IonTime=10;

    AmpLow=200;
    AmpHigh=500;

    eGateTime=200;
    LowWeight=1000;
    HighWeight=1500;

    int data[13];
    data[0]=ionMoudle;
    data[1]=scanMoudle;
    data[2]=rampTime;
    data[3]=rampFreq;
    data[4]=rampNumber;
    data[5]=IonSaveVoltage;
    data[6]=LowWeight;
    data[7]=HighWeight;
    data[8]=IonTime;
    data[9]=ScanTime;
    data[10]=AmpLow;
    data[11]=AmpHigh;
    data[12]=eGateTime;

    ins.menthodSet(data);
}

void MainWindow::tipSlot(QPointF position, bool isHovering)
{
    if (tip == nullptr)
        tip = new Callout(chart);
    if (isHovering) {
        tip->setText(QString("X: %1 \nY: %2 ").arg(position.x()).arg(position.y()));
        tip->setAnchor(position);
        tip->setZValue(11);
        tip->updateGeometry();
        tip->show();
    } else {
        tip->hide();
    }
}

void MainWindow::tipSlot2(QPointF position, bool isHovering)
{
    if (tip2 == nullptr)
        tip2 = new Callout(chart2);
    if (isHovering) {
        tip2->setText(QString("X: %1 \nY: %2 ").arg(position.x()).arg(position.y()));
        tip2->setAnchor(position);
        tip2->setZValue(11);
        tip2->updateGeometry();
        tip2->show();
    } else {
        tip2->hide();
    }
    qDebug()<<"showMS!";

    series->replace(MSarray[int(position.x())]);
}
/*
void MainWindow::showMS(QPointF position)
{

    qDebug()<<"showMS!";


}
*/
MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::tempDeleteZero(QString message)
{


    while(message.startsWith("0"))
    {
        message=message.mid(1);
    }
    return message;
}

QString MainWindow::spdDeleteZero(QString message)
{

    while(message.startsWith("0"))
    {
        message=message.mid(1);
    }
    if(message.isEmpty())

        message="0";

    return message;
}

QString MainWindow::voltageDeleteZero(QString message)
{


    while(message.startsWith("0"))
    {
        message=message.mid(1);

    }
    message.insert(2,".");
    return message;
}

QString MainWindow::currentDeleteZero(QString message)
{


   message.insert(4,".") ;

    while(message.startsWith("0"))
    {
        message=message.mid(1);

    }
    if(message.startsWith("."))
        message.insert(0,"0");
    return message;

}

QString MainWindow::showvaccum(QString message)
{
    QString a=message.mid(0,4);

    a.insert(1,".");
    int b = message.mid(4,2).toInt();
    b=b-18;
    message=QString("%1E%2").arg(a).arg(b);
    return message;

}

void MainWindow::ShowMessage(QString m)
{
    MessageDialog *messagedialog=new MessageDialog(this);

    messagedialog->SetMessage(m);
    messagedialog->setWindowFlag(Qt::WindowStaysOnTopHint);
    messagedialog->show();

}


void MainWindow::showthisUI()
{
    //this->setFixedSize(1024,768);;
    this->showMaximized();
    normalUI->hide();

}

void MainWindow::showMonitorWidget()
{
    addDockWidget(Qt::RightDockWidgetArea, ui->MonitorWidget);   
    tabifyDockWidget(ui->VacuumPumpWidget,ui->MonitorWidget);
    ui->MonitorWidget->show();
}
void MainWindow::showVacuumWidget()
{
    addDockWidget(Qt::RightDockWidgetArea, ui->VacuumPumpWidget);
    tabifyDockWidget(ui->MonitorWidget,ui->VacuumPumpWidget);
    ui->VacuumPumpWidget->show();
}

void MainWindow::ShowDialog()

{

    Dialog_Page->show();


}
void MainWindow::on_FilamentSwitch_clicked()
{
    QString FilamentSwitch=ins.filamentSwitchFirst.toHex();
}
void MainWindow::on_FilamentOn_clicked()
{
    QString FilamentSwitch=ins.filamentON.toHex();
    qDebug()<<FilamentSwitch;
}

void MainWindow::on_PumpStart_clicked()
{

    vacTimer->stop();

    if(ui->PumpStart->text()=="分子泵开启")
    {

        ui->PumpStart->setText("分子泵关闭");
        QTimer::singleShot(500,this,&MainWindow::sendPumpON);
    }
        else
    {
        ui->PumpStart->setText("分子泵开启");
        QTimer::singleShot(500,this,&MainWindow::sendPumpOFF);
    }

}

void MainWindow::sendPumpON()
{
    QString PumpStart="0011001006111111015\r";
    sendVacMessage(PumpStart);
    vacTimer->start();
}
void MainWindow::sendPumpOFF()
{
    QString PumpStop ="0011001006000000009\r";
    sendVacMessage(PumpStop);
    vacTimer->start();
}

void MainWindow::on_TempStart_clicked()
{

    QString TempStart=ins.temperatureON.toHex();
    QString TempStop =ins.temperatureOFF.toHex();

    if(ui->TempStart->text()=="温度开始")
    {
        ui->TempStart->setText("温度结束");
        SendInstrcution(TempStart);
     }
    else
    {
        ui->TempStart->setText("温度开始");
        SendInstrcution(TempStop);
    }
}

void MainWindow::on_ExperimentStart_clicked()
{

    if(ui->ExperimentStart->text()=="实验开始")
    {
        for(int i=0;i<40000;i++)
        {
        MSarray[i].clear();
        MSshow[i].clear();
        }
        vacTimer->stop();
        CSarray.clear();
        series->clear();
        series2->clear();
        j=0;
        n=0;
        ui->ExperimentStart->setText("实验结束");
        SendInstrcution(ins.testON.toHex());
    }

     else
    {
        ui->ExperimentStart->setText("实验开始");
        SendInstrcution(ins.testOFF.toHex());
        vacTimer->start();
    }
}



void MainWindow::on_TemperatureSave_clicked()
{

    int SixWayValve=ui->SixWayValve->text().toUShort();
    int Detector=ui->Detecor->text().toUShort();
    int Diverter=ui->Diverter->text().toUShort();
    int Probe=ui->Probe->text().toUShort();
    int EnrichmentTube=ui->EnrichmentTube->text().toUShort();
    int tmp[5];
    tmp[0]=SixWayValve;
    tmp[1]=Detector;
    tmp[2]=Diverter;
    tmp[3]=Probe;
    tmp[4]=EnrichmentTube;
    ins.temperatureSet(tmp);

    SendInstrcution(ins.temperatureSet(tmp).toHex().data());

}

void MainWindow::on_VoltageSet_clicked()
{

    int MultiplierTubeVoltage=ui->TubeHighVoltage->text().toUShort();//富集管高压
    int FilamentCurrent=ui->FilameCurrentSet->text().toUShort();//灯丝电流
    int BiasVoltage=ui->BIASVoltageSet->text().toUShort();//BIAS电压  

    int vol[3];
    vol[0]=MultiplierTubeVoltage;
    vol[1]=FilamentCurrent;
    vol[2]=BiasVoltage;

    SendInstrcution(ins.voltageSet(vol).toHex().data());

}

void MainWindow::on_EFCFlowSpeedDetermine_clicked()
{

}
void MainWindow::setMenthodADUI(QString path)
{

    QFile Menthod(path);
    Menthod.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream inStream(&Menthod);
    menthod.MenthodName=inStream.readLine();

    menthod.SixWayVavle=inStream.readLine().toInt();
    menthod.Detector=inStream.readLine().toInt();
    menthod.Diverter=inStream.readLine().toInt();
    menthod.Probe=inStream.readLine().toInt();
    menthod.EnrichmentTube=inStream.readLine().toInt();
    int heatcount=inStream.readLine().toInt();


    for(int i=0;i<heatcount;i++)
    {

       menthod.Heat[i].StageNumber=inStream.readLine().toInt();
       menthod.Heat[i].StartTime=inStream.readLine().toInt();
       menthod.Heat[i].EndTemperature=inStream.readLine().toInt();
       menthod.Heat[i].HeatRate=inStream.readLine().toInt();
       menthod.Heat[i].StorageTime=inStream.readLine().toInt();

    }

    int tmp[5];
    tmp[0]=menthod.SixWayVavle;
    tmp[1]=menthod.Detector;
    tmp[2]=menthod.Diverter;
    tmp[3]=menthod.Probe;
    tmp[4]=menthod.EnrichmentTube;

    SendInstrcution(ins.temperatureSet(tmp).toHex());

    int N=menthod.HeatCount;

    int *ltmdata=new int[2*N+1];

    ltmdata[0]=2*N;

    for(int i=0;i<2*N;i++)
    {
        int RiseTime=static_cast<int>(menthod.Heat[i].EndTemperature*1.0/menthod.Heat[i].HeatRate*600);
        ltmdata[i+1]=RiseTime;
        ltmdata[i+2]=menthod.Heat[i].EndTemperature;
        ltmdata[i+3]=menthod.Heat[i].StorageTime*600;
        ltmdata[i+4]=menthod.Heat[i].EndTemperature;
    }

    qDebug()<<ins.LTMSet(N,ltmdata).toHex();

    delete[] ltmdata;

}

void MainWindow::setMenthodfromUI(QString MenthodName)
{
    QString MenthodLocation="d:/menthod/"+MenthodName+".mth";
    setMenthodADUI(MenthodLocation);

}

void MainWindow::on_saveData_clicked()
{   
    savetoMatlab();
}

void MainWindow::on_pushButton_clicked()
{

    int data[14];
    data[0]=ionMoudle;
    data[1]=scanMoudle;
    for(int i=0;i<12;i++)
    {
    QString paraname="MthP"+QString::number(i);
    QLineEdit *lineedit= ui->dockWidget->findChild<QLineEdit*>(paraname);
    data[i+2]=lineedit->text().toUShort();
    }

    SendInstrcution(ins.menthodSet(data).toHex());
    mth_period=ui->MthP1->text().toUShort()*ui->MthP7->text().toUShort()/10;
    axisX->setRange(0,mth_period);


}

void MainWindow::savetoMatlab()
{
    QFile file("data");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    for(int i=0;i<mth_period;i++)
    out << avedata[i]<<endl;
    file.close();
    ShowMessage("保存成功");

}
