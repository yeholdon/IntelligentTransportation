#include "serialportprotocol.h"

SerialPortProtocol::SerialPortProtocol(QObject *parent) : QObject(parent)
{
    len = 0;
    struct DataInfo sendData;
    struct DataInfo receiveData;
    connect(SerialportDevice::getDeviceptr(),SIGNAL(tranferData(QByteArray))
            ,this,SLOT(receiveDeviceDataSlot(QByteArray)));

}

SerialPortProtocol *SerialPortProtocol::getSerialPortProtocolPtr()
{
    static SerialPortProtocol serial;
    return &serial;
}

//向串口写数据
QByteArray SerialPortProtocol::sendDeviceData(const DataInfo &sendData)
{
    //FEFE0BFFFF0BAC0000FF
    QByteArray sendArray;
    sendArray[2] = 0x00;
    sendArray[0] = sendArray[1] = 0xFE;
    sendArray[3] = sendArray[4] = 0xFF;
    sendArray[5] = 0x08 + sendData.len;
    if(sendData.type == 3 ) //中途暂停或再次前进
    {
        sendArray[6] = sendData.data == "00" ? 0x00 : 0x01;
        sendArray[7] = 0x00;
    }else{  //1号车或2号车控制
        sendArray[6] = sendData.type == 1 ? 0xC1 : 0xC2;
        for(int i=1,j=1; i<=sendData.len; i++,j=j+2)
        {
//            qDebug()<<j<<sendData.data.at(j);
            switch (sendData.data.at(j))
            {
                case '0':  sendArray[6+i] = 0x00; break;
                case '1':  sendArray[6+i] = 0x01; break;
                case '2':  sendArray[6+i] = 0x02; break;
                default: break;
            }
        }
    }
    sendArray[sendArray[5] - 1] = 0xFF;
    return sendArray;
}

//从串口读数据
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


