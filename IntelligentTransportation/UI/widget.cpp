#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)

{
    this->resize(1024,768);
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
    right->setGeometry(resizeWidth(805),0,resizeWidth(219),resizeHeight(696));
}
