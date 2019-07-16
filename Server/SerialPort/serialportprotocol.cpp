#include "serialportprotocol.h"

SerialPortProtocol::SerialPortProtocol(QObject *parent) : QObject(parent)
{
    len = 0;
    connect(SerialportDevice::getDeviceptr(),SIGNAL(tranferData(QByteArray))
            ,this,SLOT(receiveDeviceDataSlot(QByteArray)));

}

SerialPortProtocol *SerialPortProtocol::getSerialPortProtocolPtr()
{
    static SerialPortProtocol serial;
    return &serial;
}

void SerialPortProtocol::receiveDeviceDataSlot(const QByteArray &data)
{
    //FF EFEF0BFFFF0BAC0000FF
    for(int i = 0;i<data.size();i++)
    {
        //1.判断得到帧头
        if((quint8)data[i] == 0xEF && len>0)
        {
            if(buffer[len-1] == 0xEF)
            {
                buffer[0] = 0xEF;
                buffer[1] = 0xEF;
                len = 2;
                continue;
            }

        }
        //2.判断并得到帧尾
        if(len>5&&(quint8)data[i] == 0xFF && buffer[5] == len+1)
        {
            buffer[len] = 0xFF;
            //处理buffer中完整的帧
            receiveData.addr[0] = buffer[3];
            receiveData.addr[1] = buffer[4];
            receiveData.len = buffer[5] - 8;
            receiveData.type = buffer[6];
            for(int j= 0;i<receiveData.len;j++)
            {
                receiveData.data.append(buffer[7+j]);
            }
            //将从帧结构中解析的数据发送到网络模块，进行json封装
            emit transferDeviceData(receiveData);
            //开始接收下一帧
            len = 0;
            continue;

        }
        //3.普通数据附值
        buffer[len++] = (quint8)data[i];
    }
}
