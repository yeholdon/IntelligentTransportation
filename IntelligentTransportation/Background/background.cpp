#include "background.h"

Background::Background(QObject *parent) : QObject(parent)
{
    route = Route::getRoutePtr();
    trans_to_cmd = new TransToCmdSeq;
    net = Network::getNetPtr();

    // 信号与槽绑定
    connect(net, SIGNAL(SendDataToBackground(const QJsonObject &json)), this, SLOT())
}

Background *Background::getBgPtr()
{
    if(bg_ptr == NULL) {
        bg_ptr = new Background;
    }
    return bg_ptr;
}

void Background::carNumSlot(int carNum)
{
    carNum = carNum;
}

void Background::begEndSlot(int begin, int end)
{
    begin_num = begin;
    end_num = end;
}

void Background::jamLevelSlot(int *jamLevel, int road_num)
{
    jam_level = jamLevel;
    ROAD_NUM = road_num;
}

// 自动规划模式，规划路径得到路段编号和指令,emit给Animation类
void Background::routePlanSlot()
{
    // 得到规划出路径的路口标号
    crossing_vec = route->minRouteJam(begin_num, end_num, jam_level);
    // 得到动画编号序列
    anima_vec = getAnimaIndex(begin_num, end_num, jam_level);
    // 得到路径序列
    edge_vec = trans_to_cmd->getEdgeArray(begin_num, end_num, jam_level);
    // 得到动画编号序列
    rotate_vec = trans_to_cmd->getRotateArray(edge_vec);
    // 将路口、动画标号和rotate的Vector传到UI/Animation
    emit infoForAnimation(crossing_vec, anima_vec, rotate_vec);

    // 得到cmd
    QString cmd = trans_to_cmd->getCarControlInstruction(rotate_vec);
    // 将cmd等值打包成json格式的数组
    QByteArray json = Protocol::packData(car_num, "cmd", cmd);
    // 发送json格式的字节流数组到服务器
    net->sendNetData(json);

}

// 得到动画编号
QVector Background::getAnimaIndex(int beg, int end, int *jamLevel)
{
    QVector<int> edgeVec;
    QVector<int> nodeVec = Route::getRoutePtr()->minRouteJam(beg, end, jamLevel);
    QVector<int>::iterator iter;
    int i;
    for(iter = nodeVec.begin(),i=0; iter != nodeVec.end() - 1; iter++,i++)
    {
        edgeVec.append( Route::getRoutePtr()->getNodeToEdge(*iter,*(iter+1)) );
//        qDebug()<<"edgeVec："<<edgeVec.at(i);
    }
    return edgeVec;
}





