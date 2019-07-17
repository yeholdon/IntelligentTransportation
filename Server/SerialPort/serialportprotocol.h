#ifndef SERIALPORTPROTOCOL_H
#define SERIALPORTPROTOCOL_H
/*串口协议类*/

#include <QSettings>    //配置文件类
#include <QObject>

#include "serialportdevice.h"
#include "datainfo.h"
//typedef struct
//{
//    quint8 addr[2]; //短地址
//    quint8 len;     //有效数据长度
//    quint8 type;
//    QByteArray data;//有效数据
//} DataInfo;

class SerialPortProtocol : public QObject
{
    Q_OBJECT
private:
    explicit SerialPortProtocol(QObject *parent = nullptr);
public:
    static SerialPortProtocol* getSerialPortProtocolPtr();
    QByteArray sendDeviceData(const DataInfo &sendData);
signals:
    void transferDeviceData(DataInfo receiveData);
public slots:
    void receiveDeviceDataSlot(const QByteArray &data);
    void receiveDatafromSocket(const DataInfo &info);
private:
    quint8 buffer[256];
    quint8 len;
    DataInfo receiveData;

};

#endif // SERIALPORTPROTOCOL_H
