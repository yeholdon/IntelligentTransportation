#include "protocol.h"

Protocol::Protocol(QObject *parent) : QObject(parent)
{

}

QByteArray Protocol::packData(int type, QString key1, QString value1, QString key2, QString value2, QString key3, QString value3, QString key4, QString value4)
{
    // 定义时不能写默认参数，只在声明里写
    QJsonObject json;
    // 身份标识，一个5个键值对
    json.insert("type", type);
    if(!key1.isEmpty()) {
        json.insert(key1, value1);
    }
    if(!key2.isEmpty()) {
        json.insert(key2, value2);
    }
    if(!key3.isEmpty()) {
        json.insert(key3, value3);
    }
    if(!key4.isEmpty()) {
        json.insert(key4, value4);
    }
    // 用于将json对象转换成方便直接传输的字节流
    QJsonDocument jsonDoc(json);
    return jsonDoc.toJson();// 把json对象转换成QByteArrray类型，方便直接传输
}
