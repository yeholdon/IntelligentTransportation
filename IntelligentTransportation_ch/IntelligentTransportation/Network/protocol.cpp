#include "protocol.h"

Protocol::Protocol(QObject *parent) : QObject(parent)
{

}

//封装成通用的函数
QByteArray Protocol::packData(int type, QString key1, QString value1, QString key2, QString value2, QString key3, QString value3)
{
     QJsonObject json;
     json.insert("type",type);
     //插入其他键值对时判断是否为空
     if(!key1.isEmpty())
     {
         json.insert(key1,value1);
     }
     if(!key2.isEmpty())
     {
         json.insert(key2,value2);
     }
     if(!key3.isEmpty())
     {
         json.insert(key3,value3);
     }
     //将json对象转换为json文档
     QJsonDocument jsonDoc(json);
     //将json文档转换为数组（QByteArray）
     return jsonDoc.toJson();
}
