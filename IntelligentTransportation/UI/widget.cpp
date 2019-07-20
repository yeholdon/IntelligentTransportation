#include "widget.h"
//#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)

{
    //this->resize(909*W,600*H);
    this->resize(1494,781);
    this->setWindowIcon(QIcon(":/image/logo_new.png"));
    this->setWindowTitle(tr("智能小车"));
    initPage();
    connectSignal();


}

Widget::~Widget()
{

}

void Widget::initPage()
{
   // bottom=new Bottom(this);

    //bottom->setStyleSheet("border-image:url(:/image/2233login.af9c53d.png);");
    body=new Body(this);
    right=new Right(this);
    h=new QHBoxLayout;
    h->addWidget(body);
    h->addWidget(right);
}

int Widget::resizeWidth(int rewidth)
{
    return width()*rewidth/1494;
}

int Widget::resizeHeight(int reheight)
{
    return height()*reheight/781;
}

void Widget::resizeEvent(QResizeEvent *event)
{
//    bottom->setGeometry(0,resizeHeight(567),resizeWidth(805),resizeHeight(201));
    body->setGeometry(0,0,resizeWidth(1120),resizeHeight(781));
    right->setGeometry(resizeWidth(1120),0,resizeWidth(369),resizeHeight(781));
}

void Widget::connectSignal(){
    connect(right->start_btn,SIGNAL(clicked()),body,SLOT(manualChoiceSlot()));//手动模式开始点击,设置可点击按钮
    connect(right->complete_btn,SIGNAL(clicked()),body,SLOT(on_manualButton_clicked())); //手动模式点击完成
    connect(body,SIGNAL(routeView(const QString&)),right,SLOT(viewRouteSlot(const QString&)));//手动模式点击完成后显示路线
    connect(right->select_st_pt_btn,SIGNAL(clicked()),body,SLOT(autoStartpointSlot()));//导航起点
    connect(right->select_end_pt_btn,SIGNAL(clicked()),body,SLOT(autoEndpointSlot())); //导航终点
    connect(right->begin_btn,SIGNAL(clicked()),body,SLOT(on_autoButton_clicked()));//自动模式点击完成
    connect(right->avoid_jam_combo_box,SIGNAL(currentIndexChanged(int)),body,SLOT(roadConSlot(int)));

    // 与background的通信
    // 手动模式的路口vec
    connect(body, SIGNAL(crossingSignal(QVector<int>)), Background::getBgPtr(), SLOT(manuPlanSlot(QVector<int>)));
    // 当前控制的小车号
//    connect(body, SIGNAL(carIdSignal(int)), Background::getBgPtr(), SLOT(carNumSlot(int)));
    // 自动模式的路口编号vec
    connect(body, SIGNAL(autoPlanCrossingSignal(QVector<int>)), Background::getBgPtr(), SLOT(routePlanSlot(QVector<int>)));
    // 生成拥堵情况
    connect(body, SIGNAL(roadConditionSignal(int*,int)), Background::getBgPtr(), SLOT(jamLevelSlot(int*,int)));
    // 当前选择的小车编号
    connect(right, SIGNAL(curCarIdSignal(int)), Background::getBgPtr(), SLOT(carNumSlot(int)));
}
