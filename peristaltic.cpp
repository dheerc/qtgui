#include "peristaltic.h"

peristaltic::peristaltic(QObject *parent) :
    QThread(parent)
{
    this->stop=false;
}
void peristaltic::run()
{
    qDebug()<<"Peristaltic pump started! \n";
    while(!this->stop)
    {

    }
    qDebug()<<"Peristaltic pump stopped! \n";
}
