#include "widget.h"
//#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)

{
    this->resize(1200,790);
    this->setWindowIcon(QIcon(":/image/logo_new.png"));
    this->setWindowTitle(tr("智能小车"));
    initPage();
    // 小车在线状态
    connect(Background::getBgPtr(), SIGNAL(carOnline(int)), cartimer, SLOT(carOnlineSlot(int)));
    connect(cartimer, SIGNAL(sendToWindowCarOnline(int,bool)), right, SLOT(receiveCarOnlineSlot(int, bool)));
    // 交通灯状态
    connect(Background::getBgPtr(), SIGNAL(lightColor(QString)), right, SLOT(receiveLightColor(QString)));
    // 手动规划的路径显示
    connect(right, SIGNAL(manuPlanStartSignal()), body, SLOT());
}

Widget::~Widget()
{

}

void Widget::initPage()
{
    bottom=new Bottom(this);

    //bottom->setStyleSheet("border-image:url(:/image/2233login.af9c53d.png);");
    body=new Body(this);
    right=new Right(this);

    v=new QVBoxLayout;
    v->addWidget(body);
    v->addWidget(bottom);
    h=new QHBoxLayout;
    h->addLayout(v);
    h->addWidget(right);

    // 初始化页面的时候开始定时，接收carOnline信号，判断小车是否在线
    cartimer = new CarTimer;
    cartimer->initAll();
}

int Widget::resizeWidth(int rewidth)
{
    return width()*rewidth/1200;
}

int Widget::resizeHeight(int reheight)
{
    return height()*reheight/790;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    bottom->setGeometry(0,resizeHeight(567),resizeWidth(805),resizeHeight(201));
    body->setGeometry(0,0,resizeWidth(805),resizeHeight(567));
    right->setGeometry(resizeWidth(805),0,resizeWidth(369),resizeHeight(790));
}
