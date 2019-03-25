#include "dataacquirethread.h"
#include <QMessageBox>
#include <QThread>
#include <QList>
#include <QPointF>
#include <QDebug>
#include <QMetaType>
DataAcquireThread::DataAcquireThread()

{
    qRegisterMetaType<QList<QPointF>>("QListPointf");
    server=new QTcpServer();
    server->listen(QHostAddress::Any,6000);
    connect(server,SIGNAL(newConnection()),this,SLOT(acceptConnnection()));
}


 void DataAcquireThread::run()
{
    QString readdata;
    for(i=0;i<500;i++)
    {
        readdata.append("aaaa");

    }
    for(int a=0;a<500;a++)
    {
    int data=readdata.mid(a*4,4).toInt(nullptr,16);
    CSarray.append(QPointF(a, data));
    //qDebug()<<CSarray;

    }


    emit sendarray(CSarray);

}
void DataAcquireThread::acceptConnnection()
{
    socket=server->nextPendingConnection();
    connect(socket,&QTcpSocket::disconnected,this,&DataAcquireThread::socketdisconnect);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readclient()));
    server->close();
}

void DataAcquireThread::socketdisconnect()
{
    server->listen(QHostAddress::Any,6000);
}


void DataAcquireThread::readclient()
{


}

void DataAcquireThread::debug(QList<QPointF> MSarray)
{

           qDebug()<<MSarray;

}
