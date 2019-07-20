#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "bottom.h"
#include "right.h"
#include "body.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
//const double W=369/224;  //所有的宽扩大369/224倍,所有的高扩大781/600倍
//const double H=781/600;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initPage();
    int resizeWidth(int rewidth);
    int resizeHeight(int reheight);
protected:
    void resizeEvent(QResizeEvent *event);
private:
    Bottom *bottom;
    Body *body;
    Right *right;
    QHBoxLayout *h;  //垂直布局 right组成水平布局
    QVBoxLayout *v;  //body bottom组成垂直布局
    void connectSignal();
signals:
};

#endif // WIDGET_H
