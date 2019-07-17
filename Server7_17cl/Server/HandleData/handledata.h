#ifndef HANDLEDATA_H
#define HANDLEDATA_H
/*帧数据处理类*/
//单例类
#include <QObject>
#include <Network/protocol.h>
#include <Network/mytcpserver.h>

#include "SerialPort/datainfo.h"
#include "SerialPort/serialportprotocol.h"

class HandleData : public QObject
{
    Q_OBJECT
public:
    static HandleData* getHandlePtr();
private:
    explicit HandleData(QObject *parent = nullptr);
signals:
    void tempData(struct DataInfo Info);
public slots:
    void receiverDeviceDataSlot(struct DataInfo info);

private:
    static HandleData *handlePtr;
    struct DataInfo Info;
};

#endif // HANDLEDATA_H
