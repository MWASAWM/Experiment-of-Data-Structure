#include "normalui_chosementhod.h"
#include "ui_normalui_chosementhod.h"

#include <QTableWidget>
#include <QDebug>
#include <QLineEdit>
#include <QTableWidgetItem>
#include <ui_top_para.h>


NormalUI_ChoseMenthod::NormalUI_ChoseMenthod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalUI_ChoseMenthod)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1024,768);
    EditMenthod=new ChoseMenthod_EditMenthod();
    connect(EditMenthod,&ChoseMenthod_EditMenthod::RenewSignal,this,&NormalUI_ChoseMenthod::RenewTable);
    dir=("d:/menthod");
    if(!dir.exists())
    {
        dir.mkdir("d:/menthod");
    }
    filter<<".mth";
    RenewTable();

}

NormalUI_ChoseMenthod::~NormalUI_ChoseMenthod()
{
    delete ui;
}

void NormalUI_ChoseMenthod::on_pushButton_clicked()
{

    delete EditMenthod;

    EditMenthod=new ChoseMenthod_EditMenthod();

    connect(EditMenthod,&ChoseMenthod_EditMenthod::RenewSignal,this,&NormalUI_ChoseMenthod::RenewTable);

    EditMenthod->changeTitle();

    EditMenthod->show();


}
void NormalUI_ChoseMenthod::on_pushButton_2_clicked()
{

    if(ui->tableWidget->currentItem()->isSelected())
    {

    QString MenthodName=ui->tableWidget->currentItem()->text();

    delete EditMenthod;

    EditMenthod=new ChoseMenthod_EditMenthod();

    connect(EditMenthod,&ChoseMenthod_EditMenthod::RenewSignal,this,&NormalUI_ChoseMenthod::RenewTable);

    EditMenthod->PutinMenthod(MenthodName);

    EditMenthod->show();

    }

}
void NormalUI_ChoseMenthod::on_pushButton_3_clicked()
{
    if(ui->tableWidget->currentItem()->isSelected())
    {
    QString location="d:/menthod/"+ui->tableWidget->currentItem()->text()+".mth";
    ui->tableWidget->removeRow(ui->tableWidget->currentItem()->row());
    QFile removefile(location);
    removefile.remove();
    }
}
void NormalUI_ChoseMenthod::on_pushButton_4_clicked()
{

    if(ui->tableWidget->currentItem()->isSelected())
    {
    QString menthodname=ui->tableWidget->currentItem()->text();
    emit MenthodSelectedSignal(menthodname);
    this->hide();
    }

}
void NormalUI_ChoseMenthod::on_pushButton_5_clicked()
{
    this->hide();
}

void NormalUI_ChoseMenthod::RenewTable()
{

    menthodNameList.clear();
    ui->tableWidget->setRowCount(0);
    QDirIterator iter(dir,QDirIterator::Subdirectories);
    while (iter.hasNext())
    {
    iter.next();
    QFileInfo info=iter.fileInfo();
    if (info.isFile())
    {
     ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
     menthodNameList.append(info.fileName().remove(".mth"));
    }
    }
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
     ui->tableWidget->setItem(i,0,new QTableWidgetItem(menthodNameList[i]));
    }
    ui->tableWidget->setCurrentCell(0,0);

}

void NormalUI_ChoseMenthod::updateTop()
{
    ui->Datetime->setText(currentTime);
   // ui->Battery->setText(battery);
    ui->Vacuum->setText(vacuum);
    ui->CurrentMenthodName->setText(menthodName);
    EditMenthod->updateTop();
}
