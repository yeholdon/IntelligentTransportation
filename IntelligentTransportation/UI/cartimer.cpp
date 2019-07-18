#include "cartimer.h"

CarTimer::CarTimer(QObject *parent) : QObject(parent)
{
    connect(Background::getBgPtr(),SIGNAL(carOnline(int)),
            this,SLOT(carOnlineSlot(int)));
}

void CarTimer::initAll()
{
    initCaronline();
    initCarTimer();
}

void CarTimer::initCaronline()
{
    number_carOnline = 5;
    for(int i = 0;i<5;i++)
    {
        carOnline[i] = 0;
    }
}

void CarTimer::initCarTimer()
{
    carTimer = new QTimer;
    carTimer->setTimerType(Qt::PreciseTimer);
    //信号与槽函数的绑定
    connect(carTimer,SIGNAL(timeout()),this,SLOT(carTimerSlot()));
    carTimer->start(2000);
}

void CarTimer::carTimerSlot()
{
    if(carOnline[1] == 0)
    {
    }
    else
    {
        carOnline[1]--;
        if(carOnline[1] == 0)
        {
            emit sendToWindowCarOnline(1,false);
        }
        else
        {
             emit sendToWindowCarOnline(1,true);
        }
    }
    if(carOnline[2] == 0)
    {
    }
    else
    {
        carOnline[2]--;
        if(carOnline[2] == 0)
        {
            emit sendToWindowCarOnline(2,false);
        }
        else
        {
            emit sendToWindowCarOnline(2,true);
            //ui->label_21->setStyleSheet("background-color:green;");
        }
    }

}

void CarTimer::carOnlineSlot(int car)
{
    carOnline[car] = number_carOnline;
}





