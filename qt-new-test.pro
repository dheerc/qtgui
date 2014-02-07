#-------------------------------------------------
#
# Project created by QtCreator 2014-01-22T11:53:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = arduino-test-new-3
TEMPLATE = app

# VERY Important to add these lines manually, if not done automatically
################################################################################
target.path= /home/pi/Desktop/          #Path where to install executable on Pi
INSTALLS+= target                       #The executable name which is going to be installed and debugged

################################################################################
SOURCES += main.cpp\
        mainwindow.cpp \
    arduino.cpp \
    peristaltic.cpp \
    thermocycler.cpp \
    sample_injector.cpp \
    droplet_generator.cpp \
    droplet_separator.cpp \
    led_pmt.cpp


CONFIG+= debug
HEADERS  += mainwindow.h \
    arduino.h \
    common.h \
    peristaltic.h \
    thermocycler.h \
    sample_injector.h \
    droplet_generator.h \
    droplet_separator.h \
    led_pmt.h

FORMS    += mainwindow.ui

OTHER_FILES +=
