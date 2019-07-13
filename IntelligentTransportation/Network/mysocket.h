#ifndef MYSOCKET_H
#define MYSOCKET_H
/*自定义套接字*/
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include "protocol.h"

class MySocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MySocket(QObject *parent = nullptr);

signals:
    // 信号没有函数体
    void transferData(MySocket *socket, const QByteArray &data);

private:
    // 解析函数，解析收到的数据
    void translaterData(const QByteArray &data);
    // 处理群发消息的函数（收到的消息类型为需要群发的消息）
    void handleMassData(const QJsonObject &json);
public slots:
    void readDataSlot();
    void disConnectSlot();
    // 接收某个服务器端socket转发过来的消息，再发给自己对应的客户端socket
    void receiveMassDataSlot(MySocket *socket, const QByteArray &data);
};

#endif // MYSOCKET_H
