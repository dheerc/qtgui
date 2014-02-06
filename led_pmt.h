#ifndef LED_PMT_H
#define LED_PMT_H

#include <QThread>
#include "common.h"
class Led_Pmt : public QThread
{
    Q_OBJECT
public:
    explicit Led_Pmt(QObject *parent = 0);
    void run();
    bool stop;

signals:

public slots:

};

#endif // LED_PMT_H
