#include "widget.h"
//#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)

{
    this->resize(1024,768);
    //this->resize(1920,1080);
    this->setWindowIcon(QIcon(":/image/logo_new.png"));
    this->setWindowTitle(tr("智能小车"));
    initPage();
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

    connect(right->startButton,SIGNAL(clicked()),body,SLOT(on_manualButton_clicked()));
    connect(right->roadConButton,SIGNAL(clicked()),body,SLOT(on_roadConButton_clicked()));

    connect(bottom,SIGNAL(autoStart(int,int)),body,SLOT(on_autoButton_clicked(int,int)));
    v=new QVBoxLayout;
    v->addWidget(body);
    v->addWidget(bottom);
    h=new QHBoxLayout;
    h->addLayout(v);
    h->addWidget(right);
}

int Widget::resizeWidth(int rewidth)
{
    return width()*rewidth/1024;
}

int Widget::resizeHeight(int reheight)
{
    return height()*reheight/768;
}


void Widget::resizeEvent(QResizeEvent *event)
{
    bottom->setGeometry(0,resizeHeight(567),resizeWidth(805),resizeHeight(201));
    body->setGeometry(0,0,resizeWidth(805),resizeHeight(567));
    //right->setGeometry(resizeWidth(805),0,resizeWidth(219),resizeHeight(696));
    right->setGeometry(resizeWidth(805),0,resizeWidth(219),resizeHeight(768));
}

void Widget::outtimeSlot(int carId, bool flag)
{

}


