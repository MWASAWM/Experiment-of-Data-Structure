#ifndef DATAACQUIRETHREAD_H
#define DATAACQUIRETHREAD_H
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPointF>
#include <QList>
class DataAcquireThread:public QThread

{

    Q_OBJECT
public:
    DataAcquireThread();


    void run();


signals:
    void sendarray(QList<QPointF> CSarray);

private slots:
    void acceptConnnection();
    void socketdisconnect();
    void readclient();
    void debug(QList<QPointF> Getarray);


private:

    QTcpServer *server;
    QTcpSocket *socket;
    int i;
    QList<QPointF> CSarray;


};

#endif // DATAACQUIRETHREAD_H
