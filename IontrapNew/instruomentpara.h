#ifndef INSTRUOMENTPARA_H
#define INSTRUOMENTPARA_H

#include <QString>
extern QString InsNumber;
extern QString CheckResult;

//主动上传第一命令组
//0x01
extern QString SixWayVavle ;//通阀
extern QString Detector ;//到探测器（气质接口）
extern QString Diverter ;//分流器
extern QString Probe ;//探头
extern QString EnrichmentTube; //富集管
extern QString LTMTemperature; //LTM柱

//0x03

extern QString MultiplierTubeVoltage;//富集管高压
extern QString FilamentCurrent;//灯丝电流
extern QString BiasVoltage;//BIAS高压


//0x05

extern QString Vacuum;

extern QString PumpSpeed;
extern QString PumpCurrent;
extern QString PumpVoltage;
extern QString PumpElecTemperature;
extern QString PumpVacuum;



//
extern QString flowspeed1;
extern QString flowspeed2;
extern QString ActiveTime;

extern QString pressure1;
extern QString pressure2;
extern QString pressure3;
//参数控制



extern QString EFCFlowSpeed1;
extern QString EFCFlowSpeed2;


extern QString ErrorCode;
//参数控制返回消息
extern QString InsFirstCode[5];
extern QString InsSecondCode[5];
extern int insFailCount[5];
extern QString InsMenthodCode;
extern int MenthodFailCount;
extern QString InsReady;
extern QString InsParaCode;


extern int Valve[4];
extern int Fan[3];
extern int SampalePump;

enum lightingstatus{lightingoff=0x00,flicker=0x01,lighting=0xff};
extern lightingstatus samplestautslast;
extern lightingstatus samplestautsnow;
extern QString samplereply;

//方法参数
extern int ionMoudle;
extern int scanMoudle;
extern int rampTime;
extern int rampFreq;
extern int rampNumber;
extern int IonSaveVoltage;//离子化存储水平
extern int LowWeight;//Ramp 低电压
extern int HighWeight;//Ramp高电压
extern int IonTime;//离子化时间
extern int ScanTime;//扫描时间
extern int AmpLow;
extern int AmpHigh;
extern int eGateTime;//电子门开启时间




#endif // INSTRUOMENTPARA_H
