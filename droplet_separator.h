#ifndef DROPLET_SEPARATOR_H
#define DROPLET_SEPARATOR_H

#include <QThread>
#include "common.h"
class droplet_separator : public QThread
{
    Q_OBJECT
public:
    explicit droplet_separator(QObject *parent = 0);
    void run();
    bool stop;

signals:

public slots:

};

#endif // DROPLET_SEPARATOR_H
