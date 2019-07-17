#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent) : QTcpSocket(parent)
{
    //绑定信号与槽函数
    connect(this,SIGNAL(readyRead()),this,SLOT(readDataSlot()));
    connect(this,SIGNAL(disconnected()),this,SLOT(disconnectSlot()));
}

void MyTcpSocket::translaterData(const QByteArray &data)
{
    //客户端发送来的data是具有json格式的
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QJsonObject json = jsonDoc.object();
    //json.value("type")为String类型
    int type = json.value("type").toInt();
    switch(type)
    {
    //群发消息
    case 0:
    {
        //下行数据中，规定type = 0也为群发
        handleMessData(json);
    }
    }
}
void MyTcpSocket::handleMessData(const QJsonObject &json)
{
    QString text = json.value("text").toString();
    QByteArray data = Protocol::packData(0,"ip",peerAddress().toString(),"text",text);
    //emit 发出信号
    emit transferData(this,data);
}

//读取数据的槽函数
void MyTcpSocket::readDataSlot()
{
    //开辟一段缓存（数组）
    QByteArray data;
    //为了防止不能完全读取数据，使用while循环
    //bytesAvailable()返回未读取的数据的字节数
    while(this->bytesAvailable())
    {
        data.append(this->readAll());       //readAll():当前网络环境允许读取的数据的最大值
    }
    //data():返回char* 指针
    qDebug()<<peerAddress().toString()<<":"<<data.data();
}

//断开连接的槽函数
void MyTcpSocket::disconnectSlot()
{
    qDebug()<<"断开连接"<<this->peerAddress().toString();   //peerAddress()：得到IP地址
    //1.当客户端端开连接时，将套接字与客户端解绑
    this->disconnect();
    //2.释放套接字
    this->deleteLater();
}

void MyTcpSocket::receiveMassDataSlot(const QByteArray &data)
{
//    //this：每个客户端对应的socket id
//    //socket:  给服务器发送群发消息的客户端的 socket id
//    if(this != socket)
//    {
//        this->write(data);
//    }
    this->write(data);
}
