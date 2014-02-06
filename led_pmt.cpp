#include "led_pmt.h"

Led_Pmt::Led_Pmt(QObject *parent) :
    QThread(parent)
{
    this->stop=false;
}
void Led_Pmt::run()
{
    qDebug()<<"LED PMT started! \n";
    while(!this->stop)
    {

    }
    qDebug()<<"LED PMT stopped! \n";
}
