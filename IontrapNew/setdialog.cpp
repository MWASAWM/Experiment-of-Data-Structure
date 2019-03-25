#include "setdialog.h"
#include "ui_setdialog.h"
#include <QWidget>
#include <QComboBox>
#include <QDebug>
#include <QLineEdit>
#include <QFileDialog>
#include <QSpinBox>




SetDialog::SetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetDialog)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    insertRow(0);

}

SetDialog::~SetDialog()
{
    delete ui;
}

void SetDialog::on_Add_clicked()
{



    if(ui->tableWidget->rowCount()>8)

    {
        return;
    }

    int isinsert=ui->tableWidget->currentRow();

    if(isinsert==-1)
    {
        int rowcount=ui->tableWidget->rowCount();
        insertRow(rowcount);
    }

    else
    {
        int rowcount=isinsert+1;
        insertRow(rowcount);

    }
}

void SetDialog::on_pushButton_clicked()
{

    int module[50][50];
    int time[50][50];
    para=new SetParameter();
    for(int i=0;i<ui->tableWidget->rowCount();i++)
        for (int j=5;j<ui->tableWidget->columnCount();j++)
    {
            QWidget *widget=ui->tableWidget->cellWidget(i,j);
            QComboBox *combox=qobject_cast<QComboBox*>(widget);
            module[i][j]=combox->currentIndex();


    }

    for(int i=0;i<ui->tableWidget->rowCount();i++)
        for (int j=1;j<3;j++)
    {

            time[i][j]=ui->tableWidget->item(i,j)->text().toInt();


    }

    para->count=ui->tableWidget->rowCount();


    for(int i=0;i<para->count;i++)
    {
        para->length[i]=ui->tableWidget->item(i,2)->text().toInt()-ui->tableWidget->item(i,1)->text().toInt();
        para->SW[i]=ui->tableWidget->item(i,3)->text().toInt();
        para->EW[i]=ui->tableWidget->item(i,4)->text().toInt();
        para->ionmodule=module[i][5];
        para->scanmoudle=module[i][6];

    }

    para->Ionsave=ui->IonSave->text().toInt();
    para->PreIonTime=static_cast<int>(ui->PreIonTime->text().toDouble());
    para->ScanRate=ui->ScanRate->text().toInt();


    this->setPara(para);
    delete para;
    this->accept();
}

void SetDialog::on_pushButton_2_clicked()
{
    this->reject();
}

void SetDialog::on_Delete_clicked()
{
    int removefucus=ui->tableWidget->currentRow();
    if(removefucus!=-1)
    {
        ui->tableWidget->removeRow(removefucus);
    }

}

void SetDialog::on_OpenMenthod_clicked()
{
    QFileDialog *a=new QFileDialog(this);
    a->setDirectory("d:/Menthod/");
    a->setNameFilter("Menthod(*.mth)");
    if(a->exec()==QDialog::Accepted)
    {
        qDebug()<<a->selectedFiles()[0];
        QString path=a->selectedFiles()[0];
        QFile mth(path);

    }

}

void SetDialog::insertRow(int rowcount)
{

    ui->tableWidget->insertRow(rowcount);
    QLineEdit *lineedit=new QLineEdit;
    if(ui->tableWidget->rowCount()==1)
    {
        lineedit->setText("溶剂延迟");
        lineedit->setEnabled(false);
    }
    lineedit->setStyleSheet("QLineEdit{border:none;\
    font: 11pt '苹方 常规';}");

    ui->tableWidget->setCellWidget(rowcount,0,lineedit);

    QSpinBox *spinbox[4];

    for(int i=0;i<4;i++)
    {
    spinbox[i]=new QSpinBox();
    spinbox[i]->setStyleSheet("QSpinBox::up-button { width: 0px;height: 0px;}"\
                           "QSpinBox::down-button { width: 0px;height: 0px;}\
                           QSpinBox{border-color: rgb(177, 177, 177);\
                           font: 11pt '苹方 常规';}");

    spinbox[i]->setRange(0,100);
    ui->tableWidget->setCellWidget(rowcount,i+1,spinbox[i]);
    }

    QComboBox *combox=new QComboBox;
    QComboBox *combox2=new QComboBox;
    combox->addItem("EI_fixed");
    combox->addItem("EI_AGC");
    combox2->addItem("FullScan");
    combox2->addItem("MS/MS");

    ui->tableWidget->setCellWidget(rowcount,5,combox);
    ui->tableWidget->setCellWidget(rowcount,6,combox2);

}

void SetDialog::readmth(QString path)
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



    int tmp[5]={0};
    tmp[0]=menthod.SixWayVavle;
    tmp[1]=menthod.Detector;
    tmp[2]=menthod.Diverter;
    tmp[3]=menthod.Probe;
    tmp[4]=menthod.EnrichmentTube;

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


    delete[]  ltmdata;
}
