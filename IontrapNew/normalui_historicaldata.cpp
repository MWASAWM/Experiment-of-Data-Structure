#include "normalui_historicaldata.h"
#include "ui_normalui_historicaldata.h"
#include "QHeaderView"
#include "QTableWidget"
#include <QDebug>
#include <QDateTime>
#include <qalgorithms.h>
#include <QToolButton>


 bool SortDatetime(QFileInfo a,QFileInfo b)
{
    return a.birthTime()<b.birthTime();

}
NormalUI_HistoricalData::NormalUI_HistoricalData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalUI_HistoricalData)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1024,768);
    ui->tableWidget->setColumnWidth(0,150);
    ui->tableWidget->setColumnWidth(1,600);
    ui->tableWidget->setColumnWidth(2,250);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    dir=("d:/historicaldata");
    if(!dir.exists())
    {
        dir.mkdir("d:/historicaldata");
    }
    filter<<".data";
    RenewTable();

    ui->CalendarGroup->hide();
    ui->CalendarGroup->setGeometry(0,0,1024,768);
    QToolButton *toolbutton= ui->calendarWidget->findChild<QToolButton*>("qt_calendar_yearbutton");
    toolbutton->setDisabled(true);
}

NormalUI_HistoricalData::~NormalUI_HistoricalData()
{
    delete ui;
}

void NormalUI_HistoricalData::on_pushButton_7_clicked()
{
    this->hide();
}
void NormalUI_HistoricalData::RenewTable()
{


    ui->tableWidget->setRowCount(0);
    QDirIterator iter(dir,QDirIterator::Subdirectories);
    QFileInfoList filelist;
    filelist.clear();
    while (iter.hasNext())
    {
    iter.next();
    QFileInfo info=iter.fileInfo();

    if (info.isFile())
    {
     ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
     filelist.append(info);
     //DataNameList.append(info.fileName().remove(".data"));
     //DataBirthTimeList.append(info.birthTime().toString("yyyy-MM-dd hh:mm:ss"));

    }
    }
    /*
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
     ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
     ui->tableWidget->setItem(i,1,new QTableWidgetItem(DataNameList[i]));
     ui->tableWidget->setItem(i,2,new QTableWidgetItem(DataBirthTimeList[i]));

    }
    */

    qSort(filelist.begin(),filelist.end(),SortDatetime);
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
     ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
     ui->tableWidget->setItem(i,1,new QTableWidgetItem(filelist[i].fileName()));
     ui->tableWidget->setItem(i,2,new QTableWidgetItem(filelist[i].birthTime().toString("yyyy-MM-dd hh:mm:ss")));

    }
}



void NormalUI_HistoricalData::FindRecentFlie(int Day)
{

    ui->tableWidget->setRowCount(0);

    QFileInfoList filelist=GetFileList();

    QFileInfoList selectFileList;

    foreach(QFileInfo file,filelist)
    {
        if(file.birthTime()>QDateTime::currentDateTime().addDays(-Day))
        {
         selectFileList.append(file);
         ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        }

    }

    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
     ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
     ui->tableWidget->setItem(i,1,new QTableWidgetItem(selectFileList[i].fileName()));
     ui->tableWidget->setItem(i,2,new QTableWidgetItem(selectFileList[i].birthTime().toString("yyyy-MM-dd hh:mm:ss")));
    }

}

QFileInfoList NormalUI_HistoricalData::GetFileList()
{
    QDirIterator iter(dir,QDirIterator::Subdirectories);
    QFileInfoList filelist;
    filelist.clear();
    while (iter.hasNext())
    {
    iter.next();
    QFileInfo info=iter.fileInfo();

    if (info.isFile())
    {

     filelist.append(info);
    }
    }

    qSort(filelist.begin(),filelist.end(),SortDatetime);

    return filelist;

}

void NormalUI_HistoricalData::on_pushButton_clicked()
{
    FindRecentFlie(3);
}

void NormalUI_HistoricalData::on_pushButton_2_clicked()
{
    FindRecentFlie(7);
}

void NormalUI_HistoricalData::on_pushButton_3_clicked()
{
    FindRecentFlie(30);
}

void NormalUI_HistoricalData::on_SelectDate_clicked()
{
  ui->CalendarGroup->show();

}

void NormalUI_HistoricalData::on_Reject_clicked()
{
  ui->CalendarGroup->hide();

}

void NormalUI_HistoricalData::on_Accept_clicked()
{

   QDate day = ui->calendarWidget->selectedDate();

   QDateTime datetime(day);

   QFileInfoList filelist=GetFileList();

   QFileInfoList selectFileList;

   ui->tableWidget->setRowCount(0);

   foreach(QFileInfo file,filelist)
   {
       if(file.birthTime()>datetime&&file.birthTime()<datetime.addDays(1))
       {
        selectFileList.append(file);
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
       }

   }

   for(int i=0;i<ui->tableWidget->rowCount();i++)
   {
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(selectFileList[i].fileName()));
    ui->tableWidget->setItem(i,2,new QTableWidgetItem(selectFileList[i].birthTime().toString("yyyy-MM-dd hh:mm:ss")));
   }

   ui->CalendarGroup->hide();
}
