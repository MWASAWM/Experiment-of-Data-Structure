#include "normalui_experimentresult.h"
#include "ui_normalui_experimentresult.h"
#include <QFile>
#include <QProcess>

NormalUI_ExperimentResult::NormalUI_ExperimentResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalUI_ExperimentResult)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);


    series=new QLineSeries();
    chart = new QChart();
    axisX = new QValueAxis;
    axisY = new QValueAxis;
    QFont font("苹方 常规",14,QFont::Normal,false);
    QFont labelfont("苹方 常规",12,QFont::Normal,false);
    //建立图表及其各项细节
    chart->legend()->setAlignment(Qt::AlignRight);

    chart->legend()->setFont(font);

    axisX->setRange(0, 600);
    axisX->setLabelFormat("%.1f");
    axisX->setGridLineVisible(false);
    axisX->setTickCount(11);
    //axisX->setMinorTickCount(4);

    axisY->setRange(0,100);
    axisY->setLabelFormat("%d");
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


    axisX->setTitleFont(QFont("苹方 常规",10, QFont::Normal, true));
    axisY->setTitleFont(QFont("苹方 常规",10, QFont::Normal, true));
    axisX->setTitleText("质量数(m/z)");
    axisY->setTitleText("百分比(%)");
    axisX->setLabelsFont(labelfont);
    axisY->setLabelsFont(labelfont);



    //series->setUseOpenGL(true);

    //色谱图
    series2=new QLineSeries();
    chart2 = new QChart();
    axisX2 = new QValueAxis;
    axisY2 = new QValueAxis;


    //建立图表及其各项细节
    chart2->legend()->setAlignment(Qt::AlignRight);

    chart2->legend()->setFont(font);

    axisX2->setRange(0, 30);
    axisX2->setLabelFormat("%d");
    axisX2->setGridLineVisible(false);
    axisX2->setTickCount(11);
    //axisX->setMinorTickCount(4);

    axisY2->setRange(0,1000);
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

    axisX2->setTitleFont(QFont("苹方 常规",10, QFont::Normal, true));
    axisY2->setTitleFont(QFont("苹方 常规",10, QFont::Normal, true));
    axisX2->setTitleText("时间/min");
    axisY2->setTitleText("响应值");
    axisX2->setLabelsFont(labelfont);
    axisY2->setLabelsFont(labelfont);

    testview=new ChartView(chart,this);
    testview->setRenderHint(QPainter::Antialiasing);

    testview2=new ChartView(chart2,this);
    testview2->setRenderHint(QPainter::Antialiasing);

    testview->setStyleSheet("background-color:white");
    testview2->setStyleSheet("background-color:white");

    testview->setGeometry(0,0,800,650);
    testview2->setGeometry(0,0,800,650);
    testview2->hide();


    SearchResultTimer=new QTimer();

    connect(SearchResultTimer,&QTimer::timeout,this,&NormalUI_ExperimentResult::SearchPerS);
    //SearchResultTimer->start(1000);


    fakeDataTimer= new QTimer;

    connect(fakeDataTimer,&QTimer::timeout,this,&NormalUI_ExperimentResult::fakeData);




    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    series->setUseOpenGL();


}

NormalUI_ExperimentResult::~NormalUI_ExperimentResult()
{
    delete ui;
}

void NormalUI_ExperimentResult::on_pushButton_5_clicked()
{

    this->hide();
}

void NormalUI_ExperimentResult::on_CS_clicked()
{
    testview2->show();
    testview->hide();
    testview2->setGeometry(0,0,800,650);

}

void NormalUI_ExperimentResult::on_MS_clicked()
{
    testview->show();
    testview->setGeometry(0,0,800,650);
    testview2->hide();
}

void NormalUI_ExperimentResult::on_pushButton_4_clicked()
{

    QFile SearchResult("c:/NIST17/MSSEARCH/SRCRESLT.TXT");
    if(SearchResult.exists())
    SearchResult.remove();

    QFile filelocate("c:/mymsds/filespec.fil");
    filelocate.open(QIODevice::WriteOnly|QIODevice::Text);
    filelocate.write("c:/mymsds/data/datafile.txt OVERWRITE");
    filelocate.close();
    QProcess p;
    p.setWorkingDirectory("C:/NIST17/MSSEARCH/");
    p.start("cmd");
    p.waitForStarted();
    p.write("NISTMS$.EXE /PAR=2\r\n");
    p.closeWriteChannel();
    p.waitForFinished();
    SearchResultTimer->start(1000);
}

void NormalUI_ExperimentResult::SearchPerS()
{

    QFile SearchResult("c:/NIST17/MSSEARCH/SRCRESLT.TXT");
    QFile SearchReady("c:/NIST17/MSSEARCH/SRCREADY.TXT");
    if(SearchReady.exists())
    {
    if(SearchResult.open(QIODevice::ReadOnly|QIODevice::Text))

    {
    SearchResultTimer->stop();
    QTextStream in(&SearchResult);
    ui->tableWidget->setRowCount(0);
    int rowcount=0;
    in.readLine();
    while(!in.atEnd())
    {
        QString line=in.readLine();
        int a= line.indexOf("<<");
        int b= line.indexOf(">>");

        qDebug()<<line.mid(a+2,b-a-2);

        line=line.mid(b+2);

        int c=line.indexOf("<<");
        int d=line.indexOf(">>");
        qDebug()<<line.mid(c+2,d-c-2);


        int e=line.indexOf("Prob: ");
        int f=line.indexOf("; CAS:");

        qDebug()<<line.mid(e+6,f-e-6);


        ui->tableWidget->setRowCount(rowcount+1);
        ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(line.mid(c+2,d-c-2)));
        ui->tableWidget->setItem(rowcount,1,new QTableWidgetItem(line.mid(e+6,f-e-6)+"%"));

        rowcount++;




    }
    }
    }



}

void NormalUI_ExperimentResult::on_Compare_clicked()
{
    testview->setGeometry(0,0,800,325);
    testview2->setGeometry(0,325,800,325);
    testview->show();
    testview2->show();
};

void NormalUI_ExperimentResult::fakeData()
{
    QList<QPointF> CSarray;


    for(int i=0;i<33;i++)
    {
     int a=qrand()%30;
      CSarray<<QPointF(i*30+a,0)<<QPointF(i*30+a,qrand()%3)<<QPointF(i*30+a,0);



    }

    CSarray<<QPointF(69,0)<<QPointF(69,100)<<QPointF(69,0);
    CSarray<<QPointF(119,0)<<QPointF(119,40-qrand()%2)<<QPointF(119,0);
    CSarray<<QPointF(131,0)<<QPointF(131,20-qrand()%2)<<QPointF(131,0);
    CSarray<<QPointF(169,0)<<QPointF(169,28-qrand()%2)<<QPointF(169,0);
    CSarray<<QPointF(181,0)<<QPointF(181,6-qrand()%2)<<QPointF(181,0);
    CSarray<<QPointF(220,0)<<QPointF(220,6-qrand()%2)<<QPointF(220,0);
    CSarray<<QPointF(231,0)<<QPointF(231,5-qrand()%2)<<QPointF(231,0);
    series->replace(CSarray);

    if(i%10==0)
    series2->append(QPointF(1.0/6,qrand()%100+400));
    i++;

}
void NormalUI_ExperimentResult::faketimerstart()
{
    fakeDataTimer->start(1000);
}

void NormalUI_ExperimentResult::faketimerstop()
{
    fakeDataTimer->stop();
    series->clear();
    series2->clear();
}
