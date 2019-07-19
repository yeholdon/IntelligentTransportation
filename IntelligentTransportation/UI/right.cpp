#include "right.h"

Right::Right(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle(tr("智能小车"));
    this->setupUi(this);

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

