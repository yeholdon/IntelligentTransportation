#include "mysocket.h"

MySocket::MySocket(QObject *parent) : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(readDataSlot()));
    connect(this, SIGNAL(disconnected()), this, SLOT(disConnectSlot()));
}
// 解析函数，业务逻辑的主要处理函数
void MySocket::translaterData(const QByteArray &data)
{
    // 客户端发来的就是打包过的json对象，这里解析
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QJsonObject json = jsonDoc.object();
    int type = json.value("type").toInt();
    // 获取第一个键值对，代表消息的类型。了解消息,确定身份。
    switch(type) {
    case 0:
        handleMassData(json); break;
    }
}

void MySocket::handleMassData(const QJsonObject &json)
{
    QString text = json.value("text").toString();
    QByteArray data = Protocol::packData(0,
                                         "ip", peerAddress().toString(),
                                         "text", text);
    emit transferData(this, data); // 发送信号, 整个工程都能收到。每个套接字都能收到
}

void MySocket::readDataSlot()
{
    QByteArray data;
    while (this->bytesAvailable()) {
        data.append(this->readAll()); // 只是读取缓冲区里的所有。
    }
    qDebug() << "new data:" << peerAddress().toString() << ":" << data.data();
    translaterData(data);
}

void MySocket::disConnectSlot()
{
    qDebug() << "discnnected: " << this->peerAddress().toString();
    // 1. 解绑
    this->disconnect();
    // 2. 释放socket
    this->deleteLater();

}

void MySocket::receiveMassDataSlot(MySocket *socket, const QByteArray &data)
{

   if(this != socket) { // 不是在服务器端接收并转发数据的套接字，而是转发的目的地套接字
       this->write(data);
   }

}
