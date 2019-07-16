#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置窗口大小固定, 先实现功能，有需要再改自适应
    this->setFixedSize(this->width(), this->height());
    this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    // 初始情况的随机生成按钮不可用
    ui->generate_jam_btn->setVisible(false);
    ui->generate_jam_btn->setEnabled(false);
    // 初始化拥堵标签和路口按钮
    initJamLabelGroup();
    initCrossingGroup();
    // 初始化表示拥堵状况的三种颜色的数组
    jam_level_color[0] = "background-color:rgb(0, 255, 0)"; // 绿
    jam_level_color[1] = "background-color:rgb(255, 170, 0)"; // 橙
    jam_level_color[2] = "background-color:rgb(255, 0, 0)"; // 红

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
        connect(crossing[i], SIGNAL(clicked(bool)), this, SLOT(crossing_clicked(bool)));
    }
}


void MainWindow::on_avoid_jam_checkbox_stateChanged(int arg1)
{
    if(arg1 == 0) {
        // unchecked, 按钮不可见
        ui->generate_jam_btn->setVisible(false);
        ui->generate_jam_btn->setEnabled(false);
    }
    else
    {
        ui->generate_jam_btn->setVisible(true);
        ui->generate_jam_btn->setEnabled(true);
    }
}

void MainWindow::on_begin_clicked()
{
    for(int i = 0; i < CROSSING_NUM; i++) {
        crossing[i]->setVisible(true);
        crossing[i]->setEnabled(true);
    }
}

void MainWindow::crossing_clicked(bool b)
{
    QPushButton *pressed_btn = (QPushButton *)sender();
    pressed_btn->setFlat(false);
    pressed_btn->setStyleSheet("background:red;");
    vec.append(pressed_btn);
}

void MainWindow::on_cancel_clicked()
{
    for(int i = 0; i < vec.size(); i++) {
        vec[i]->setStyleSheet("background:transparent;");
    }
    vec.clear();
}

void MainWindow::on_finish_clicked()
{
    for(int i = 0; i < CROSSING_NUM; i++) {
        crossing[i]->setVisible(false);
        crossing[i]->setEnabled(false);
    }
//    for(int i = 0; i < vec.size(); i++) {
//        crossing[i]->setVisible(true);
//        crossing[i]->setEnabled(true);
////        crossing[i]->setFlat(false);
//        crossing[i]->setStyleSheet("background:red;");
//    }

}
