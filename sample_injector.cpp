#include "sample_injector.h"

Sample_Injector::Sample_Injector(QObject *parent) :
    QThread(parent)
{
    this->stop=false;
}
void Sample_Injector::run()
{
    qDebug()<<"Sample Injector started! \n";
    while(!this->stop)
    {

    }
    qDebug()<<"Sample Injector stopped! \n";
}
