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
