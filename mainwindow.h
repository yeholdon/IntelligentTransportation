#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsOpacityEffect>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QVector>

#include "Network/network.h"
#include "Network/protocol.h"
#include "Route/route.h"

const qint32 ROAD_NUM = 32;
const qint32 CROSSING_NUM = 12;



namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *labels[ROAD_NUM];
    QPushButton *crossing[CROSSING_NUM]; // 路口按钮
    int jam_level[ROAD_NUM];
    QString jam_level_color[3];
    QGraphicsOpacityEffect *opacityEffect;

    QVector<QPushButton *> vec;// 存手动规划的点


    //新增
    //心跳包信号量
    int carOnline[5];
    //信号量初始值
    int number_carOnline;
    //心跳包定时器
    QTimer *carTimer;

public:
    void initJamLabelGroup();
    void initCrossingGroup();

    //新增
    //心跳包信号量初始化
    void initCaronline();
    //心跳包定时器初始化
    void initCarTimer();

signals:

public slots:
    void receiveNetDataSLOT(const QJsonObject& json);       ////根据json数据包来改变界面

    //新增
    void carTimerSlot();
};

#endif // MAINWINDOW_H
