#include "mytcpserver.h"

MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    this->listen(QHostAddress::AnyIPv4, 10001);
}

// 当新客户端连接服务器以后，该函数会自动触发
void MyTcpServer::incomingConnection(qintptr handle)
{
    // 1. 构造套接字对象
    MySocket *socket = new MySocket(this);
    // 2. 设置套接字描述符
    socket->setSocketDescriptor(handle);
//    qDebug() << "new connection: " << this->peerAddress().toString();
    // 信号触发信号，同名但是所属对象不一样。绑定是针对对象的
    // 相同服务器端套接字之间
    connect(socket, SIGNAL(transferData(MySocket*, QByteArray)), this, SIGNAL(tansferData(MySocket*, QByteArray)));
    connect(this, SIGNAL(transferData(MySocket*, QByteArray)), socket, SIGNAL(receiveMassDataSlot(MySocket *, QByteArray)));
//    qDebug() << "discnnected: " << this->peerAddress().toString();
}
