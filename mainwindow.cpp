#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(Network::getNetPtr(),SIGNAL(sendDataWindow(QJsonObject)),
            this,SLOT(receiveNetDataSLOT(QJsonObject)));
    // 设置窗口大小固定, 先实现功能，有需要再改自适应
    this->setFixedSize(this->width(), this->height());
    this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    // 初始情况的随机生成按钮不可用
    ui->generate_jam_btn->setVisible(false);
    ui->generate_jam_btn->setEnabled(false);
    initJamLabelGroup();
    initCrossingGroup();
    // 初始化表示拥堵状况的三种颜色的数组
    jam_level_color[0] = "background-color:rgb(0, 255, 0)"; // 绿
    jam_level_color[1] = "background-color:rgb(0, 0, 255)"; // 橙
    jam_level_color[2] = "background-color:rgb(255, 0, 0)"; // 红
    initCaronline();
    initCarTimer();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] opacityEffect;
}

void MainWindow::initJamLabelGroup()
{
    labels[0] = ui->label;
    labels[1] = ui->label_2;
    labels[2] = ui->label_3;
    labels[3] = ui->label_4;
    labels[4] = ui->label_5;
    labels[5] = ui->label_6;
    labels[6] = ui->label_7;
    labels[7] = ui->label_8;
    labels[8] = ui->label_9;
    labels[9] = ui->label_10;
    labels[10] = ui->label_11;
    labels[11] = ui->label_12;
    labels[12] = ui->label_13;
    labels[13] = ui->label_14;
    labels[14] = ui->label_15;
    labels[15] = ui->label_16;
    labels[16] = ui->label_17;
    labels[17] = ui->label_18;
    labels[18] = ui->label_19;
    labels[19] = ui->label_20;
    labels[20] = ui->label_21;
    labels[21] = ui->label_22;
    labels[22] = ui->label_23;
    labels[23] = ui->label_24;
    labels[24] = ui->label_25;
    labels[25] = ui->label_26;
    labels[26] = ui->label_27;
    labels[27] = ui->label_28;
    labels[28] = ui->label_29;
    labels[29] = ui->label_30;
    labels[30] = ui->label_31;
    labels[31] = ui->label_32;

    opacityEffect = new QGraphicsOpacityEffect[ROAD_NUM];


}

void MainWindow::initCrossingGroup()
{
    crossing[0] = ui->crossing_1;
    crossing[1] = ui->crossing_2;
    crossing[2] = ui->crossing_3;
    crossing[3] = ui->crossing_4;
    crossing[4] = ui->crossing_5;
    crossing[5] = ui->crossing_6;
    crossing[6] = ui->crossing_7;
    crossing[7] = ui->crossing_8;
    crossing[8] = ui->crossing_9;
    crossing[9] = ui->crossing_10;
    crossing[10] = ui->crossing_11;
    crossing[11] = ui->crossing_12;

    for(int i = 0; i < CROSSING_NUM; i++) {
        crossing[i]->setVisible(false);
        crossing[i]->setEnabled(false);
    }
    for(int i; i < ROAD_NUM; i++) {
        labels[i]->setStyleSheet("background:tansparent;");
    }
}

void MainWindow::initCaronline()
{
    number_carOnline = 3;
    for(int i = 0;i<5;i++)
    {
        carOnline[i] = 0;
    }
}

void MainWindow::initCarTimer()
{
    carTimer = new QTimer;
    carTimer->setTimerType(Qt::PreciseTimer);
    //信号与槽函数的绑定
    connect(carTimer,SIGNAL(timeout()),this,SLOT(carTimerSlot()));
    carTimer->start(2000);
}

void MainWindow::receiveNetDataSLOT(const QJsonObject &json)
{
    //根据json数据包来改变界面
    int type = json.value("type").toInt();
    //使用定时器来判断心跳包  ？？？
    if(type == 1)
    {
        qDebug()<<"1号小车的心跳包";
        carOnline[1] = 3;
    }
    else if(type == 2)
    {
        qDebug()<<"2号小车的心跳包";
        carOnline[2] = 3;
    }
    else if(type == 3)
    {
        QString data = json.value("rfid").toString();
        qDebug()<<"1号小车的位置卡号："<<data;
    }
    else if(type == 4)
    {
        QString data = json.value("rfid").toString();
        qDebug()<<"2号小车的位置卡号："<<data;
    }
    //交通灯
    else if(type == 5)
    {
        QString data = json.value("lightcolor").toString();
        qDebug()<<"交通灯的状态为："<<data;

    }
    else
    {
        qDebug()<<"mainwindow：客户端无法解析该类型的json数据包";
    }
}

void MainWindow::carTimerSlot()
{
    if(carOnline[1] == 0)
    {
        ui->label->setStyleSheet("background-color:red;");
    }
    else
    {
        carOnline[1]--;
        if(carOnline[1] == 0)
        {
            ui->label->setStyleSheet("background-color:red;");
        }
        else
        {
             ui->label->setStyleSheet("background-color:green;");
        }
    }
    if(carOnline[2] == 0)
    {
        ui->label_21->setStyleSheet("background-color:red;");
    }
    else
    {
        carOnline[2]--;
        if(carOnline[2] == 0)
        {
            ui->label_21->setStyleSheet("background-color:red;");
        }
        else
        {
             ui->label_21->setStyleSheet("background-color:green;");
        }
    }

}



