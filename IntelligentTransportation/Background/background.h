#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include "Route/route.h"
#include "Route/transtocmdseq.h"
#include "Network/network.h"
#include "Network/protocol.h"
#include "UI/animation.h"

class Background : public QObject
{
    Q_OBJECT
public:
    explicit Background(QObject *parent = nullptr);
    static Background *getBgPtr(); // 获取单例对象
signals:
    void carOnline(int car_num); // 代表小车心跳包，1：
    void infoForAnimation(const QVector &crossing_vec, const QVector &anima_vec, const QVector &rotate_vec);
private:
    static Background *bg_ptr; // 单例指针
    // 各个类的指针成员
    Route *route; // 路径规划类
    TransToCmdSeq *trans_to_cmd; // 路径信息转化
    Network *net;   // 网络操作类
    Animation *anima; // 动画类
/****************************************************************/
    // 从前端收到的信号，用于Route
    int begin_num, end_num; // 起点终点的顶点
    int *jam_level, ROAD_NUM; // 各条路拥堵情况
    int car_num; // 当前操作的小车编号
    QVector<int> crossing_vec; // 路口标号序列
    QVector<int> anima_vec; // 动画标号序列
    QVector<int> edge_vec; // 路径标号序列
    QVector<int> rotate_vec; // 旋转角度序列
public slots:
    void carNumSlot(int carNum);
    void begEndSlot(int beg, int end); // 获取起点终点编号
    void jamLevelSlot(int *jamLevel, int road_num); // 获取拥堵信息
    void routePlanSlot(); // 接收路径规划命令
    // 手动规划模式，获取路径结点向量，得到指令序列
    void manuPlanSlot(const QVector &vec);
    void receiveDataSlot(const QJsonObject &jsonObj);

public:
    QVector getAnimaIndex(int beg, int end, int *jamLevel);

};

#endif // BACKGROUND_H
