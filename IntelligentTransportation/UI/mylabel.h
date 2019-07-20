#ifndef MYLABEL_H
#define MYLABEL_H
/*自定义标签类*/
#include <QWidget>
#include <QLabel>
#include <QPainter>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
    void setRotate(int rotate);
protected:
    virtual void paintEvent(QPaintEvent *);  //重载虚函数时，对于不需要的参数的变量名可以省略
private:
    int rotate;
signals:

public slots:
};

#endif // MYLABEL_H
