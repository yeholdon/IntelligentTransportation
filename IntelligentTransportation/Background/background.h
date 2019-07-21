#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include "Route/route.h"
#include "Route/transtocmdseq.h"
#include "Network/network.h"
#include "Network/protocol.h"
#include "UI/cartimer.h"
#include <QTime>
#include "Route/parkinglot.h"
class Background : public QObject
{
    Q_OBJECT
private:
    explicit Background(QObject *parent = nullptr);

signals:
    void carOnline(int car_num); // 代表小车心跳包，1：1号车
    void lightColor(QString color); // 代表交通灯当前的颜色
    void infoForAnimation(int car_num, const QVector<int> &crossing_vec, const QVector<int> &anima_vec, const QVector<int> &rotate_vec);
    void carCurrentPosIdForAnimation(int car_id, int card_id);
    // 中转定时器的在线离线信号
    void TransOnelineSignal(int car_number, bool flag);
private:
    static Background *bg_ptr; // 单例指针
    // 各个类的指针成员
    Route *route; // 路径规划类
    TransToCmdSeq *trans_to_cmd; // 路径信息转化
    Network *net;   // 网络操作类
    //Animation *anima; // 动画类
//    CarTimer *cartimer; // 判断小车在线定时器
/****************************************************************/
    // 从前端收到的信号，用于Route
    int begin_num, end_num; // 起点终点的顶点
    int jam_level[32], ROAD_NUM; // 各条路拥堵情况
    int car_num; // 当前操作的小车编号
    QVector<int> crossing_vec; // 路口标号序列
    QVector<int> anima_vec; // 动画标号序列
    QVector<int> edge_vec; // 路径标号序列
    QVector<int> rotate_vec; // 旋转角度序列
    QMap<QString, int> card_id; // 64位卡号的映射
public slots:
    void carNumSlot(int carNum); // 获取ui当前操作的车号
    void begEndSlot(int beg, int end); // 获取起点终点编号
    void jamLevelSlot(int *jamLevel, int road_num); // 获取拥堵信息
    void routePlanSlot(const QVector<int> &crossing_vec); // 接收路径规划命令
    // 手动规划模式，获取路径结点向量，得到指令序列
    void manuPlanSlot(const QVector<int> &vec);
    // 上行数据，json包
    void receiveDataSlot(const QJsonObject &json);
    // 停车模式, 车号，车位号
    void parkPlanSlot(int car_id, int pos_index);
    // 出车库
    void parkingOutSlot(int car_id, QString tar_pt_id);
    void test();


public:
    static Background *getBgPtr(); // 获取单例对象
//    QVector<int> getAnimaIndex(int beg, int end, int *jamLevel);
    void readCardMapSetting();
    int getCardId(QString card64);
    // 测试，获取给jam_level赋初值
    void init();
};

#endif // BACKGROUND_H
