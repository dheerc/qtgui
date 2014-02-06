#ifndef ARDUINO_H
#define ARDUINO_H

#include <QThread>
#include "common.h"

class arduino : public QThread
{
    Q_OBJECT
public:
    explicit arduino(QObject *parent = 0);
    void run();
    bool stop;

signals:

public slots:

};

#endif // ARDUINO_H
