#include "right.h"

Right::Right(QWidget *parent) : QWidget(parent)
{
    this->resize(300, 900);
//    this->setWindowIcon(QIcon(":/image/logo_new.png"));
    this->setWindowTitle(tr("智能小车"));
    // 控件对象生成
    state_view = new QGroupBox(this);
    state_view->setGeometry(QRect(0, 0, 140, 250));
//    car_label1 = new QLabel(state_view);
//    car_label2 = new QLabel(state_view);
//    light_label = new QLabel(state_view);
//    car_edit1 = new QLineEdit(state_view);
//    car_edit2 = new QLineEdit(state_view);
//    light_edit = new QLineEdit(state_view);

    map_view = new QGroupBox(this);
    map_view->setGeometry(QRect(160, 0, 140, 250));
//    flow_view = new QCheckBox(map_view);
//    cmd = new QLabel(map_view);
//    state = new QPushButton(map_view);

//    car_rad_btn1 = new QRadioButton(this);
//    car_rad_btn2 = new QRadioButton(this);

    plan_mode = new QTabWidget(this);
    plan_mode->setGeometry(0, 260, 300, 300);
//    path_view = new QTextBrowser(plan_mode);
//    start_btn = new QPushButton(plan_mode);
//    complete_btn = new QPushButton(plan_mode);

    park_lot = new QTabWidget(this);
    park_lot->setGeometry(0, 600, 300, 300);
//    car_lot1 = new QLabel(park_lot);
//    park_pos1 = new QLabel(park_lot);
//    car_select = new QComboBox(park_lot);
//    pos_select = new QComboBox(park_lot);
//    park_in_btn = new QPushButton(park_lot);

    // layout
//    h_layout = new QHBoxLayout;
//    h_rad_btn = new QHBoxLayout;
//    v_layout = new QVBoxLayout;

//    h_layout->addWidget(state_view);
//    h_layout->addWidget(map_view);

////    h_rad_btn->addWidget(car_rad_btn1);
////    h_rad_btn->addWidget(car_rad_btn2);

//    v_layout->addLayout(h_layout);
////    v_layout->addLayout(h_rad_btn);
//    v_layout->addWidget(plan_mode);
//    v_layout->addWidget(park_lot);
//    setLayout(v_layout);
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

