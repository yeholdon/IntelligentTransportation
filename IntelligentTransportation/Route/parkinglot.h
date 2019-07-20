#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "transtocmdseq.h"


class ParkingLot
{
public:
    ParkingLot( int currentPoint, int parkingSpace, int destinationPoint, int *jam_level);
    void EnterParkingLot();
    void LeaveParkingLot();
    QString getParkingLotInstruction();
private:
    int currentPoint;     //小车的当前点，用于入库
    int destinationPoint; //小车的目的地点，用于出库
    int parkingSpace;     //停车位
    QString cmd;          //停车场指令
    int jamLevel[32];
};

#endif // PARKINGLOT_H
