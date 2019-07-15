#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    initJamLabelGroup();

    // 初始化表示拥堵状况的三种颜色的数组
    jam_level_color[0] = "background-color:rgb(0, 255, 0)"; // 绿
    jam_level_color[1] = "background-color:rgb(255, 170, 0)"; // 橙
    jam_level_color[2] = "background-color:rgb(255, 0, 0)"; // 红
    //设置标签透明度
//    QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
//    ui->label->setGraphicsEffect(opacityEffect);
//    opacityEffect->setOpacity(0.7);
}

Window::~Window()
{
    delete ui;
}


void Window::on_pushButton_clicked()
{
    qDebug() << "on_pushButton_clicked()";
    // 随机生成24各随机数，取值为0，1，2，分别对应畅通，轻微拥堵和拥堵三种拥堵等级。
    // 根据随机数设置对应路段表示道路拥堵状态的标签颜色
    qsrand((unsigned)time(NULL));
    for(int i = 0; i < 24; i++) {
        int r = (round(1.0 * rand() / RAND_MAX * (2 - 0) + 0));
        jam_level[i] = r; // 记录当前生成的所有路段的拥堵等级，供路径规划使用
        labels[i]->setStyleSheet(jam_level_color[r]);
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect;
        labels[i]->setGraphicsEffect(opacityEffect);
        opacityEffect->setOpacity(0.5);
    }




//    QGraphicsOpacityEffect *opacityEffect=new QGraphicsOpacityEffect;
//    QGraphicsOpacityEffect *opacityEffect1=new QGraphicsOpacityEffect;
//    labels[0]->setGraphicsEffect(opacityEffect1);
//    opacityEffect->setOpacity(0.7);
//    ui->label_5->setGraphicsEffect(opacityEffect);
//    opacityEffect1->setOpacity(0.7);
}

void Window::initJamLabelGroup()
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

}

void Window::routePlanning()
{
    // 根据当前路况信息规划最优路径


}

void Window::paintEvent(QPaintEvent *)
{
}


void Window::on_tabWidget_currentChanged(int index)
{
    // default index starts from 0
    if(index == 1) {
        for(int i = 0; i < 24; i++) {
            labels[i]->setStyleSheet("");
        }
    }
}
