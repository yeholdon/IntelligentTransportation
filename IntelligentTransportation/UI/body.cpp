#include "body.h"

Body::Body(QWidget *parent) : QWidget(parent)
{
  initButtonGroup();
  initLayout();

}

void Body::initButtonGroup()
{
    btnGroup=new QButtonGroup(this);
    for(int i=0;i<12;i++){
        QPushButton *btn=new QPushButton(QString::number(i+1),this);
        /*btn->set(true);//设置扁平化*/
        btn->setStyleSheet("background:transparent;"
                           "color:#FFFFFF;"
                           "font-weight:700;"
                           "font-style:bold");
        btn->setCursor(QCursor(Qt::PointingHandCursor));
        btnGroup->addButton(btn,i);
    }
    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(btnGroupSlot(int)));
}

void Body::initLayout()
{
    //水平布局
    h1=new QHBoxLayout;
    h1->addWidget(btnGroup->button(0));
    h1->addStretch();//加弹簧
    h1->addWidget(btnGroup->button(1));
    h1->addStretch();
    h1->addWidget(btnGroup->button(2));
    h1->addStretch();
    h1->addWidget(btnGroup->button(3));

    h2=new QHBoxLayout;
    h2->addWidget(btnGroup->button(4));
    h2->addStretch();//加弹簧
    h2->addWidget(btnGroup->button(5));
    h2->addStretch();
    h2->addWidget(btnGroup->button(6));
    h2->addStretch();
    h2->addWidget(btnGroup->button(7));


    h3=new QHBoxLayout;
    h3->addWidget(btnGroup->button(8));
    h3->addStretch();//加弹簧
    h3->addWidget(btnGroup->button(9));
    h3->addStretch();
    h3->addWidget(btnGroup->button(10));
    h3->addStretch();
    h3->addWidget(btnGroup->button(11));

    //垂直布局
    v1=new QVBoxLayout;
    v1->setMargin(0);
    v1->addLayout(h1);
    v1->addStretch();
    v1->addLayout(h2);
    v1->addStretch();
    v1->addLayout(h3);

    this->setLayout(v1);
}

void Body::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    QRect target(0,0,this->width(),this->height());
    p.drawImage(target,QImage(":/image/mymap.png"));
}

void Body::resizeEvent(QResizeEvent *event)
{
    for(int i=0;i<12;i++){
        btnGroup->button(i)->setFixedSize(width()/14,height()/11);
    }
}
