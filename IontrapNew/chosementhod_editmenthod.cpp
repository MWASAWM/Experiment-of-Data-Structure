#include "chosementhod_editmenthod.h"
#include "ui_chosementhod_editmenthod.h"
#include "QDebug"
#include "QFile"


ChoseMenthod_EditMenthod::ChoseMenthod_EditMenthod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoseMenthod_EditMenthod)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1024,768);

    ui->BasicBox->setGeometry(187,97,800,540);
    ui->TemperatureBox->setGeometry(187,97,800,540);
    ui->StatusBox->setGeometry(187,97,800,540);
    ui->QualityBox->setGeometry(187,97,800,540);

    ui->BasicBox->show();
    ui->StatusBox->hide();
    ui->TemperatureBox->hide();
    ui->QualityBox->hide();

    ui->TemperatureWidget->horizontalHeader()->setVisible(true);
    ui->StatusWidget->horizontalHeader()->setVisible(true);
    ui->LibraryWidget->horizontalHeader()->setVisible(true);




    menthod = new MenthodParameter();
    /*
    connect(ui->Detector,&QLineEdit::editingFinished,this,&ChoseMenthod_EditMenthod::CheckTmp);
    connect(ui->Diverter,&QLineEdit::editingFinished,this,&ChoseMenthod_EditMenthod::CheckTmp);
    connect(ui->EnrichmentTube,&QLineEdit::editingFinished,this,&ChoseMenthod_EditMenthod::CheckTmp);
    connect(ui->Probe,&QLineEdit::editingFinished,this,&ChoseMenthod_EditMenthod::CheckTmp);
    connect(ui->SixWayValve,&QLineEdit::editingFinished,this,&ChoseMenthod_EditMenthod::CheckTmp);
    */


    ui->textEdit->toPlainText();
    ui->TemperatureWidget->rowCount();



    //connect(ui->Detector,SIGNAL(valueChanged(QString)),this,SLOT(ShowInput(QString)));

    ui->Detector->setRange(50,180);
    ui->EnrichmentTube->setRange(50,350);
    ui->Probe->setRange(40,80);
    ui->SixWayValve->setRange(50,100);
    ui->Diverter->setRange(50,325);




    //QRegExp rx("^(180|([1-9]?[0-9]|1[0-7][0-9])(\\.\\d{1,2})?)$");
    //QRegExpValidator *pReg = new QRegExpValidator(rx, this);
/*
    QRegExp Diverterrx("^(32[0-5]|3[0-1][0-9]|2[0-9][0-9]|1[0-9][0-9]|([5-9][0-9])$)");
    QRegExp EnrichmentTuberx("^(350|3[0-4][0-9]|2[0-9][0-9]|1[0-9][0-9]|([5-9][0-9]))$");
    QRegExp Proberx("^(80|([4-7][0-9]))$");
    QRegExp SixWayValverx("^(100|([5-9][0-9]))$");
    QRegExp Detecorrx("^(300|2[0-9][0-9]|1[0-9][0-9]|([5-9][0-9]))$");

    ui->Diverter->setValidator( new QRegExpValidator(Diverterrx, this));
    ui->EnrichmentTube->setValidator( new QRegExpValidator(EnrichmentTuberx, this));
    ui->Probe->setValidator( new QRegExpValidator(Proberx, this));
    ui->SixWayValve->setValidator( new QRegExpValidator(SixWayValverx, this));
    ui->Detector->setValidator( new QRegExpValidator(Detecorrx, this));


*/
    ui->INPUT->hide();
    ui->INPUT->move(0,0);
    ui->INPUT->raise();

    updateTop();


}

ChoseMenthod_EditMenthod::~ChoseMenthod_EditMenthod()
{
    delete ui;
}

void ChoseMenthod_EditMenthod::on_pushButton_clicked()
{


    ui->pushButton->setChecked(true);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);


    ui->BasicBox->show();
    ui->StatusBox->hide();
    ui->TemperatureBox->hide();
    ui->QualityBox->hide();

    ui->back->setStyleSheet("background-color: rgb(0, 158, 214)");



}


void ChoseMenthod_EditMenthod::on_pushButton_2_clicked()
{

    ui->pushButton_2->setChecked(true);
    ui->pushButton->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);


    ui->BasicBox->hide();
    ui->TemperatureBox->show();
    ui->StatusBox->hide();
    ui->QualityBox->hide();

    ui->back->setStyleSheet("background-color: rgb(238, 239, 239);");


}


void ChoseMenthod_EditMenthod::on_pushButton_3_clicked()
{

    ui->pushButton_3->setChecked(true);
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_4->setChecked(false);


    ui->BasicBox->hide();
    ui->TemperatureBox->hide();
    ui->StatusBox->show();
    ui->QualityBox->hide();
    ui->back->setStyleSheet("background-color: rgb(238, 239, 239);");

}

void ChoseMenthod_EditMenthod::on_pushButton_4_clicked()
{

    ui->pushButton_4->setChecked(true);
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);


    ui->BasicBox->hide();
    ui->StatusBox->hide();
    ui->TemperatureBox->hide();
    ui->QualityBox->show();
    ui->back->setStyleSheet("background-color: rgb(238, 239, 239);");
}

void ChoseMenthod_EditMenthod::on_MenthodDetermination_clicked()
{
    this->hide();
    RecordMenthod();
    QString MenthodName="d:/menthod/"+ui->MenthodName->text()+".mth";
    WriteMenthodtoFile(MenthodName);
    emit RenewSignal();

}

void ChoseMenthod_EditMenthod::on_Return_clicked()
{

    this->hide();

}


void ChoseMenthod_EditMenthod::on_AddRow_clicked()
{

    if(ui->TemperatureWidget->rowCount()>8)

    {

        ShowMessage("已到达最大阶数！");
        return;

    }

    int isinsert=ui->TemperatureWidget->currentRow();
    if(isinsert==-1)
    {
        int rowcout=ui->TemperatureWidget->rowCount();
        ui->TemperatureWidget->insertRow(rowcout);
        QSpinBox *spinbox[5];

        for(int i=0;i<5;i++)
        {
        spinbox[i]=new QSpinBox();
        spinbox[i]->setStyleSheet("QSpinBox::up-button { width: 0px;height: 0px;}"\
                               "QSpinBox::down-button { width: 0px;height: 0px;}\
                               QSpinBox{border-color: rgb(177, 177, 177);\
                               font: 11pt '苹方 常规';}");
        if(i!=0) connect(spinbox[i],SIGNAL(valueChanged(QString)),this,SLOT(ShowInput(QString)));
        connect(spinbox[i],&QSpinBox::editingFinished,this,&ChoseMenthod_EditMenthod::InputFinish);
        if(i==0) spinbox[i]->setReadOnly(true);
        spinbox[i]->setRange(-1,100);

        ui->TemperatureWidget->setCellWidget(rowcout,i,spinbox[i]);
        }


    }

    else
    {
        ui->TemperatureWidget->insertRow(isinsert+1);
        QSpinBox *spinbox[5];

        for(int i=0;i<5;i++)
        {
        spinbox[i]=new QSpinBox();
        spinbox[i]->setStyleSheet("QSpinBox::up-button { width: 0px;height: 0px;}"\
                               "QSpinBox::down-button { width: 0px;height: 0px;}\
                               QSpinBox{border-color: rgb(177, 177, 177);\
                               font: 11pt '苹方 常规';}");
        if(i!=0) connect(spinbox[i],SIGNAL(valueChanged(QString)),this,SLOT(ShowInput(QString)));
        if(i==0) spinbox[i]->setReadOnly(true);
        connect(spinbox[i],&QSpinBox::editingFinished,this,&ChoseMenthod_EditMenthod::InputFinish);
        spinbox[i]->setRange(0,100);

        ui->TemperatureWidget->setCellWidget(isinsert+1,i,spinbox[i]);
        }

    }

      for(int i=0;i<ui->TemperatureWidget->rowCount();i++)
         {

          qobject_cast<QSpinBox*>(ui->TemperatureWidget->cellWidget(i,0))->setValue(i);


      }
}

void ChoseMenthod_EditMenthod::on_DeleteRow_clicked()
{

    int removefucus=ui->TemperatureWidget->currentRow();
    if(removefucus==-1)
    {

        ShowMessage("未选中任何行");

    }

    else
    {

        ui->TemperatureWidget->removeRow(removefucus);
        for(int i=0;i<ui->TemperatureWidget->rowCount();i++)
            qobject_cast<QSpinBox*>(ui->TemperatureWidget->cellWidget(i,0))->setValue(i);

    }

 }


/*
    int Select=0;
    int SelectRowNumber[50];

  *  QList<QTableWidgetSelectionRange>ranges= ui->TemperatureWidget->selectedRanges();
    int count=ranges.count();
    qDebug()<<count;
      for(int i=0;i<count;i++)
    {
    int topRow=ranges.at(i).topRow();
    qDebug()<<topRow;
    int bottomRow=ranges.at(i).bottomRow();
    qDebug()<<bottomRow;
    for(int j=topRow;j<=bottomRow;j++)
    {
     SelectRowNumber[Select]=j;
     qDebug()<<SelectRowNumber[Select];
     Select++;
    }
    }
    Select--;

    std::sort(SelectRowNumber,SelectRowNumber+Select+1);
    for(int i=Select;i>=0;i--)
    {
    qDebug()<<i;
    ui->TemperatureWidget->removeRow(i);
    }
    */



void ChoseMenthod_EditMenthod::on_AddStatus_clicked()
{
    bool isinsert=ui->StatusWidget->isItemSelected(ui->StatusWidget->currentItem());
    if(isinsert)
    {
        int insertRow=ui->StatusWidget->currentItem()->row();
        ui->StatusWidget->insertRow(insertRow+1);
    }

    else
    {
        int rowcount=ui->StatusWidget->rowCount();
        rowcount++;
        ui->StatusWidget->setRowCount(rowcount);
    }

}



void ChoseMenthod_EditMenthod::on_DeleteStatus_clicked()
{

    bool removefocus=ui->StatusWidget->isItemSelected(ui->StatusWidget->currentItem());
    if(removefocus)
    {
        int deleteRow=ui->StatusWidget->currentItem()->row();
        ui->StatusWidget->removeRow(deleteRow);
    }

    else
    {


    }
}

void ChoseMenthod_EditMenthod::PutinMenthod(QString MenthodName)
{
    QString MenthodLocation="d:/menthod/"+MenthodName+".mth";
    QFile menthod(MenthodLocation);
    ReadMenthodfromFile(MenthodLocation);
    menthod.close();
    ui->INPUT->hide();
}
void ChoseMenthod_EditMenthod::RecordMenthod()
{
    menthod->MenthodName=ui->MenthodName->text();

    menthod->Detector=ui->Detector->text().toInt();
    menthod->Diverter=ui->Diverter->text().toInt();
    menthod->EnrichmentTube=ui->EnrichmentTube->text().toInt();
    menthod->Probe=ui->Probe->text().toInt();
    menthod->SixWayVavle=ui->SixWayValve->text().toInt();
    menthod->Note=ui->textEdit->toPlainText();
    menthod->HeatCount=ui->TemperatureWidget->rowCount();
    for(int i=0;i<menthod->HeatCount;i++)
    {

        menthod->Heat[i].StageNumber= qobject_cast<QSpinBox*>(ui->TemperatureWidget->cellWidget(i,0))->value();
        menthod->Heat[i].StartTime= qobject_cast<QSpinBox*>(ui->TemperatureWidget->cellWidget(i,1))->value();
        menthod->Heat[i].EndTemperature= qobject_cast<QSpinBox*>(ui->TemperatureWidget->cellWidget(i,2))->value();
        menthod->Heat[i].HeatRate= qobject_cast<QSpinBox*>(ui->TemperatureWidget->cellWidget(i,3))->value();
        menthod->Heat[i].StorageTime= qobject_cast<QSpinBox*>(ui->TemperatureWidget->cellWidget(i,4))->value();






        /*
        menthod->Heat[i].StageNumber=ui->TemperatureWidget->item(i,0)->text().toInt();
        menthod->Heat[i].StartTime=ui->TemperatureWidget->item(i,1)->text().toInt();
        menthod->Heat[i].EndTemperature=ui->TemperatureWidget->item(i,2)->text().toInt();
        menthod->Heat[i].HeatRate=ui->TemperatureWidget->item(i,3)->text().toInt();
        menthod->Heat[i].StorageTime=ui->TemperatureWidget->item(i,4)->text().toInt();
        menthod->Heat[i].TotalTime=ui->TemperatureWidget->item(i,5)->text().toInt();
        */
    }

}
void ChoseMenthod_EditMenthod::WriteMenthodtoFile(QString MenthodNametoSave)
{
    QFile Menthod(MenthodNametoSave);
    Menthod.open(QIODevice::WriteOnly | QIODevice::Text );
    QTextStream outStream(&Menthod);
    outStream<<menthod->MenthodName<<endl;
    outStream<<menthod->Detector<<endl;
    outStream<<menthod->Diverter<<endl;
    outStream<<menthod->EnrichmentTube<<endl;
    outStream<<menthod->Probe<<endl;
    outStream<<menthod->SixWayVavle<<endl;
    outStream<<menthod->HeatCount<<endl;
    for(int i=0;i<menthod->HeatCount;i++)
    {

        outStream<<menthod->Heat[i].StageNumber<<endl;
        outStream<<menthod->Heat[i].StartTime<<endl;
        outStream<<menthod->Heat[i].EndTemperature<<endl;
        outStream<<menthod->Heat[i].HeatRate<<endl;
        outStream<<menthod->Heat[i].StorageTime<<endl;


    }


    outStream<<menthod->Note;
    Menthod.close();

}

void ChoseMenthod_EditMenthod::ReadMenthodfromFile(QString MenthodNametoRead)
{
    QFile Menthod(MenthodNametoRead);
    Menthod.open(QIODevice::ReadOnly | QIODevice::Text );
    QTextStream inStream(&Menthod);
    ui->MenthodName->setText(inStream.readLine());

    ui->Detector->setValue(inStream.readLine().toInt());
    ui->Diverter->setValue(inStream.readLine().toInt());
    ui->EnrichmentTube->setValue(inStream.readLine().toInt());
    ui->Probe->setValue(inStream.readLine().toInt());
    ui->SixWayValve->setValue(inStream.readLine().toInt());
    int heatcount=inStream.readLine().toInt();
    ui->TemperatureWidget->setRowCount(heatcount);
    HeatContol heat[10];
    for(int i=0;i<heatcount;i++)
    {

       heat[i].StageNumber=inStream.readLine().toInt();
       heat[i].StartTime=inStream.readLine().toInt();
       heat[i].EndTemperature=inStream.readLine().toInt();
       heat[i].HeatRate=inStream.readLine().toInt();
       heat[i].StorageTime=inStream.readLine().toInt();


       QSpinBox *spinbox[5];

       for(int i=0;i<5;i++)
       {
       spinbox[i]=new QSpinBox();
       spinbox[i]->setStyleSheet("QSpinBox::up-button { width: 0px;height: 0px;}"\
                              "QSpinBox::down-button { width: 0px;height: 0px;}\
                              QSpinBox{border-color: rgb(177, 177, 177);\
                              font: 11pt '苹方 常规';}");

       if(i!=0)connect(spinbox[i],SIGNAL(valueChanged(QString)),this,SLOT(ShowInput(QString)));
       if(i==0) spinbox[i]->setReadOnly(true);
       connect(spinbox[i],&QSpinBox::editingFinished,this,&ChoseMenthod_EditMenthod::InputFinish);

       spinbox[i]->setRange(-1,100);


       }
       spinbox[0]->setValue(heat[i].StageNumber);
       ui->TemperatureWidget->setCellWidget(i,0,spinbox[0]);
       spinbox[1]->setValue(heat[i].StartTime);
       ui->TemperatureWidget->setCellWidget(i,1,spinbox[1]);
       spinbox[2]->setValue(heat[i].EndTemperature);
       ui->TemperatureWidget->setCellWidget(i,2,spinbox[2]);
       spinbox[3]->setValue(heat[i].HeatRate);
       ui->TemperatureWidget->setCellWidget(i,3,spinbox[3]);
       spinbox[4]->setValue(heat[i].StorageTime);
       ui->TemperatureWidget->setCellWidget(i,4,spinbox[4]);



       /*
       ui->TemperatureWidget->setItem(i,0,new QTableWidgetItem(QString::number(heat[i].StageNumber)));
       ui->TemperatureWidget->setItem(i,1,new QTableWidgetItem(QString::number(heat[i].StartTime)));
       ui->TemperatureWidget->setItem(i,2,new QTableWidgetItem(QString::number(heat[i].EndTemperature)));
       ui->TemperatureWidget->setItem(i,3,new QTableWidgetItem(QString::number(heat[i].HeatRate)));
       ui->TemperatureWidget->setItem(i,4,new QTableWidgetItem(QString::number(heat[i].StorageTime)));
       ui->TemperatureWidget->setItem(i,5,new QTableWidgetItem(QString::number(heat[i].TotalTime)));
       */
    }

    ui->textEdit->setText(inStream.readAll());

    Menthod.close();

}

void ChoseMenthod_EditMenthod::ShowMessage(QString m)
{
    MessageDialog *messagedialog=new MessageDialog(this);
    messagedialog->SetMessage(m);
    messagedialog->show();

}
void ChoseMenthod_EditMenthod::ShowInput(QString mess)
 {
    ui->INPUT->show();
    ui->INPUT->setText(mess);
 }


void ChoseMenthod_EditMenthod::InputFinish()
{
    ui->INPUT->hide();
}

void ChoseMenthod_EditMenthod::updateTop()
{
    ui->Datetime->setText(currentTime);
    //ui->Battery->setText(battery);
    ui->Vacuum->setText(vacuum);
    ui->CurrentMenthodName->setText(menthodName);
}

void ChoseMenthod_EditMenthod::changeTitle()
{
    ui->Title->setText("新建方法");
}
