#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common.h"
#include "arduino.h"
#include "peristaltic.h"
#include "droplet_generator.h"
#include "droplet_separator.h"
#include "sample_injector.h"
#include "thermocycler.h"
#include "led_pmt.h"
#include <QtCore>
#include <QtGui>

#include <QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    arduino *a1;
    ~MainWindow();

private slots:
    void on_actionClose_triggered();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_start_stop_1_clicked(bool checked);

    void on_set_1_clicked();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rect;


};

#endif // MAINWINDOW_H
