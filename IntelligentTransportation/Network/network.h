#ifndef NETWORK_H
#define NETWORK_H
/*
 * 网络接口类
 */
#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>

class Network : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    static Network *netPtr; // 单例网络对象
    bool flag;
private:

    explicit Network(QObject *parent = nullptr);
public:
    static Network *getNetPtr();
    void initNetwork();
    bool sendNetData(const QByteArray &data);

signals:
    // 参数带json对象比较好
    void SendDataToWindow(const QJsonObject &json);
public slots:
    void connectedSlot();
    void readDataSlot();
    void disconnectSlot();
};

#endif // NETWORK_H
