#ifndef NETWORK_H
#define NETWORK_H
/*网络接口类*/

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

//单例模式、单例类
class Network : public QObject
{
    Q_OBJECT
//单例模式的封装
//1.类的构造函数为私有的
private:
    explicit Network(QObject *parent = nullptr);
public:
    static Network* getNetPtr();
    void initNetwork();
    bool sendNetData(const QByteArray& data);

private:
    //静态成员必须在类的外部进行初始化，因为静态成员不属于类的对象，属于类的
    //只有静态的成员函数才能访问静态的成员函数
    static Network* netPtr;
    QTcpSocket *socket;
    bool flag;  //客户端是否与服务器连接成功
signals:
    void sendDataWindow(const QJsonObject& json);
public slots:
    void connectSLot();   //当客户端成功连接到服务器时，客户端的套接字发出信号，该槽函数被触发
    void readDataSLot();  //当客户端的套接字接收到数据时，套接字发出信号，该槽函数被触发
    void disconnectSlot();  //当客户端与服务器断线时，套接字发出信号，该槽函数被触发，请求重连
};

#endif // NETWORK_H
