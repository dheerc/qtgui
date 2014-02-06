#ifndef PERISTALTIC_H
#define PERISTALTIC_H

#include <QThread>
#include "common.h"
class peristaltic : public QThread
{
    Q_OBJECT
public:
    explicit peristaltic(QObject *parent = 0);
    void run();
    bool stop;

signals:

public slots:

};

#endif // PERISTALTIC_H
