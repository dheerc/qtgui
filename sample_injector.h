#ifndef SAMPLE_INJECTOR_H
#define SAMPLE_INJECTOR_H

#include <QThread>
#include "common.h"
class Sample_Injector : public QThread
{
    Q_OBJECT
public:
    explicit Sample_Injector(QObject *parent = 0);
    void run();
    bool stop;

signals:

public slots:

};

#endif // SAMPLE_INJECTOR_H
