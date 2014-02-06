#include "droplet_generator.h"

droplet_generator::droplet_generator(QObject *parent) :
    QThread(parent)
{
    this->stop=false;
}
void droplet_generator::run()
{
    qDebug()<<"Droplet Generator started! \n";
    while(!this->stop)
    {

    }
    qDebug()<<"Droplet Generator stopped! \n";
}
