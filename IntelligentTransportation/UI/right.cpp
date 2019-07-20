#include "right.h"

Right::Right(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle(tr("智能小车"));
    this->setupUi(this);

    // 手动规划开始按钮，点击后发送给body，boby 使能路口按钮
    connect(start_btn, SIGNAL(clicked()), this, SIGNAL(manuPlanStartSignal()));
}



int Right::resizeWidth(int rewidth)
{
    return width()*rewidth/300;
}

int Right::resizeHeight(int reheight)
{
    return height()*reheight/900;
}

void Right::resizeEvent(QResizeEvent *event)
{

}

void Right::receiveCarOnlineSlot(int car_number, bool flag)
{
    // 接收到心跳包数据，操作相应控件显示小车在线信息
    if(car_number == 1)
    {
        if(flag == true)
        {
            car_view_label1->setText("在线");
        }
        else
        {
            QMessageBox::information(this, "提醒", "小车1已离线！", QMessageBox::Ok, QMessageBox::NoButton);
            car_view_label1->setText("离线");
        }
    }
    else if(car_number == 2) {
        if(flag == true)
        {
            car_view_label2->setText("在线");
        }
        else
        {
            QMessageBox::information(this, "提醒", "小车2已离线！", QMessageBox::Ok, QMessageBox::NoButton);
            car_view_label2->setText("离线");
        }
    }



}

void Right::receiveLightColor(QString color)
{
    if(color == "red") {
        car_view_label3->setText("红");
    }
    else if(color == "green")
    {
        car_view_label3->setText("绿");
    }
}

