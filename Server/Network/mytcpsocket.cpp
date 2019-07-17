#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent) : QTcpSocket(parent)
{
    //绑定信号与槽函数
    connect(this,SIGNAL(readyRead()),this,SLOT(readDataSlot()));
    connect(this,SIGNAL(disconnected()),this,SLOT(disconnectSlot()));
    connect(this, SIGNAL(transferDataToSerialPort(DataInfo)), SerialportDevice::getDeviceptr(), SLOT(writeSerialPortSlot(DataInfo)));
    //上行，从串口传来的
//    connect(this, SIGNAL(transferDataToSerialPort(DataInfo)), SerialPortProtocol::getSerialPortProtocolPtr(), SLOT(receiveDatafromSocket(DataInfo)));
}


// 新加的接收来自客户端的json包
void MyTcpSocket::receiveDataFromClient(const QByteArray &data)
{
    //客户端发送来的data是具有json格式的
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QJsonObject json = jsonDoc.object();
    //json.value("type")为String类型
    int type = json.value("type").toInt();
    DataInfo info;
    info.data.clear();
    info.addr[0] = info.addr[1] = 0xFF;
    switch(type)
    {
    //群发消息
    case 1:
    {
        //下行数据中
        info.data.append(json.value("cmd").toString());
        info.len = info.data.size();
        info.type = 1;
        break;
    }
    case 2:
    {
        info.data.append(json.value("cmd").toString());
        info.len = info.data.size();
        info.type = 2;
        break;
    }
    case 3:
    {
        info.data.append(json.value("cmd").toString());
        info.len = info.data.size();
        info.type = 3;
        break;
    }
    }
    emit transferDataToSerialPort(info);
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
    receiveDataFromClient(data);
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

// 服务器发送给客户端
void MyTcpSocket::sendToClientSlot(const QByteArray &data)
{
//    qDebug() << "服务器发送给客户端" << data;
    this->write(data);
}
