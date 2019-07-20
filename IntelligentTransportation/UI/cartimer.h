#ifndef CARTIMER_H
#define CARTIMER_H

#include <QObject>
#include "body.h"     //改成body
#include "Background/background.h"
#include <QTimer>
class CarTimer : public QObject
{
    Q_OBJECT
public:
    explicit CarTimer(QObject *parent = nullptr);
    void initAll();
    //心跳包信号量初始化
    void initCaronline();
    //心跳包定时器初始化
    void initCarTimer();

signals:
    void sendToWindowCarOnline(int car_number,bool flag);
public slots:
    void carTimerSlot();
    void carOnlineSlot(int car);
private:
    //心跳包信号量
    int carOnline[5];
    //信号量初始值
    int number_carOnline;
    //心跳包定时器
    QTimer *carTimer;
};

#endif // CARTIMER_H
