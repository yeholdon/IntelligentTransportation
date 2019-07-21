#include "parkinglot.h"
#include<QTime>

ParkingLot::ParkingLot(int currentPoint = -1, int parkingSpace = -1, int destinationPoint = -1, int *jam_level = NULL)
{
    // 新加的，拥堵情况统一用background里的
    jamLevel = jam_level;
    if(parkingSpace != -1)
    {
        this->parkingSpace = parkingSpace;
        if(currentPoint != -1)
        {
            this->currentPoint = currentPoint;  //当前点的位置
            EnterParkingLot();
        }else if(destinationPoint != -1)
        {
            this->destinationPoint = destinationPoint;
            LeaveParkingLot();
        }
    }
}

void ParkingLot::EnterParkingLot()
{
//    //生成jamLevel
//    int *jamLevel = new int[32];
//    for(int i=0;i<32;i++)
//    {
//        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//        int a = qrand()%2;   //随机生成0到2的随机数
//        jamLevel[i] = a;
//    }

    //小车由当前点开往停车场入口
    QVector<int> nodeVec = Route::getRoutePtr()->minRoute(currentPoint, 6);
    QVector<int> edgeVec = TransToCmdSeq::getRoutePtr()->getEdgeArray(nodeVec);
    QVector<int> rotateVec = TransToCmdSeq::getRoutePtr()->getRotateArray( edgeVec);
    QString str = TransToCmdSeq::getRoutePtr()->getCarControlInstruction( rotateVec);
    cmd.append(str);
    //停车场入口   0-前   1-左    2-右
    switch( edgeVec.at(edgeVec.length()-1) ){
        case 15:   cmd.append("1");   break;
        case 16:   cmd.append("2");    break;
        case 23:   cmd.append("4");    break;
        default:   break;
    }
//     qDebug()<< "停车场入口cmd "<<cmd;
    //停车场入口至停车场车位
    switch(parkingSpace){
        case 1:   cmd.append("2");    break;
        case 2:   cmd.append("4");    break;
        case 3:   cmd.append("1");    break;
        default:   break;
    }
//      qDebug()<< "停车场车位cmd "<<cmd;
    //到车位停止

}

void ParkingLot::LeaveParkingLot()
{
//    //生成jamLevel
//    int *jamLevel = new int[32];
//    for(int i=0;i<32;i++)
//    {
//        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//        int a = qrand()%2;   //随机生成0到2的随机数
//        jamLevel[i] = a;
//    }

    //小车由停车场车位开往停车场出口
    switch(parkingSpace){
        case 1:   cmd.append("2");    break;
        case 2:   cmd.append("0");    break;
        case 3:   cmd.append("1");    break;
        default:   break;
    }
    //路径规划
//    QVector<int> edgeVec = TransToCmdSeq::getRoutePtr(jamLevel)->getEdgeArray(2, destinationPoint, jamLevel);
//    QVector<int> rotateVec = TransToCmdSeq::getRoutePtr(jamLevel)->getRotateArray( edgeVec);
//    QString str = TransToCmdSeq::getRoutePtr(jamLevel)->getCarControlInstruction( rotateVec);

    QVector<int> nodeVec = Route::getRoutePtr()->minRoute(2, destinationPoint);
    QVector<int> edgeVec = TransToCmdSeq::getRoutePtr()->getEdgeArray(nodeVec);
    QVector<int> rotateVec = TransToCmdSeq::getRoutePtr()->getRotateArray( edgeVec);
    QString str = TransToCmdSeq::getRoutePtr()->getCarControlInstruction( rotateVec);
    cmd.append(str);
    //停车场出口
    if( edgeVec.at(0) == 5)   //离开停车场后先向右拐
    {
        cmd.append("2");
    }else if( edgeVec.at(0) == 2)
    {
        cmd.append("1");
    }
    //小车由停车场出口开往目的地
    cmd = cmd + str;
//    qDebug()<< "目的地cmd "<<cmd;

}

QString ParkingLot::getParkingLotInstruction()
{
    return cmd;
}
