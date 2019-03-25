#include "instruction.h"
#include <QByteArray>
#include <QDebug>
Instruction::Instruction()
{

   //SECOND COMMAND GROUP
   temperatureON=formStableInstruition(ON,0x11);
   temperatureOFF=formStableInstruition(OFF,0x11);
   vacuumON=formStableInstruition(ON,0x12);
   vacuumOFF=formStableInstruition(OFF,0x12);
   filamentSwitchFirst=formStableInstruition(ON,0x13);
   filamentSwitchSecond=formStableInstruition(OFF,0x13);
   filamentON=formStableInstruition(ON,0x14);
   filamentOFF=formStableInstruition(OFF,0x14);
   testON=formStableInstruition(ON,0x15);
   testOFF=formStableInstruition(OFF,0x15);
   readyON=formStableInstruition(ON,0x16);
   readyOFF=formStableInstruition(OFF,0x16);


}


QByteArray Instruction::temperatureSet(int *data)
{
    QByteArray Instruction;
    action=control;
    commandCode=0x01;
    length=10+2;
    Instruction=formInstruction(action,commandCode,length,data);
    return Instruction;
}

QByteArray Instruction::LTMSet(int x, int *data)
{
    QByteArray Instruction;
    action=control;
    commandCode=0x02;
    length=4*x+3;
    Instruction.append(char(frameHead));
    Instruction.append(action);
    Instruction.append(char(commandCode));
    QString temp="%1";
    Instruction.append(QByteArray::fromHex(temp.arg(length,4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(0x01);
    Instruction.append(0x01);
    Instruction.append(char(x));
    for(int i=0;i<(length-3)/2;i++)
    Instruction.append(QByteArray::fromHex(temp.arg(data[i+1],4,16,QLatin1Char('0')).toLatin1().data()));
    crcCheck=crc.crc16ForModbus(Instruction.mid(1));
    Instruction.append(QByteArray::fromHex(temp.arg(crcCheck,4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(frameTail));
    return Instruction;

}

QByteArray Instruction::voltageSet(int *data)
{
    QByteArray Instruction;
    action=control;
    commandCode=0x03;
    length=6+2;
    Instruction=formInstruction(action,commandCode,length,data);
    return Instruction;
}

QByteArray Instruction::flowSet(int *data)
{
    QByteArray Instruction;
    action=control;
    commandCode=0x04;
    length=4+2;
    Instruction=formInstruction(action,commandCode,length,data);
    return Instruction;
}

QByteArray Instruction::menthodSet(int *data)
{
    QByteArray Instruction;
    action=control;
    commandCode=0x81;
    length=25+2;
    Instruction.append(char(frameHead));
    Instruction.append(action);
    Instruction.append(char(commandCode));
    QString temp="%1";
    Instruction.append(QByteArray::fromHex(temp.arg(length,4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(0x01);
    Instruction.append(0x01);
    Instruction.append(char(data[0]));
    Instruction.append(char(data[1]));
    for(int i=0;i<11;i++)
    Instruction.append(QByteArray::fromHex(temp.arg(data[i+2],4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(data[13]));
    crcCheck=crc.crc16ForModbus(Instruction.mid(1));
    Instruction.append(QByteArray::fromHex(temp.arg(crcCheck,4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(frameTail));
    return Instruction;
}


QByteArray Instruction::formInstruction(actionCode action, int command, int length, int *data)
{
    QByteArray Instruction;
    Instruction.append(char(frameHead));
    Instruction.append(action);
    Instruction.append(char(command));
    QString temp="%1";
    Instruction.append(QByteArray::fromHex(temp.arg(length,4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(0x01);
    Instruction.append(0x01);
    for(int i=0;i<(length-2)/2;i++)
    Instruction.append(QByteArray::fromHex(temp.arg(data[i],4,16,QLatin1Char('0')).toLatin1().data()));
    crcCheck=crc.crc16ForModbus(Instruction.mid(1));
    Instruction.append(QByteArray::fromHex(temp.arg(crcCheck,4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(frameTail));
    return Instruction;
}
QByteArray Instruction::formStableInstruition(status sta, int command)
{
    QByteArray Instruction;
    Instruction.append(char(frameHead));
    Instruction.append(control);
    Instruction.append(char(command));
    QString temp="%1";
    Instruction.append(char(0x00));
    Instruction.append(0x03);
    Instruction.append(0x01);
    Instruction.append(0x01);
    Instruction.append(sta);
    crcCheck=crc.crc16ForModbus(Instruction.mid(1));
    Instruction.append(QByteArray::fromHex(temp.arg(crcCheck,4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(frameTail));
    return Instruction;

}
