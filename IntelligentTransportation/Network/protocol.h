#ifndef PROTOCOL_H
#define PROTOCOL_H
// 协议类
#include <QObject>
#include <QJsonObject> // json对象,以键值对形式
#include <QJsonDocument> // json文档，提供数据
#include <QJsonArray> // json数组，可以放json对象，也可放标准数据类型

class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = nullptr);
    // 1. 信息的唯一标识符 2. 之后每两个参数就是一个键值对。默认参数更灵活
    static QByteArray packData(int type, QString key1 = "", QString value1 = "",
                               QString key2 = "", QString value2 = "",
                               QString key3 = "", QString value3 = "",
                               QString key4 = "", QString value4 = "");

signals:

public slots:
};

#endif // PROTOCOL_H
