#include "normalui.h"
#include "ui_normalui.h"
#include <QDateTime>
#include <QProcess>

QString currentTime;
QString battery;
QString menthodName;
QString vacuum;

NormalUI::NormalUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalUI)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    timer=new QTimer(this);
    current_date_time = QDateTime::currentDateTime();
    current_date =current_date_time.toString("yy.MM.dd hh:mm");
    ui->Datetime->setText(current_date);

    ChoseMenthod = new NormalUI_ChoseMenthod();
    ChoseMenthod->hide();
    InstrumentStatus = new NormalUI_InstrumentStatus();
    InstrumentStatus->hide();
    HistoricalData=new NormalUI_HistoricalData();
    HistoricalData->hide();
    ExperimentResult =new NormalUI_ExperimentResult();
    ExperimentResult->hide();

    connect(this,&NormalUI::startFakeData,ExperimentResult,&NormalUI_ExperimentResult::faketimerstart);


    connect(ChoseMenthod,&NormalUI_ChoseMenthod::MenthodSelectedSignal,this,&NormalUI::SetSelectedMenthodOnUi);

    this->setFixedSize(1024,768);

    connect(timer,&QTimer::timeout,this,&NormalUI::RenewDateTime);
    timer->start(1000);



}

NormalUI::~NormalUI()
{
    delete ui;
}

void NormalUI::on_pushButton_clicked()
{

     ChoseMenthod->show();



}
void NormalUI::on_pushButton_3_clicked()
{
    ExperimentResult->show();

    ui->pushButton_4->setEnabled(true);

    emit startFakeData();
}
void NormalUI::on_pushButton_4_clicked()
{
    //ui->CurrentMenthodName->clear();
    ui->pushButton_4->setEnabled(false);
    showMessage("停止成功");
    ExperimentResult->faketimerstop();

}

void NormalUI::on_pushButton_5_clicked()
{
    HistoricalData->show();

}

void NormalUI::on_pushButton_6_clicked()

{

    InstrumentStatus->show();

}

void NormalUI::on_pushButton_8_clicked()
{
   /*
    QProcess p;
    p.start("cmd");
    p.waitForStarted();
    p.write("shutdown -s -t 00\r\n");
    p.closeWriteChannel();
    p.waitForFinished();

    QApplication::quit();
    */

}

void NormalUI::on_pushButton_9_clicked()
{

    emit showAdvanceUI();

}

void NormalUI::on_pushButton_10_clicked()
{
    QApplication::quit();
}


void NormalUI::SetSelectedMenthodOnUi(QString MenthodName)
{
    ui->CurrentMenthodName->setText(MenthodName);
    menthodName=MenthodName;
    ui->pushButton_3->setEnabled(true);

}

void NormalUI::RenewDateTime()
{

    current_date_time = QDateTime::currentDateTime();
    currentTime=current_date_time.toString("yy.MM.dd hh:mm");
    ui->Datetime->setText(currentTime);
    //ui->Battery->setText(battery);
    ui->Vacuum->setText(vacuum);
    ChoseMenthod->updateTop();
    //ui->CurrentMenthodName->setText(menthodName);
}

void NormalUI::showMessage(QString m)
{

    MessageDialog *message=new MessageDialog();
    message->SetMessage(m);
    message->show();


}
