#include "mainwindow.h"
#include "ui_mainwindow.h"

int addr=0x04;
int addr_peristaltic=0x05;
int addr_led_pmt=0x06;
int addr_sample_injector=0x07;
int addr_droplet_generator=0x08;
int addr_droplet_separator=0x09;
int addr_thermocycler=0x0A;
int file=0;

char size=1;
char buf[20]={0};
char buf1[80]={0};
QString add;
char filename[40];

int i=0;
QMutex mutex;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene= new QGraphicsScene (this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);

    QPen blackPen(Qt::black);
    blackPen.setWidth(6);
    ellipse = scene->addEllipse(10,10,100,100,blackPen,redBrush);
    rect = scene->addRect(-100,-100,50,50,blackPen,blueBrush);
    a1= new arduino(this);

    {
        sprintf(filename,"/dev/i2c-1");
        qDebug()<<"\nStart of communication \n";
        if((file=open(filename,O_RDWR))<0)
        {
            qDebug()<<"Cannot open i2c bus...\n";

        }
        else
        {
            qDebug()<<"\n\n Successfully opened i2c bus...";
        }

    }
    if (ioctl(file,I2C_SLAVE,addr) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to UNO.";
        /* ERROR HANDLING; you can check errno to see what went wrong */
        a1->stop=false;
        //exit(1);
    }
    else
        qDebug()<<("Successfully connected to UNO!");

    if (ioctl(file,I2C_SLAVE,addr_droplet_generator) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to droplet generator.";
        /* ERROR HANDLING; you can check errno to see what went wrong */
        a1->stop=false;
        //exit(1);
    }
    else
        qDebug()<<("Successfully connected to droplet generator!");

    if (ioctl(file,I2C_SLAVE,addr_droplet_separator) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to droplet separator.";
        /* ERROR HANDLING; you can check errno to see what went wrong */
        a1->stop=false;
        //exit(1);
    }
    else
        qDebug()<<("Successfully connected to droplet separator!");

    if (ioctl(file,I2C_SLAVE,addr_led_pmt) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to LED PMT.";
        /* ERROR HANDLING; you can check errno to see what went wrong */
        a1->stop=false;
        //exit(1);
    }
    else
        qDebug()<<("Successfully connected to LED PMT!");

    if (ioctl(file,I2C_SLAVE,addr_peristaltic) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to Peristaltic pump.";
        /* ERROR HANDLING; you can check errno to see what went wrong */
        a1->stop=false;
        //exit(1);
    }
    else
        qDebug()<<("Successfully connected to Peristaltic pump!");

    if (ioctl(file,I2C_SLAVE,addr_sample_injector) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to Sample Injector pump.";
        /* ERROR HANDLING; you can check errno to see what went wrong */
        a1->stop=false;
        //exit(1);
    }
    else
        qDebug()<<("Successfully connected to Sample Injector pump!");

    if (ioctl(file,I2C_SLAVE,addr_thermocycler) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to Thermocycler.";
        /* ERROR HANDLING; you can check errno to see what went wrong */
        a1->stop=false;
        //exit(1);
    }
    else
        qDebug()<<("Successfully connected to Thermocycler !");

    ui->rem_vol_1->setToolTip("Remaining Volume in Pump 1");
    ui->rem_vol_2->setToolTip("Remaining Volume in Pump 2");
    ui->rem_vol_3->setToolTip("Remaining Volume in Pump 3");
    ui->rem_vol_4->setToolTip("Remaining Volume in Pump 4");

    ui->start_stop_1->setToolTip("Start/Stop Pump 1");
    ui->start_stop_2->setToolTip("Start/Stop Pump 2");
    ui->start_stop_3->setToolTip("Start/Stop Pump 3");
    ui->start_stop_4->setToolTip("Start/Stop Pump 4");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void send_data()
{
    size=strlen(buf);
    char *temp={0};
    for(i=0;i<size;i++)
    {
        temp=&buf[i];
        if(write(file,temp,1)==1)
        {
            qDebug()<<"Value sent: "<<*temp;
        }
        else
            qDebug()<<"Value not sent: "<<*temp;
        usleep(70000);
    }

    if(read(file,buf1,80))
    {
        //ui->get_value->setText(buf);
        i=0;
        while(buf1[i]!='\n')
        {
            add.append(buf1[i]);

            i++;
        }
        i=0;
        qDebug()<<"Value received: "<<add;

    }
}

//void MainWindow::on_start_stop_clicked(bool checked)
//{
//    if(checked)
//    {
//        ui->start_stop->setText("STOP");
//        a1->stop=false;
//        a1->start();
//        if (ioctl(file,I2C_SLAVE,addr) < 0)
//        {
//            qDebug()<<"Failed to acquire bus access and/or talk to Mega.";
//            /* ERROR HANDLING; you can check errno to see what went wrong */
//            a1->stop=false;
//            //exit(1);
//        }
//        else
//            qDebug()<<("Successfully connected to UNO!");
//        char size=1;
//        char buf[20];
//        strcpy(buf,"STARTP");
//        size=strlen(buf);
//        char *temp={0};
//        //char size=sizeof(ui->set_value->text().toLatin1().data());
//        //char *buf[sizeof(ui->set_value->text().toLatin1().data())]={ui->set_value->text().toLatin1().data()};
//        for(i=0;i<size;i++)
//        {
//            temp=&buf[i];
//            if(write(file,temp,1)==1)
//            {
//                qDebug()<<"Value sent: "<<*temp;
//            }
//            else
//                qDebug()<<"Value not sent: "<<*temp;
//            usleep(70000);
//        }
//        char buf1[80]={0};
//        QString add;
//        if(read(file,buf1,80))
//        {
//            //ui->get_value->setText(buf);
//            i=0;
//            while(buf1[i]!='\n')
//            {
//                add.append(buf1[i]);

//                i++;
//            }
//            i=0;
//            qDebug()<<"Value received: "<<add;

//        }

//        //        usleep(70000);
//    }
//    else
//    {
//        ui->start_stop->setText("START");
//        a1->stop=true;
//        a1->start();
//        if (ioctl(file,I2C_SLAVE,addr) < 0)
//        {
//            qDebug()<<"Failed to acquire bus access and/or talk to Mega.";
//            /* ERROR HANDLING; you can check errno to see what went wrong */
//            a1->stop=false;
//            //exit(1);
//        }
//        else
//            qDebug()<<("Successfully connected to UNO!");
//        char size=1;
//        char buf[20];
//        strcpy(buf,"STOPPP");
//        size=strlen(buf);
//        char *temp={0};
//        //char size=sizeof(ui->set_value->text().toLatin1().data());
//        //char *buf[sizeof(ui->set_value->text().toLatin1().data())]={ui->set_value->text().toLatin1().data()};
//        for(i=0;i<size;i++){
//            temp=&buf[i];
//            if(write(file,temp,1)==1)
//            {
//                qDebug()<<"Value sent: "<<*temp;
//            }
//            else
//                qDebug()<<"Value not sent: "<<*temp;
//            usleep(70000);
//        }
//        char buf1[80]={0};
//        QString add;
//        if(read(file,buf1,80))
//        {
//            //ui->get_value->setText(buf);
//            i=0;
//            while(buf1[i]!='\n')
//            {
//                add.append(buf1[i]);

//                i++;
//            }
//            i=0;
//            qDebug()<<"Value received: "<<add;

//        }
//    }
//    //        usleep(70000);
//}


//void MainWindow::on_set1_clicked()
//{
//    if (ioctl(file,I2C_SLAVE,addr) < 0)
//    {
//        qDebug()<<"Failed to acquire bus access and/or talk to Mega.";
//        /* ERROR HANDLING; you can check errno to see what went wrong */
//        a1->stop=false;
//        //exit(1);
//    }
//    for(i=0;i<size;i++){
//    else
//        qDebug()<<("Successfully connected to UNO!");

//    char size=1;
//    char buf[20];
//    strcpy(buf,ui->set_value->text().toLatin1().data());
//    size=strlen(buf);
//    char *temp=NULL;
//    //char size=sizeof(ui->set_value->text().toLatin1().data());
//    //char *buf[sizeof(ui->set_value->text().toLatin1().data())]={ui->set_value->text().toLatin1().data()};
//        temp=&buf[i];
//        if(write(file,temp,1)==1)
//        {
//            qDebug()<<"Value sent: "<<*temp;
//        }
//        else
//            qDebug()<<"Value not sent: "<<*temp;
//        usleep(70000);
//    }
//}

//void MainWindow::on_get1_clicked()
//{
//    if (ioctl(file,I2C_SLAVE,addr) < 0)
//    {
//        qDebug()<<"Failed to acquire bus access and/or talk to Mega.";
//        /* ERROR HANDLING; you can check errno to see what went wrong */
//        a1->stop=false;
//        //exit(1);
//    }
//    else
//        qDebug()<<("Successfully connected to UNO!");
//    char buf[80]={0};
//    QString add;
//    if(read(file,buf,80))
//    {
//        //ui->get_value->setText(buf);
//        i=0;
//        while(buf[i]!='\n')
//        {
//            add.append(buf[i]);

//            i++;
//        }
//        i=0;
//        qDebug()<<"Value received: "<<add;

//    }


//}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->rotate(-10);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->rotate(10);
}

void MainWindow::on_start_stop_1_clicked(bool checked)
{
    if(checked)
    {
        ui->start_stop_1->setText("STOP");
        a1->stop=false;
        a1->start();
        if (ioctl(file,I2C_SLAVE,addr) < 0)
        {
            qDebug()<<"Failed to acquire bus access and/or talk to Mega.";
            /* ERROR HANDLING; you can check errno to see what went wrong */
            a1->stop=false;
            //exit(1);
        }
        else
            qDebug()<<("Successfully connected to UNO!");
        strcpy(buf,"STARTP");
        send_data();
    }
    else
    {
        ui->start_stop_1->setText("START");
        a1->stop=true;
        a1->start();
        if (ioctl(file,I2C_SLAVE,addr) < 0)
        {
            qDebug()<<"Failed to acquire bus access and/or talk to Mega.";
            /* ERROR HANDLING; you can check errno to see what went wrong */
            a1->stop=false;
            //exit(1);
        }
        else
            qDebug()<<("Successfully connected to UNO!");
        strcpy(buf,"STOPPP");
        send_data();
    }
}

void MainWindow::on_set_1_clicked()
{
    if (ioctl(file,I2C_SLAVE,addr) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to Mega.";
        /* ERROR HANDLING; you can check errno to see what went wrong */
        a1->stop=false;
        //exit(1);
    }
    else
        qDebug()<<("Successfully connected to UNO!");

    strcpy(buf,"FLWRTE");
    send_data();
    if(strcmp(add.toStdString().c_str(),"OK")==0)
    {
        strcpy(buf,ui->flow_rate_1->text().toStdString().c_str());
        send_data();
    }
    if(strcmp(add.toStdString().c_str(),"OK")==0)
    {
        strcpy(buf,"VOLDIS");
        send_data();
    }
    if(strcmp(add.toStdString().c_str(),"OK")==0)
    {
        strcpy(buf,ui->vol_to_dispense_1->text().toStdString().c_str());
        send_data();
    }

}

