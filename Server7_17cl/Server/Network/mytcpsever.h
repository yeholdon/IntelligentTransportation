#ifndef MYTCPSEVER_H
#define MYTCPSEVER_H
/*自定义服务类*/
#include <QObject>
#include<QTcpServer>
#include"mysocket.h"
#include <QTextToSpeech>
#include<QHostAddress>
class MytcpSever : public QTcpServer
{
    Q_OBJECT
public:
    explicit MytcpSever(QObject *parent = nullptr);
protected://虚函数
    void incomingConnection(qintptr handle);//句柄

signals:
    void transferData(MySocket* socket,const QByteArray& data);
public slots:
private:
    QTextToSpeech *speech;
};

#endif // MYTCPSEVER_H
