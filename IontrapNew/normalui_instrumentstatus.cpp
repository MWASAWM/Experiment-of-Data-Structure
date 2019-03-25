#include "normalui_instrumentstatus.h"
#include "ui_normalui_instrumentstatus.h"
#include "instruomentpara.h"


NormalUI_InstrumentStatus::NormalUI_InstrumentStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalUI_InstrumentStatus)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    this->setFixedSize(1024,768);
    ui->groupBox->setGeometry(12,70,1000,600);
    ui->groupBox_2->setGeometry(12,70,1000,600);
    ui->groupBox_3->setGeometry(12,70,1000,600);
    ui->groupBox_2->hide();
    ui->groupBox_3->hide();
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&NormalUI_InstrumentStatus::renew);
    timer->start(1000);

}

NormalUI_InstrumentStatus::~NormalUI_InstrumentStatus()
{
    delete ui;
}



void NormalUI_InstrumentStatus::on_pushButton_clicked()
{

    ui->pushButton->setChecked(true);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->groupBox_2->hide();
    ui->groupBox_3->hide();
    ui->groupBox->show();

}
void NormalUI_InstrumentStatus::on_pushButton_2_clicked()
{
    ui->pushButton_2->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton->setChecked(false);
    ui->groupBox->hide();
    ui->groupBox_3->hide();
    ui->groupBox_2->show();

}

void NormalUI_InstrumentStatus::on_pushButton_3_clicked()
{
    ui->pushButton_3->setChecked(true);
    ui->pushButton_2->setChecked(false);
    ui->pushButton->setChecked(false);
    ui->groupBox->hide();
    ui->groupBox_2->hide();
    ui->groupBox_3->show();


}

void NormalUI_InstrumentStatus::renew()
{
    ui->SixWayValve->setText(SixWayVavle);
    ui->EnrichmentTube->setText(EnrichmentTube);
    ui->Probe->setText(Probe);
    ui->Diverter->setText(Diverter);
    ui->LTM->setText(LTMTemperature);

    ui->MultiplierVoltage->setText(MultiplierTubeVoltage);
    ui->FilamentCurrent->setText(FilamentCurrent);


    ui->Vacuum->setText(Vacuum);
    ui->Flow->setText(flowspeed1);


}

void NormalUI_InstrumentStatus::on_pushButton_4_clicked()
{
    this->hide();
}
