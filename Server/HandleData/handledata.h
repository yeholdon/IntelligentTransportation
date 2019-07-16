#ifndef HANDLEDATA_H
#define HANDLEDATA_H
/*帧数据处理类*/
//单例类
#include <QObject>
#include <Network/protocol.h>
#include <Network/mytcpserver.h>

#include "SerialPort/serialportprotocol.h"

class HandleData : public QObject
{
    Q_OBJECT
public:
    static HandleData* getHandlePtr();
private:
    explicit HandleData(QObject *parent = nullptr);
signals:

public slots:
    void receiverDeviceDataSlot(DataInfo info);

private:
    static HandleData *handlePtr;
};

#endif // HANDLEDATA_H
