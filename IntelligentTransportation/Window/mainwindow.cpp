#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initJamLabelGroup();

    // 初始化表示拥堵状况的三种颜色的数组
    jam_level_color[0] = "background-color:rgb(0, 255, 0)"; // 绿
    jam_level_color[1] = "background-color:rgb(255, 170, 0)"; // 橙
    jam_level_color[2] = "background-color:rgb(255, 0, 0)"; // 红



}

MainWindow::~MainWindow()
{
    delete ui;

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

    for(int i; i < ROAD_NUM; i++) {
        labels[i]->setStyleSheet("background:tansparent;");
    }
}

void MainWindow::routePlanningAvoidJam()
{
    // 路径规划算法，躲避拥堵
}

void MainWindow::routePlanningShortestPath()
{
    // 路径规划算法，最短路径
}

void MainWindow::on_pushButton_clicked()
{
    // 随机生成拥堵按钮槽函数
    qDebug() << "on_pushButton_clicked()";
    // 随机生成24各随机数，取值为0，1，2，分别对应畅通，轻微拥堵和拥堵三种拥堵等级。
    // 根据随机数设置对应路段表示道路拥堵状态的标签颜色
    qsrand((unsigned)time(NULL));
    for(int i = 0; i < ROAD_NUM; i++) {
        int r = (round(1.0 * rand() / RAND_MAX * (3 - 0) - 0.5));
        jam_level[i] = r; // 记录当前生成的所有路段的拥堵等级，供路径规划使用
        labels[i]->setStyleSheet(jam_level_color[r]);
        labels[i]->setGraphicsEffect(&opacityEffect[i]);
        opacityEffect[i].setOpacity(1.0);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    // 自动规划路径槽函数
    // 运行路径规划算法
    // 可以由用户设置为躲避拥堵模式
    // “躲避拥堵”模式下，优先选取拥堵情况最好的路径，最优路径不唯一，
    // 则选取最短的一条，若还不唯一，则随机选取一条。
    // 普通模式，则优先选取最短路径，其余同“躲避拥堵模式”
    if(ui->checkBox->checkState()) {
        // 躲避拥堵模式
        routePlanningAvoidJam();
    }
    else
    {
        // 最短路径优先模式
        routePlanningShortestPath();
    }
}
