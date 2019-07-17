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
    if(info.type == 0xC1)
    {
        //1号小车的心跳包
        if(info.len == 1)
        {
            QByteArray data = Protocol::packData(1);
            //将data发给MyTcpSever
            MyTcpServer::getServerPtr()->sendDataToClient(data);
        }
        //1号小车的 位置卡号
        else if(info.len == 8)
        {
            //打包成json格式

            QByteArray data = Protocol::packData(3,"rfid",info.data);
            //将 data 发给MyTcpServer
            MyTcpServer::getServerPtr()->sendDataToClient(data);
        }
     }
    else if(info.type == 0xC2)
    {
        //2号小车
        if(info.len == 1)
        {
        //心跳包
            QByteArray data = Protocol::packData(2);
            //将data发给MyTcpSever
            MyTcpServer::getServerPtr()->sendDataToClient(data);
        }
        //2号车的卡号位置
        else if(info.len == 8)
        {
            QByteArray data = Protocol::packData(4,"rfid",info.data);
            //将 data 发给MyTcpServer
            MyTcpServer::getServerPtr()->sendDataToClient(data);
        }
     }
     //交通灯
     else if(info.type==0xDD)
     {
        //"0"的ASCII码值为0x30 "1"的ASCII码值为0x31
        QString lightcolor;
        if((QString)info.data == "0")
        {
            lightcolor = "red";
        }
        else if ((QString)info.data == "1")
        {
            lightcolor = "green";
        }
        QByteArray data = Protocol::packData(5,"lightcolor",lightcolor);
        MyTcpServer::getServerPtr()->sendDataToClient(data);
     }
    else
    {
        qDebug()<<"HandleDate: 服务器无法把DataInfo格式的数据包转换为json格式的";
    }
}
