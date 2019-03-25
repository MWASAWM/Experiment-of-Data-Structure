#ifndef GCINSTRUCTION_H
#define GCINSTRUCTION_H

#include <QByteArray>
#include <QString>

class GCInstruction
{
public:
    GCInstruction();

    QByteArray instruction;
    int frameHead=0x55;
    int addressCode;
    int commandCode;
    int length;
    int frameCount;
    int checkSum;
    int frameTail=0xaa;
    enum status{ON=0x22,OFF=0x23,Request=0x11};

    QByteArray temperatureSet(int *data);
    QByteArray LTMSet(int x,int *data);
    QByteArray flowSet(int *data);

    QByteArray temperatureON;
    QByteArray temperatureOFF;
    QByteArray TestON;
    QByteArray TestOFF;
    QByteArray selfheck;
    QByteArray messget;


    enum lightstatus{lightingoff=0x00,flicker=0x01,lighting=0xff};
    QByteArray sampleSet(lightstatus ready,lightstatus run,lightstatus alarm);
    QByteArray sampleRead;






private:

    QByteArray formInstruction(int address,int command,int length,int *data);
    QByteArray formFixedInstruition(status sta,int address,int command);

};

#endif // GCINSTRUCTION_H
