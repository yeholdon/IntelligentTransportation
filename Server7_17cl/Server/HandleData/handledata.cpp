#include "handledata.h"

HandleData * HandleData::handlePtr = NULL;

HandleData *HandleData::getHandlePtr()
{
    if(handlePtr == NULL)
    {
        handlePtr = new HandleData;
    }

    return handlePtr;
}

HandleData::HandleData(QObject *parent) : QObject(parent)
{

    connect(SerialPortProtocol::getSerialPortProtocolPtr(),
            SIGNAL(transferDeviceData(DataInfo)),
            this,
            SLOT(receiverDeviceDataSlot(DataInfo)));
    connect(this,SIGNAL(tempData(DataInfo)),
            SerialportDevice::getDeviceptr(),
            SLOT(writeSerialPortSlot(DataInfo)));
//    Info = {0xFF,0xFF,1,3,"00"};
//    Info = {0xFF,0xFF,1,3,"01"};
//    Info = {0xFF,0xFF,4,1,"01020001"};
    Info = {0xFF,0xFF,5,2,"0102000100"};
    emit tempData(Info);
}

void HandleData::receiverDeviceDataSlot(DataInfo info)
{
    if(info.type == 0x01){
            //1号小车的心跳包
            if(info.len == 1)
            {
                QByteArray data = Protocol::packData(1);
                //将data发给MyTcpSever
            }
            //1号小车的 位置卡号
            else if(info.len == 8)
            {
                //打包成json格式

                QByteArray data = Protocol::packData(3,"rfid",info.data);
                //将 data 发给MyTcpServer
                MyTcpServer::getServerPtr()->sendDataToClient(data);
            }
        }if(info.type == 0x02){
            //2号小车
            if(info.len == 1)
            {//心跳包

            }else if(info.len == 8){

            }
        }else if(info.type==0x03){

        }
}
