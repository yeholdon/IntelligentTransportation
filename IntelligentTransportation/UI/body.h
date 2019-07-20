#ifndef BODY_H
#define BODY_H
#include <QPainter>
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
class Body : public QWidget
{
    Q_OBJECT
public:
    explicit Body(QWidget *parent = nullptr);
    void initButtonGroup();
    void initLayout();
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:
private:
    QButtonGroup *btnGroup;//路口按钮组
    QHBoxLayout *h1; //h1 h2 h3三个水平布局
    QHBoxLayout *h2;
    QHBoxLayout *h3;
    QVBoxLayout *v1;//垂直布局
public slots:

    // 接收来自right的信号，使能所有路口按钮
//    void manuPlanStartEnableAllCrossingBtnSlot();
};

#endif // BODY_H
