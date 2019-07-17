#include "right.h"

Right::Right(QWidget *parent) : QWidget(parent)
{
   initButton();
   initLabel();
}

int Right::resizeWidth(int rewidth)
{
    return width()*rewidth/219;
}

int Right::resizeHeight(int reheight)
{
    return height()*reheight/696;
}

void Right::initButton()
{
    roadCon_Button=new QPushButton("路况生成",this);//"border-width:1px;border-style:solid;border-color:rgba(121,121,121,1);"
    roadCon_Button->setStyleSheet("font-style:normal;"
                                  "font-size:23px;"
                                  "color:#333333;"
                                  "text-align:center;"
                                  "line-height:normal;"
                                  "background-color:rgba(255,255,255,1);"
                                  "border:1px solid #979797"
                                  "border-radius:5px;"
                                  "box:shadow:none;");
    roadCon_Button->setCursor(QCursor(Qt::PointingHandCursor));

    start_Button=new QPushButton("开始",this);//background-color:buttonface;"border-image:initial;"
    start_Button->setStyleSheet("font-style:normal;"
                                "font-size:23px;"
                                "color:#333333;"
                                "border-width:2px;"
                                "border-style:outset;"
                                "border-color:buttonface;"
                                );
    start_Button->setCursor(QCursor(Qt::PointingHandCursor));

    stop_Button=new QPushButton("暂停",this);
    stop_Button->setStyleSheet("font-style:normal;"
                               "font-size:23px;"
                               "color:#333333;"
                               "text-align:center;"
                               "border-image:url(:/images/u18.png);"
                               "line-height:normal;");
    stop_Button->setCursor(QCursor(Qt::PointingHandCursor));

}

void Right::initLabel()
{
    remind_Label=new QLabel("点击路口"
                            "手动规划",this);

    //设置自动换行
    remind_Label->setWordWrap(true);
    remind_Label->setAlignment(Qt::AlignTop);

    remind_Label->setStyleSheet("background:#99CCFF;"
                                "border:none;"
                                "border-radius:0px;"
                                "box-shadow:none;"
                                "border-width:0px;"
                                "word-wrap:break-word;"
                                "font-weight:400;"
                                "font-style:normal;"
                                "font-size:23px;"
                                "color:#333333;"
                                "line-height:normal;");
    //remind_Label->setStyleSheet("QLabel{background:#99C6FF;}");
    remind_Label->setAlignment(Qt::AlignCenter);

    roadCon_Label0=new QLabel("非常拥堵",this);
    roadCon_Label0->setStyleSheet("font-weight:700;"
                                  "font-style:bold;"
                                  "font-size:17px;"
                                  "color:#333333;");
    roadCon_Label0->setWordWrap(true);
    roadCon_Label0->setAlignment(Qt::AlignTop);

    roadCon_Label1=new QLabel("一般拥堵",this);
    roadCon_Label1->setWordWrap(true);
    roadCon_Label1->setAlignment(Qt::AlignTop);
    roadCon_Label1->setStyleSheet("font-weight:700;"
                                  "font-style:bold;"
                                  "font-size:17px;"
                                  "color:#333333;");

    roadCon_Label2=new QLabel("不拥堵",this);
    roadCon_Label2->setWordWrap(true);
    roadCon_Label2->setAlignment(Qt::AlignTop);
    roadCon_Label2->setStyleSheet("font-weight:700;"
                                  "font-style:bold;"
                                  "font-size:17px;"
                                  "color:#333333;");


}

void Right::resizeEvent(QResizeEvent *event)
{
    roadCon_Button->setGeometry(resizeWidth(28),resizeHeight(240),resizeWidth(173),resizeHeight(41));
    start_Button->setGeometry(resizeWidth(0),resizeHeight(513),resizeWidth(219),resizeHeight(52));
    stop_Button->setGeometry(resizeWidth(0),resizeHeight(612),resizeWidth(102),resizeHeight(84));
    remind_Label->setGeometry(resizeWidth(18),resizeHeight(368),resizeWidth(184),resizeHeight(112));
    roadCon_Label0->setGeometry(resizeWidth(102),resizeHeight(10),resizeWidth(70),resizeHeight(40));
    roadCon_Label1->setGeometry(resizeWidth(102),resizeHeight(92),resizeWidth(70),resizeHeight(40));
    roadCon_Label2->setGeometry(resizeWidth(102),resizeHeight(168),resizeWidth(70),resizeHeight(40));
}

void Right::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen;
    pen.setWidth(5);//5个像素点
    pen.setColor(QColor(Qt::red));
    p.setPen(pen);
    p.drawLine(0,resizeHeight(17),resizeWidth(67),resizeHeight(17));
    pen.setWidth(5);//5个像素点
    pen.setColor(QColor(0xFF,0x80,0x00));
    p.setPen(pen);
    p.drawLine(0,resizeHeight(97),resizeWidth(67),resizeHeight(97));
    pen.setWidth(5);//5个像素点
    pen.setColor(QColor(Qt::green));
    p.setPen(pen);
    p.drawLine(0,resizeHeight(171),resizeWidth(67),resizeHeight(171));
}
