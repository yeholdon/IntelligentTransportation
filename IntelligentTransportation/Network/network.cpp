#include "network.h"
#include <QDebug>
Network* Network::netPtr = NULL; // 类外赋初值


Network::Network(QObject *parent) : QObject(parent)
{
    socket = NULL;
    flag = false;
}
// 获取本类唯一对象的指针
Network *Network::getNetPtr()
{
    if(netPtr == NULL) {
        netPtr = new Network;
    }
    return netPtr;
}

void Network::initNetwork()
{
    if(socket == NULL) {
        socket = new QTcpSocket;
    }
    socket->connectToHost("127.0.0.1", 10086);
    connect(socket, SIGNAL(connected()), this, SLOT(connectedSlot()));
    qDebug() << "initNetwork";
}

bool Network::sendNetData(const QByteArray &data)
{
    if(socket == NULL) {
        initNetwork();
    }
//    if(flag == true) {
        // 初始化网络对象成功
        qDebug() << "sentNetdata";
        if(socket->write(data) != -1) {
            return true;
        }
//    }
    return false;
}
// 读取数据槽函数
void Network::readDataSlot()
{
    QByteArray data;
    while (socket->bytesAvailable()) {
        data.append(socket->readAll());
    }
    qDebug() << "服务器反馈：" << data.data();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    emit SendDataToBackground(jsonDoc.object()); // 收到数据，自动发给后台总控
}

void Network::disconnectSlot()
{
    // 断开连接槽函数，包含连接失败
    flag = false;
}
// 网络连接成功后触发（需要绑定）
void Network::connectedSlot()
{
//    flag = true;
    connect(socket, SIGNAL(readyRead()), this, SLOT(readDataSlot()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnectSlot()));
    qDebug() << "网络连接成功";
}
