#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
/*自定义套接字类*/

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>

#include "protocol.h"

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = nullptr);

signals:
    //信号没有函数体
    //信号可以发送data数据
    void transferData(MyTcpSocket* socket,const QByteArray& data);
    //进一步解析数据包，开始处理数据包

private:
    void translaterData(const QByteArray& data);   //解析具有json格式数据包：初步解析，只判断数据包的类型，具体的处理操作封装成函数
    void handleMessData(const QJsonObject &json);   //群发消息
public slots:   
    //MyTcpSocket类的套接字负责发出信号
    void readDataSlot();   //当与客户端连接的套接字接受数据时被触发
    void disconnectSlot();  //当客户端与服务器断开连接时被触发
  //  void receiveMassDataSlot(MyTcpSocket* socket,const QByteArray& data);
    void receiveMassDataSlot(const QByteArray& data);
};

#endif // MYTCPSOCKET_H
