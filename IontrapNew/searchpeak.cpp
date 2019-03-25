#include "searchpeak.h"

SearchPeak::SearchPeak()
{
    qRegisterMetaType<QList<QPointF>>("QListPointf");
}

void SearchPeak::SetData(int *data)
{

    int length=sizeof(data)/sizeof(data[0]);
    for(int i=0;i<length;i++)
    {
        RawData[i]=data[i];
    }

}

void SearchPeak::run()
{





}
