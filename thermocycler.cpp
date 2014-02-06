#include "thermocycler.h"

thermocycler::thermocycler(QObject *parent) :
    QThread(parent)
{
    this->stop=false;
}
void thermocycler::run()
{
    qDebug()<<"Thermocycler started! \n";
    while(!this->stop)
    {

    }
    qDebug()<<"Thermocycler stopped! \n";
}
