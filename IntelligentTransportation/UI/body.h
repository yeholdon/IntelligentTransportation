#ifndef BODY_H
#define BODY_H
#include <QPainter>
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QPropertyAnimation>      //基本的动画类：使控件（如label）动起来，实现旋转、透明度改变、渐变、大小位置的改变
#include <QSequentialAnimationGroup>   //动画组，实现连续的动画效果
#include <QTimer>
#include <QSettings>    //配置文件类

#include "Background/background.h"
#include "Route/route.h"
#include "mylabel.h"
const int ROAD_NUM = 32;
const int LANTERN_UD=14;
const int LANTERN_LR=18;
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

    void initAnimationTimer();         //定时器初始化
    void initMap();           //初始化map：动画与rotate对应
    void initAnimal();        //初始化animal数组
    void setAnimationGroup(const QVector<QPropertyAnimation *> &vect);  //设置动画组
    void startAnimation(QVector<int> route_num);
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:
    void crossingSignal(const QVector<int>&);

    void autoPlanCrossingSignal(const QVector<int>&);
    void routeView(const QString&);
    void roadConditionSignal(int *, int);
private:
    void setenabled();
    void setunabled();
    void initLantern();

    QButtonGroup *btnGroup;//路口按钮组
    QHBoxLayout *h1; //h1 h2 h3三个水平布局
    QHBoxLayout *h2;
    QHBoxLayout *h3;
    QVBoxLayout *v1;//垂直布局
    QString jam_level_color[3]; //存放颜色
    int jam_level[ROAD_NUM];//拥堵值数组
    QLabel* lanternUD[LANTERN_UD];
    QLabel* lanternLR[LANTERN_LR];
    QVector<int> routeVector;
    QVector <int> crossingVector;
    bool flag;//标志是否生成路况
    bool adjoin;//标志点击按钮是否相邻
    bool once;//判断是自动还是手动
    QString routeString;

    MyLabel *carLabel;     //小车标签指针
    QVector<QPropertyAnimation *> animal;    //动画数组
    QSequentialAnimationGroup *group;
        //定时器，用来监听动画子进程
    QTimer *animationTimer;
        //map保存动画和旋转方向的对应关系
    QMap<QPropertyAnimation *,int> map;

public slots:
    void btnSlot();  //按钮点击触发
    void manualChoiceSlot();  //设定按钮可以被点击
    void autoStartpointSlot(); //导航起点
    void autoEndpointSlot(); //导航终点
//    void on_roadConButton_clicked();
    void on_manualButton_clicked();
    void on_autoButton_clicked();
    void roadConSlot(int index);//躲避拥堵
    void animationTimerSlot();
    void startAnimation(const QVector<int> &crossing_vec, const QVector<int> &route_num, const QVector<int> &rotate_vec);
};

#endif // BODY_H
