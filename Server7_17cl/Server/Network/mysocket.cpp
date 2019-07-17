#include "mysocket.h"
#include <QDebug>

MySocket::MySocket(QObject *parent) : QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),
            this,SLOT(readDataSlot()));
    connect(this,SIGNAL(disconnected()),
            this,SLOT(disConnectSlot()));
}
//解析函数
void MySocket::translaterData(const QByteArray &data)
{
    QJsonDocument jsonDoc=QJsonDocument::fromJson(data);
    QJsonObject json = jsonDoc.object();
    int type = json.value("type").toInt();
    switch(type)
    {
    //群发消息
    case 0:handleMassData(json);break;
    }
}
//处理群发消息
void MySocket::handleMassData(const QJsonObject &json)
{
    QString text = json.value("text").toString();
    QByteArray data = Protocol::packData(0,
                      "ip",peerAddress().toString(),
                      "text",text);
    emit transferData(this,data);
}
//读取数据的槽函数
void MySocket::readDataSlot()
{
    QByteArray data;
    while(this->bytesAvailable())
    {
        data.append(this->readAll());
    }
    qDebug()<<peerAddress().toString()<<" : "<<data.data();
    translaterData(data);
}
//断开连接的槽函数
void MySocket::disConnectSlot()
{
    qDebug()<<"断开连接: "<<this->peerAddress().toString();
    //1.解绑
    this->disconnect();
    //2.释放socket
    this->deleteLater();
}

void MySocket::receiveMassDataSlot(const QByteArray &data)
{
    this->write(data);
}
