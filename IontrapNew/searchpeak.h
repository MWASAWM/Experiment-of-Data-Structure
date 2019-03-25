#ifndef SEARCHPEAK_H
#define SEARCHPEAK_H

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPointF>
#include <QList>
#include <QQueue>
class SearchPeak:public QThread

{

    Q_OBJECT
public:
    SearchPeak();

    void SetData(int data[]);

    void run();


signals:
    void sendarray(QList<QPointF> CSarray);

private slots:



private:


    QList<QPointF> CSarray;

    double RawData[10000];

    QQueue<QList<QPointF>>   Buffer;


};

#endif // SEARCHPEAK_H
