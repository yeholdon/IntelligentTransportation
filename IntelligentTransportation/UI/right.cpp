#include "right.h"

Right::Right(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle(tr("智能小车"));
    this->setupUi(this);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
    start_btn->setCursor(QCursor(Qt::PointingHandCursor));
    complete_btn->setCursor(QCursor(Qt::PointingHandCursor));
    select_st_pt_btn->setCursor(QCursor(Qt::PointingHandCursor));
    select_end_pt_btn->setCursor(QCursor(Qt::PointingHandCursor));
    begin_btn->setCursor(QCursor(Qt::PointingHandCursor));

    pushButton->setCursor(QCursor(Qt::PointingHandCursor));
    pushButton->setStyleSheet("background:#c9c9c9;"
                              "border:3px solid #c9c9c9;"
                              "border-radius:100px");
    pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));

    // 初始化Radio button group
    car_rad_btn_group = new QButtonGroup(this);
    car_rad_btn_group->addButton(car_rad_btn1, 1);
    car_rad_btn_group->addButton(car_rad_btn2, 2);
    car_rad_btn1->setChecked(true);
    cur_car_id = 1;
    // 绑定两个car_rad_btn的点击信号与slot
    connect(car_rad_btn1, SIGNAL(clicked()), this, SLOT(carRadBtnSlot()));
    connect(car_rad_btn2, SIGNAL(clicked()), this, SLOT(carRadBtnSlot()));

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



//入库
void Right::on_pushButton_clicked(){
    QString string0=pos_select_combo_box->currentText();
    int index=string0.right(1).toInt();
    QString string1=car_select_combo_box->currentText();
    int carID=string1.right(1).toInt();
}

//出库
void Right::on_pushButton_2_clicked(){
   QString string=car_select2_combo_box->currentText();
   int carID=string.right(1).toInt();
}

void Right::carRadBtnSlot()
{

    switch (car_rad_btn_group->checkedId()) {
    case 1:
        cur_car_id = 1;
        break;
    case 2:
        cur_car_id = 2;
    default:
        break;
    }
    qDebug() << "carRadBtnSlot" << cur_car_id;
    emit curCarIdSignal(cur_car_id);
}
//显示路线
void Right::viewRouteSlot(const QString& routeString){
    path_view_text_brow->clear();
    path_view_text_brow->append(routeString);
}

