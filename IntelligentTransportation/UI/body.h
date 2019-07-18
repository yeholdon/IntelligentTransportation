#ifndef BODY_H
#define BODY_H
#include <QPainter>
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QLabel>
#include <QMap>
#include "route.h"
//#include "cartimer.h"
const int ROAD_NUM = 32;
class Body : public QWidget
{
    Q_OBJECT
public:
    explicit Body(QWidget *parent = nullptr);
    QVector<int> vector;      //存放点击的按钮对应下标
    QLabel *labels[ROAD_NUM]; //道路标签 32
    void initButtonGroup();   //初始化按钮(路口)组
    void initLayout();        //放置按钮
    void initLabelsGroup();   //初始化标签
    int resizeWidth(int rewidth);  //控制页面比例,所有类的这两个方法功能相同
    int resizeHeight(int reheight);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:
    void roadCondition(int*,int); //发送路况
private:
    QButtonGroup *btnGroup;//路口按钮组
    QHBoxLayout *h1; //h1 h2 h3三个水平布局
    QHBoxLayout *h2;
    QHBoxLayout *h3;
    QVBoxLayout *v1;//垂直布局
    QString jam_level_color[3];
//    QString transparent[3] ;//设置透明度
    int jam_level[ROAD_NUM];//拥堵值数组
    QVector<int> routeVector;

   // QMap<QString,int> map;

public slots:
    void btnSlot();
    void on_roadConButton_clicked();
    void on_manualButton_clicked();
    //void receiveFromCarTimerSlot(int car_number,bool flag);

private slots:
    void on_autoButton_clicked(int start,int end);
};

#endif // BODY_H
