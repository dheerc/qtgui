#include "arduino.h"

arduino::arduino(QObject *parent) :
    QThread(parent)
{
    this->stop=false;
}

void arduino::run()
{
    qDebug()<<"Arduino thread started! \n";
    while(!this->stop)
    {

    }
    qDebug()<<"Arduino thread stopped! \n";
}
