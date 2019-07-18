#include "network.h"

Network* Network::netPtr = NULL;

Network::Network(QObject *parent) : QObject(parent)
{
    socket = NULL;
    flag = false;
    //将连接成功的信号与槽函数绑定

}

Network* Network::getNetPtr()
{
    if(netPtr == NULL)
    {
        netPtr = new Network;
    }
    return netPtr;
}

//初始化网络
void Network::initNetwork()
{
    if(socket == NULL)
    {
        socket = new QTcpSocket;
    }
    //星宏的IP地址与端口
    //socket->connectToHost("192.168.43.137",10001);
    //老师的IP地址与端口
    //socket->connectToHost("192.168.43.198",10086);
    //本机自发自收
    socket->connectToHost("127.0.0.1",10086);
    connect(socket,SIGNAL(connected()),this,SLOT(connectSLot()));
}

bool Network::sendNetData(const QByteArray &data)
{
    if(socket == NULL)
    {
        initNetwork();
    }
    if(flag)
    {
        if(socket->write(data)!=-1)
        {
            return true;
        }
    }
    return false;
}

void Network::connectSLot()
{
    flag = true;
    connect(socket,SIGNAL(readyRead()),this,SLOT(readDataSLot()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnectSlot()));
    qDebug()<< "网络连接成功！";
}

void Network::readDataSLot()
{
    //开辟一段缓存（数组）
    QByteArray data;
    //为了防止不能完全读取数据，使用while循环
    //bytesAvailable()返回未读取的数据的字节数
    while(socket->bytesAvailable())
    {
        data.append(socket->readAll());       //readAll():当前网络环境允许读取的数据的最大值
    }
    qDebug()<<"服务器反馈："<<data;
    //QJsonDocument::fromJson():字节流 -> json文档
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    emit sendDataWindow(jsonDoc.object());
}

void Network::disconnectSlot()
{
    flag = false;
    qDebug()<<"客户端与服务器断开连接";

}
