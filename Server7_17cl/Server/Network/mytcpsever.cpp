#include "mytcpsever.h"
#include<QDebug>
MytcpSever::MytcpSever(QObject *parent) : QTcpServer(parent)
{
    this->listen(QHostAddress::AnyIPv4,10001);
    speech = new QTextToSpeech;
    speech->say("hello world 智能交通服务器已启动");
}
//当新客户端连接服务器后，该函数会被自动触发
void MytcpSever::incomingConnection(qintptr handle)
{
    //1.构造套接字对象
    MySocket *socket=new MySocket(this);
    //2.设置套接字描述符
    socket->setSocketDescriptor(handle);
    //qDebug<<"新连接:"<<socket->peerAddress().toString();
    //客户端可以给我发消息，我转发
    connect(socket,SIGNAL(transferData(MySocket*,QByteArray)),this,SIGNAL(transferData(MySocket*,QByteArray)));//第一个：每一个套接字都有的信号；第二个：this:当前MyTcpServer对象有的信号
    //客户端可以接受我的消息
    connect(this,SIGNAL(transferData(MySocket*,QByteArray)),socket,SLOT(receiveMassDataSlot(MySocket*,QByteArray)));//将MyTcpServer对象的绑定到每一个socket的槽函数(每一个新连接的客户端socket)

}
