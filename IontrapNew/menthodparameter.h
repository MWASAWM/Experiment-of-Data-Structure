#ifndef MENTHODPARAMETER_H
#define MENTHODPARAMETER_H
#include <QString>
 class MenthodParameter
{
 public:
     //基本信息
     enum AnalyzeMoudle{GCMS,SingleMS};
     enum ScanMoudle{FullScan,SelectScan};
     QString MenthodName;
     QString Note;
     ScanMoudle scan=ScanMoudle::FullScan;
     AnalyzeMoudle analyze=AnalyzeMoudle::GCMS;
     //色谱温度
     int HeatCount;
     struct HeatControl
     {

      int StageNumber;
      int StartTime;
      int EndTemperature;
      int HeatRate;
      int StorageTime;

     };
     int SixWayVavle;//通阀
     int Detector;//到探测器
     int Diverter;//分流器
     int Probe;//探头
     int EnrichmentTube; //富集管

     HeatControl Heat[10];
     //色谱状态


     //谱库
     QString location;


};
#endif // MENTHODPARAMETER_H
