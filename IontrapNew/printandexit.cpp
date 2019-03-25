#include "printandexit.h"
#include "ui_printandexit.h"
#include <QFile>
#include <QDebug>


PrintandExit::PrintandExit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintandExit)
{
    ui->setupUi(this);
/*
    QFile file("C:/log.txt");


    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QString text;
    while(!file.atEnd())
    {
       QByteArray line = file.readLine();
       QString str(line);
       text+=str;

    }
    ui->textEdit->setPlainText(text);
*/
}

PrintandExit::~PrintandExit()
{
    delete ui;
}


