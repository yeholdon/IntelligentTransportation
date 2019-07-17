#ifndef PROTOCOL_H
#define PROTOCOL_H
/*协议类*/
#include <QObject>
#include <QJsonObject>     //json对象
#include <QJsonDocument>   //json文档
#include <QJsonArray>      //json数组
#include <QString>
class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = nullptr);
    static QByteArray packData(int type,QString key1="",QString value1 = "",
                               QString key2="",QString value2 = "",
                               QString key3="",QString value3 = "",
                               QString key4="",QString value4 = "");  //按协议打包函数,默认参数值，可串1-4对键值对
signals:

public slots:
};

#endif // PROTOCOL_H
