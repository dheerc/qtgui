#ifndef COMMON_H
#define COMMON_H


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <QtCore>
#include <QDebug>
extern char filename[40];
extern int file;
extern int addr;
extern int addr_peristaltic;
extern int addr_led_pmt;
extern int addr_sample_injector;
extern int addr_droplet_generator;
extern int addr_droplet_separator;
extern int addr_thermocycler;
extern char buf[5];
extern QMutex mutex;

#endif // COMMON_H
