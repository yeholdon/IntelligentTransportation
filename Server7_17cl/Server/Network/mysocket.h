#ifndef MYSOCKET_H
#define MYSOCKET_H
/*自定义套接字类*/
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include "protocol.h"

class MySocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MySocket(QObject *parent = nullptr);

signals:
    void  transferData(MySocket*socket,const QByteArray& data);
private:
    void  translaterData(const QByteArray& data);
    void  handleMassData(const QJsonObject& json);
public slots:
    void  readDataSlot();
    void  disConnectSlot();
    void  receiveMassDataSlot(const QByteArray& data);
};

#endif // MYSOCKET_H
