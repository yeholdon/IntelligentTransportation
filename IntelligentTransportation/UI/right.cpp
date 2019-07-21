#include "right.h"

Right::Right(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle(tr("智能小车"));
    this->setupUi(this);
    // 新加的ui
    avoid_jam_combo_box->setCurrentIndex(1);
    plan_mode_tab_widget->setCurrentIndex(0);
    pathPlan_2->setCurrentIndex(0);
    stop_start=new QPushButton(this);
    stop_start->setCheckable(true);
    voice_btn->setCheckable(true);

    initStyle();

    connect(pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
    connect(stop_start,SIGNAL(clicked(bool)),this,SLOT(changeStatus(bool)));
    connect(voice_btn,SIGNAL(clicked(bool)),this,SLOT(changeSound(bool)));
    //start_btn->setCursor(QCursor(Qt::PointingHandCursor));
   // complete_btn->setCursor(QCursor(Qt::PointingHandCursor));
    //select_st_pt_btn->setCursor(QCursor(Qt::PointingHandCursor));
    //select_end_pt_btn->setCursor(QCursor(Qt::PointingHandCursor));
    //begin_btn->setCursor(QCursor(Qt::PointingHandCursor));

//    pushButton->setStyleSheet("background:#c9c9c9;"
//                              "border:3px solid #c9c9c9;"
//                              "border-radius:100px");

    // 初始化Radio button group
    car_rad_btn_group = new QButtonGroup(this);
    car_rad_btn_group->addButton(car_rad_btn1, 1);
    car_rad_btn_group->addButton(car_rad_btn2, 2);
    car_rad_btn1->setChecked(true);
    cur_car_id = 1;
    // 绑定两个car_rad_btn的点击信号与slot
    connect(car_rad_btn1, SIGNAL(clicked()), this, SLOT(carRadBtnSlot()));
    connect(car_rad_btn2, SIGNAL(clicked()), this, SLOT(carRadBtnSlot()));
    // 绑定入库按钮和相应的操作
    connect(this, SIGNAL(parkCarIdPosSignal(int,int)), Background::getBgPtr(), SLOT(parkPlanSlot(int,int)));
    connect(this, SIGNAL(parkOutCarIdSignal(int, QString)), Background::getBgPtr(), SLOT(parkingOutSlot(int, QString)));
}

void Right::initStyle(){
    stop_start->setStyleSheet("QPushButton{"
                              "border-image:url(:/image/start.png);"
                              "border-radius:100%;}"
                              "QPushButton:pressed{"
                              "border:3px solid #008FFF;}");
    stop_start->setCursor(QCursor(Qt::PointingHandCursor));

    voice_btn->setStyleSheet("QPushButton{"
                              "border-image:url(:/image/sound.png);"
                              "border-radius:100%;}"
                              "QPushButton:pressed{"
                              "border:3px solid #008FFF;}");
    voice_btn->setCursor(QCursor(Qt::PointingHandCursor));



    start_btn->setCursor(QCursor(Qt::PointingHandCursor));
    start_btn->setStyleSheet("QPushButton{"
                              "border:2px solid #c9c9c9;"
                              "border-radius:8px}"
                              "QPushButton:hover{"
                              "border:2px solid #008FFF;}"
                              "QPushButton:pressed{"
                              "background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));"
                              "border-radius:5px;"
                              "border: 1px solid #5F92B2;}");

    complete_btn->setCursor(QCursor(Qt::PointingHandCursor));
    complete_btn->setStyleSheet("QPushButton{"
                              "border:2px solid #c9c9c9;"
                              "border-radius:8px}"
                              "QPushButton:hover{"
                              "border:2px solid #008FFF;}"
                              "QPushButton:pressed{"
                              "background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));"
                              "border-radius:5px;"
                              "border: 1px solid #5F92B2;}");

    select_st_pt_btn->setCursor(QCursor(Qt::PointingHandCursor));
    select_st_pt_btn->setStyleSheet("QPushButton{"
                              "border:2px solid #c9c9c9;"
                              "border-radius:8px}"
                              "QPushButton:hover{"
                              "border:2px solid #008FFF;}"
                              "QPushButton:pressed{"
                              "background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));"
                              "border-radius:5px;"
                              "border: 1px solid #5F92B2;}");

    select_end_pt_btn->setCursor(QCursor(Qt::PointingHandCursor));
    select_end_pt_btn->setStyleSheet("QPushButton{"
                              "border:2px solid #c9c9c9;"
                              "border-radius:8px}"
                              "QPushButton:hover{"
                              "border:2px solid #008FFF;}"
                              "QPushButton:pressed{"
                              "background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));"
                              "border-radius:5px;"
                              "border: 1px solid #5F92B2;}");

    begin_btn->setCursor(QCursor(Qt::PointingHandCursor));
    begin_btn->setStyleSheet("QPushButton{"
                              "border:2px solid #c9c9c9;"
                              "border-radius:8px}"
                              "QPushButton:hover{"
                              "border:2px solid #008FFF;}"
                              "QPushButton:pressed{"
                              "background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));"
                              "border-radius:5px;"
                              "border: 1px solid #5F92B2;}");

    pushButton->setCursor(QCursor(Qt::PointingHandCursor));
    pushButton->setStyleSheet("QPushButton{"
                              "border:2px solid #c9c9c9;"
                              "border-radius:8px}"
                              "QPushButton:hover{"
                              "border:2px solid #008FFF;}"
                              "QPushButton:pressed{"
                              "background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));"
                              "border-radius:5px;"
                              "border: 1px solid #5F92B2;}");
    pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
    pushButton_2->setStyleSheet("QPushButton{"
                                "border:2px solid #c9c9c9;"
                                "border-radius:8px}"
                                "QPushButton:hover{"
                                "border:2px solid #008FFF;}"
                                "QPushButton:pressed{"
                                "background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));"
                                "border-radius:5px;"
                                "border: 1px solid #5F92B2;}");

//    voice_btn->setStyleSheet("QPushButton{"
//                             "border:2px solid #c9c9c9;"
//                             "border-radius:8px}"
//                             "QPushButton:hover{"
//                             "border:2px solid #008FFF;}"
//                             "QPushButton:pressed{"
//                             "background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));"
//                             "border-radius:5px;"
//                             "border: 1px solid #5F92B2;}");
//    voice_btn->setCursor(QCursor(Qt::PointingHandCursor));
}

int Right::resizeWidth(int rewidth)
{
    return width()*rewidth/369;
}

int Right::resizeHeight(int reheight)
{
    return height()*reheight/781;
}

void Right::resizeEvent(QResizeEvent *event)
{
    stop_start->setGeometry(resizeWidth(239),resizeHeight(117),resizeWidth(51),resizeHeight(51));

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

void Right::changeStatus(bool status){
    if(status)
        stop_start->setStyleSheet("QPushButton{"
                                  "border-image:url(:/image/stop.png);"
                                  "border-radius:100%;}"
                                  "QPushButton:pressed{"
                                  "border:3px solid #008FFF;}");
    else
        stop_start->setStyleSheet("QPushButton{"
                                  "border-image:url(:/image/start.png);"
                                  "border-radius:100%;}"
                                  "QPushButton:pressed{"
                                  "border:3px solid #008FFF;}");
}

void Right::changeSound(bool status)
{
    if(status)
        voice_btn->setStyleSheet("QPushButton{"
                                  "border-image:url(:/image/soundClose.png);"
                                  "border-radius:100%;}"
                                  "QPushButton:pressed{"
                                  "border:3px solid #008FFF;}");
    else
        voice_btn->setStyleSheet("QPushButton{"
                                  "border-image:url(:/image/sound.png);"
                                  "border-radius:100%;}"
                                  "QPushButton:pressed{"
                                  "border:3px solid #008FFF;}");
}

//入库
void Right::on_pushButton_clicked(){
    QString string0=pos_select_combo_box->currentText();
    int index=string0.right(1).toInt();
    QString string1=car_select_combo_box->currentText();
    int carID=string1.right(1).toInt();
    // 发送停车入库指令，车号和车位号
    emit parkCarIdPosSignal(carID, index);
}

//出库
void Right::on_pushButton_2_clicked(){
   QString string=car_select2_combo_box->currentText();
   int carID=string.right(1).toInt();
   // 发送出库指令，车号以及目标点编号
   emit parkOutCarIdSignal(carID, lineEdit->text());
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

