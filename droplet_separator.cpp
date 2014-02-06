#include "droplet_separator.h"

droplet_separator::droplet_separator(QObject *parent) :
    QThread(parent)
{
    this->stop=false;
}
void droplet_separator::run()
{
    qDebug()<<"Droplet Separator started! \n";
    while(!this->stop)
    {

    }
    qDebug()<<"Droplet Separator stopped! \n";
}
