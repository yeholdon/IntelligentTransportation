#ifndef SERIALPORTPROTOCOL_H
#define SERIALPORTPROTOCOL_H
/*串口协议类*/
#include <QObject>
#include "serialport/serialportdevice.h"

//数据信息结构体
typedef struct
{
    quint8 addr[2]; //短地址
    quint8 len;     //有效数据长度
    quint8 type;    //数据类型   01-心跳包  02-小车  03-交通灯
    QByteArray data; //QByteArray可变长度数组，有效数据
}DataInfo;

class SerialPortProtocol : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortProtocol(QObject *parent = nullptr);
signals:

public slots:
    void receiveDeviceDataSlot(const QByteArray& data);
private:
    quint8 buffer[256];  //缓存
    quint8 len;  //当前指针位置，指向当前正在指向第几个位置
    DataInfo receiveData;
};

#endif // SERIALPORTPROTOCOL_H
