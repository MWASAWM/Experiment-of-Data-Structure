#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QByteArray>
#include <QString>
#include <crcchecksum.h>
class Instruction
{
public:
    Instruction();

    enum  actionCode{request=0x01,control=0x10,upload=0x20};
    QByteArray instruction;

    int frameHead=0x55;
    actionCode action;
    int commandCode;
    int length;
    int frameCount;
    int currentCount;
    int dataSection;
    int crcCheck;
    int frameTail=0xaa;


    enum status{ON=0x22,OFF=0x23};



    //FIRST COMMAND GROUP
    QByteArray temperatureSet(int *data);
    QByteArray LTMSet(int x,int *data);
    QByteArray voltageSet(int *data);
    QByteArray flowSet(int *data);

    //SECOND COMMAND GROUP
    QByteArray temperatureON;
    QByteArray temperatureOFF;
    QByteArray vacuumON;
    QByteArray vacuumOFF;
    QByteArray filamentSwitchFirst;
    QByteArray filamentSwitchSecond;
    QByteArray filamentON;
    QByteArray filamentOFF;
    QByteArray testON;
    QByteArray testOFF;
    QByteArray readyON;
    QByteArray readyOFF;

    //EIGHTH COMMAND GROUP
    QByteArray menthodSet(int *data);


private:
    crcCheckSum crc;
    QByteArray formInstruction(actionCode action,int command,int length,int *data);
    QByteArray formStableInstruition(status sta,int command);

};

#endif // INSTRUCTION_H
