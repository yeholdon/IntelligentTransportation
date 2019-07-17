#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
/*自定义服务类*/

#include <QObject>
#include <QTcpServer>
#include <QTextToSpeech>
#include <QSound>

#include "MyTcpSocket.h"

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
private:
    explicit MyTcpServer(QObject *parent = nullptr);
public:
    static MyTcpServer* getServerPtr();
    void sendDataToClient(const QByteArray& data);
protected:
    virtual void incomingConnection(qintptr handle);
signals:
    //void transferData(MyTcpSocket* socket,const QByteArray& data); //中继信号
    void transferData(const QByteArray& data);
public slots:

private:
    QTextToSpeech *speech;
    static MyTcpServer* serverPtr;
};

#endif // MYTCPSERVER_H
