#ifndef THERMOCYCLER_H
#define THERMOCYCLER_H

#include <QThread>
#include "common.h"
class thermocycler : public QThread
{
    Q_OBJECT
public:
    explicit thermocycler(QObject *parent = 0);
    void run();
    bool stop;

signals:

public slots:

};

#endif // THERMOCYCLER_H
