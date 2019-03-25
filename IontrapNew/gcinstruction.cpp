#include "gcinstruction.h"

GCInstruction::GCInstruction()
{
    temperatureON=formFixedInstruition(ON,0x22,0x11);
    temperatureOFF=formFixedInstruition(OFF,0x22,0x11);
    TestON=formFixedInstruition(ON,0x22,0x12);
    TestOFF=formFixedInstruition(OFF,0x22,0x12);
    selfheck=formFixedInstruition(Request,0x22,0x21);
    messget=formFixedInstruition(Request,0x22,0x22);

    sampleRead=formFixedInstruition(Request,0x33,0x01);
}


QByteArray GCInstruction::flowSet(int *data)
{
    QByteArray Instruction;
    commandCode=0x01;
    addressCode=0x22;
    length=8;
    Instruction=formInstruction(addressCode,commandCode,length,data);
    return Instruction;
}


QByteArray GCInstruction::temperatureSet(int *data)
{
    QByteArray Instruction;
    commandCode=0x02;
    addressCode=0x22;
    length=10;
    Instruction=formInstruction(addressCode,commandCode,length,data);
    return Instruction;
}

QByteArray GCInstruction::LTMSet(int x, int *data)
{
    QByteArray Instruction;
    commandCode=0x03;
    addressCode=0x22;
    length=4*x+1;
    Instruction.append(char(frameHead));
    Instruction.append(char(addressCode));
    Instruction.append(char(commandCode));
    QString temp="%1";
    Instruction.append(QByteArray::fromHex(temp.arg(length,4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(x));
    for(int i=0;i<(length-1)/2;i++)
    Instruction.append(QByteArray::fromHex(temp.arg(data[i+1],4,16,QLatin1Char('0')).toLatin1().data()));
    for(int i=0;i<length+4;i++)
    {
        Instruction[length+5]=Instruction[i+1]+Instruction[length+5];
    }
    Instruction.append(char(frameTail));
    return Instruction;

}

QByteArray GCInstruction::sampleSet(lightstatus ready, lightstatus run, lightstatus alarm)
{
    QByteArray Instruction;
    commandCode=0x02;
    addressCode=0x33;
    Instruction.append(char(frameHead));
    Instruction.append(char(addressCode));
    Instruction.append(char(commandCode));
    Instruction.append(char(0x00));
    Instruction.append(char(0x03));
    Instruction.append(char(ready));
    Instruction.append(char(run));
    Instruction.append(char(alarm));
    Instruction.append(char(checkSum));
    for(int i=0;i<3+4;i++)
    {
        Instruction[3+5]=Instruction[i+1]+Instruction[3+5];
    }
    Instruction.append(char(frameTail));
    return Instruction;


}

QByteArray GCInstruction::formInstruction(int address,int command, int length, int *data)
{
    QByteArray Instruction;
    Instruction.append(char(frameHead));
    Instruction.append(char(address));
    Instruction.append(char(command));
    QString temp="%1";
    Instruction.append(QByteArray::fromHex(temp.arg(length,4,16,QLatin1Char('0')).toLatin1().data()));
    for(int i=0;i<length/2;i++)
    Instruction.append(QByteArray::fromHex(temp.arg(data[i],4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(checkSum));
    for(int i=0;i<length+4;i++)
    {
        Instruction[length+5]=Instruction[i+1]+Instruction[length+5];
    }
    Instruction.append(char(frameTail));
    return Instruction;
}
QByteArray  GCInstruction::formFixedInstruition(status sta,int address, int command)
{
    QByteArray Instruction;
    Instruction.append(char(frameHead));
    Instruction.append(char(address));
    Instruction.append(char(command));
    Instruction.append(char(0x00));
    Instruction.append(char(0x01));
    Instruction.append(sta);
    Instruction.append(char(checkSum));
    for(int i=0;i<5;i++)
    {
        Instruction[6]=Instruction[i+1]+Instruction[6];

    }
    Instruction.append(char(frameTail));
    return Instruction;
}
