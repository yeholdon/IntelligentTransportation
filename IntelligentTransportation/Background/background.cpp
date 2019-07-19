#include "background.h"


Background *Background::bg_ptr = NULL;

Background::Background(QObject *parent) : QObject(parent)
{
    route = Route::getRoutePtr();
    trans_to_cmd = TransToCmdSeq::getRoutePtr(jam_level);
    net = Network::getNetPtr();
    anima = new Animation;
//    cartimer = new CarTimer;
    // 初始化小车在线定时器
//    cartimer->initAll();
    // 读取卡号map配置文件

    init();
    readCardMapSetting();
    // 信号与槽绑定,上行数据

    connect(net, SIGNAL(SendDataToBackground(QJsonObject)), this, SLOT(receiveDataSlot(QJsonObject)));
    // 中转小车在线信息给UI
//    connect(cartimer, SIGNAL(sendToWindowCarOnline(int,bool)), this, SIGNAL(TransOnelineSignal(int,bool)));
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
    qDebug() << "begEndSlot success";
    begin_num = begin;
    end_num = end;
}

void Background::jamLevelSlot(int *jamLevel, int road_num)
{
    for(int i = 0; i < 32; i++) {
        jam_level[i] = jamLevel[i];
    }
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
    // 得到旋转角度序列
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

void Background::manuPlanSlot(const QVector<int> &vec)
{
    // 得到动画编号序列
    anima_vec = getAnimaIndex(begin_num, end_num, jam_level);
    // 得到路径序列
    edge_vec = trans_to_cmd->getEdgeArray(begin_num, end_num, jam_level);
    // 得到旋转角度序列
    rotate_vec = trans_to_cmd->getRotateArray(edge_vec);
    // 将路口、动画标号和rotate的Vector传到UI/Animation
    emit infoForAnimation(vec, anima_vec, rotate_vec);

    // 得到cmd
    QString cmd = trans_to_cmd->getCarControlInstruction(rotate_vec);
    // 将cmd等值打包成json格式的数组
    QByteArray json = Protocol::packData(car_num, "cmd", cmd);
    // 发送json格式的字节流数组到服务器
    net->sendNetData(json);
}

// 解析上行数据json包，心跳包或卡号
void Background::receiveDataSlot(const QJsonObject &json)
{
    int type = json.value("type").toInt();
    QString pos, color;
    int id;
    qDebug() <<"receiveDataSlot:" << type;
    switch (type) {
    case 1: // 1号车心跳包
        // 发给CarTimer判断是否掉线
        emit carOnline(1);
        break;
    case 2: // 2号车心跳包
        // 发给CarTimer判断是否掉线
        emit carOnline(2);
        break;
    case 3: // 1号车当前读到的卡号
        pos = json.value("rfid").toString();
        id = getCardId(pos);
        qDebug() << pos << " " << id;
        // 发给 Animation
        emit carCurrentPosIdForAnimation(1, id);
        break;
    case 4: // 2号车当前读到的卡号
        pos = json.value("rfid").toString();
        id = getCardId(pos);
        qDebug() << pos << " " << id;
        // 发给 Animation
        emit carCurrentPosIdForAnimation(2, id);
        break;
    case 5:
        color = json.value("lightcolor").toString();
        qDebug() << color;
    default:
        break;
    }
}

void Background::test()
{
    qDebug() << "test success";
}

// 得到动画编号
QVector<int> Background::getAnimaIndex(int beg, int end, int *jamLevel)
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

// 从配置文件读取实际64位卡号到自定义卡号的映射
void Background::readCardMapSetting()
{
    QSettings set("card_id_map.ini", QSettings::IniFormat);
    set.beginGroup("CardIdMapGroup");
    QStringList str_list = set.allKeys();

    for(int i = 0; i < str_list.size(); i++) {
        card_id.insert(str_list[i], set.value(str_list[i]).toInt());
    }
}

// 实际卡号映射为自定义卡号
int Background::getCardId(QString card64)
{
    if(card_id.find(card64) == card_id.end()) {
        qDebug() << "No such card_id in card_id_map";
        return 0;
    }
    return card_id[card64];
}
// 测试用
void Background::init()
{
    // 1. begin_num, end_num
    begin_num = 0;
    end_num = 11;
    car_num = 1;
    // 2. jam_level
    qsrand((unsigned)time(NULL));
    for(int i = 0; i < 24; i++) {
        int r = (round(1.0 * rand() / RAND_MAX * (2 - 0) + 0));
        jam_level[i] = r; // 记录当前生成的所有路段的拥堵等级，供路径规划使用
    }
    ROAD_NUM = 32;
}





