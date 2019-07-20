#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent),rotate(0)
{

}

void MyLabel::setRotate(int rotate)
{
    this->rotate = rotate;
}

void MyLabel::paintEvent(QPaintEvent *)
{
    //旋转思路：先将坐标轴
    //定义画家
    QPainter p(this);
    //1.坐标偏移 寻找旋转中心
    p.translate(this->width()/2,this->height()/2);
    //2.旋转
    p.rotate(rotate);
    //3.坐标复原
    p.translate(-this->width()/2,-this->height()/2);
    //4.绘制图片
    QRect target(0,0,width(),height());
    p.drawImage(target,QImage(":/image/car.png"));


}
