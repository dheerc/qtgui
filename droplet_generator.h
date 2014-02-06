#ifndef DROPLET_GENERATOR_H
#define DROPLET_GENERATOR_H

#include <QThread>
#include "common.h"
class droplet_generator : public QThread
{
    Q_OBJECT
public:
    explicit droplet_generator(QObject *parent = 0);
    void run();
    bool stop;

signals:

public slots:

};

#endif // DROPLET_GENERATOR_H
