#include "serialportprotocol.h"
#include "serialport/serialportdevice.h"
SerialPortProtocol::SerialPortProtocol(QObject *parent) : QObject(parent)
{
    len = 0;
    connect(SerialportDevice::getDevicePtr(),
            SIGNAL(transferData(QByteArray)),
            this,
            SLOT(receiveDeviceDataSlot(QByteArray)));
    qDebug()<<"SerialPortProtocol构造函数";
}

void SerialPortProtocol::receiveDeviceDataSlot(const QByteArray &data)
{
      qDebug()<<"发射成功";
    //FF EFEF0AFFFF02AC0000FF
    for(int i=0;i<data.size();i++)
    {
        //判断并得到帧头 static_cast<quint8>data[i]
        if((quint8)data[i] == 0xEF && len>0)  //第二位及之后有0xEF
        {
            if(buffer[len-1] == 0xEF)  //上一位也是0xEF
            {
                buffer[0] = 0xEF;
                buffer[1] = 0xEF;
                len = 2;
                continue;
            }
        } //[0000FFEF]

        //判断并得到帧尾
        if(len>5 && (quint8)data[i] == 0xFF && buffer[5] == len + 1)
        {
            buffer[len] = 0xFF;
            //...处理buffer中完整的帧,存储
            receiveData.addr[0] = buffer[2];
            receiveData.addr[1] = buffer[3];
            receiveData.len = buffer[5] - 8;
            receiveData.type = buffer[6];
            for(int j=0; j<receiveData.len ;j++)
            {
                receiveData.data.append(buffer[7+j]);
            }
            qDebug()<<"帧:"<<receiveData.addr[0]<< receiveData.addr[1]<<receiveData.len<<receiveData.type;

            len = 0;
            continue;
        }

        //普通数据赋值
        buffer[len++] = (quint8)data[i];
    }

}
