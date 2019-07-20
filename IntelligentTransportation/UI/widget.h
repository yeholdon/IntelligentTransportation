#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "bottom.h"
//#include <bottom.h>
#include "right.h"
#include "body.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
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
    CarTimer *cartimer;
public slots:


signals:
};

#endif // WIDGET_H
