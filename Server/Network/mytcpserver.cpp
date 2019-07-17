#include "mytcpserver.h"

//类的静态成员变量必须在类外部初始化
//在类外部对单例对象初始化
MyTcpServer* MyTcpServer::serverPtr = NULL;

MyTcpServer::MyTcpServer(QObject *parent) : QTcpServer(parent)
{
    this->listen(QHostAddress::AnyIPv4,10086);   //参数1：套接字监听的地址，即允许连接的客户端的地址。参数2：监听的端口
    speech = new QTextToSpeech;
//    speech->say("你真是个bullshit");
//    speech->say("Hello World 智能交通 服务器已启动！");
}

MyTcpServer *MyTcpServer::getServerPtr()
{
    if(serverPtr == NULL)
    {
        serverPtr = new MyTcpServer;
    }
    return serverPtr;
}

void MyTcpServer::sendDataToClient(const QByteArray &data)
{
    qDebug() << "MyTcpServer::sendDataToClient";
    emit transferData(data);
}

//当有客户端请求连接时，自动调用，为客户端分配套接字
void MyTcpServer::incomingConnection(qintptr handle)
{
    //1.新建套接字对象
    MyTcpSocket *socket = new MyTcpSocket(this);
    //2.为客户端分配套接字描述符 socket id

    socket->setSocketDescriptor(handle);

    connect(this,
                SIGNAL(transferData(QByteArray)),
                socket,
                SLOT(sendToClientSlot(QByteArray)));
}
