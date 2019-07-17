#ifndef SERIALPORTPROTOCOL_H
#define SERIALPORTPROTOCOL_H
/*串口协议类*/

#include <QSettings>    //配置文件类
#include <QObject>

#include "serialportdevice.h"
#include "datainfo.h"

class SerialPortProtocol : public QObject
{
    Q_OBJECT
private:
    explicit SerialPortProtocol(QObject *parent = nullptr);
public:
    static SerialPortProtocol* getSerialPortProtocolPtr();
    QByteArray sendDeviceData(struct DataInfo sendData);
signals:
    void transferDeviceData(struct DataInfo receiveData);
public slots:
    void receiveDeviceDataSlot(const QByteArray &data);
private:
    quint8 buffer[256];
    quint8 len;
    struct DataInfo receiveData;
    struct DataInfo sendData;
  //  QByteArray &sendArray;
};

#endif // SERIALPORTPROTOCOL_H
