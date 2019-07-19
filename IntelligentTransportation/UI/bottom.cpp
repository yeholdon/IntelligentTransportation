#include "bottom.h"

Bottom::Bottom(QWidget *parent) : QWidget(parent)
{
    //this->setStyleSheet("background:url(:/image/2233login.af9c53d.png);" );

    initLabel();
    inittext();
    initButton();
    connect(autostart_Button, SIGNAL(clicked()), this, SLOT(autoPlan()));
    connect(this, SIGNAL(autoPlanSignal(int, int)), Background::getBgPtr(), SLOT(begEndSlot(int, int)));

}

void Bottom::initLabel()
{
    auto_Label=new QLabel(this);
    auto_Label->setWordWrap(true);
    auto_Label->setAlignment(Qt::AlignTop);
    //auto_Label->setGeometry(267,46,108,110);
    auto_Label->setStyleSheet("border-image:url(:/image/u5.png);"
                              "color: #FFFFFF;"
                              "font-family: 'Arial Normal', 'Arial';"
                              "font-style: normal;"
                              "font-size:23px;"

                             );
    auto_Label->setAlignment(Qt::AlignCenter);
    auto_Label->setText(tr("自动规划"));

}

void Bottom::inittext()
{
    start_text=new QLineEdit(this);
    start_text->setPlaceholderText("起点");
    //start_text->setGeometry(390,45,58,37);
    start_text->setStyleSheet("font-style:normal;"
                         "font-size:23px;"
                         "color:#000000");

    end_text=new QLineEdit(this);
    end_text->setPlaceholderText("终点");
    //end_text->setGeometry(390,117,58,37);
    end_text->setStyleSheet("font-style:normal;"
                              "font-size:23px;"
                              "color:#000000");

}

void Bottom::initButton()
{
    autostart_Button=new QPushButton("开始",this);
    //autostart_Button->setGeometry(465,82,67,37);
    autostart_Button->setStyleSheet("font-style:normal;"
                                    "font-size:23px;"
                                    "color:#333333;"
                                    "text-algin:center");
    autostart_Button->setCursor(QCursor(Qt::PointingHandCursor));

}

int Bottom::resizeWidth(int rewidth)
{
    return width()*rewidth/805;
}

int Bottom::resizeHeight(int reheight)
{
    return height()*reheight/201;
}

void Bottom::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    QRect target(0,0,this->width(),this->height());
    p.drawImage(target,QImage(":/images/2233login.af9c53d.png"));
    p.drawImage(target,QImage(":/images/white_60.png"));
}

void Bottom::resizeEvent(QResizeEvent *event)
{
    auto_Label->setGeometry(resizeWidth(267),resizeHeight(46),resizeWidth(108),resizeHeight(110));
    start_text->setGeometry(resizeWidth(390),resizeHeight(45),resizeWidth(58),resizeHeight(37));
    end_text->setGeometry(resizeWidth(390),resizeHeight(117),resizeWidth(58),resizeHeight(37));
    autostart_Button->setGeometry(resizeWidth(465),resizeHeight(82),resizeWidth(67),resizeHeight(37));
}
