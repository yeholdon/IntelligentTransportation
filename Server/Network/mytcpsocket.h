#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
/*自定义套接字类*/

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include "SerialPort/serialportprotocol.h"
#include "SerialPort/serialportdevice.h"
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
    void transferDataToSerialPort(const DataInfo &info);// ///////////////////////

private:

    void receiveDataFromClient(const QByteArray& data); // 解析具有json格式数据包

public slots:   
    //MyTcpSocket类的套接字负责发出信号
    void readDataSlot();   //当与客户端连接的套接字接受数据时被触发
    void disconnectSlot();  //当客户端与服务器断开连接时被触发

    void sendToClientSlot(const QByteArray& data);
};

#endif // MYTCPSOCKET_H
