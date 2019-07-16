#ifndef PROTOCOL_H
#define PROTOCOL_H
/*协议类*/
//使用json来定义协议，将字节流变为具有json格式的

#include <QObject>
#include <QJsonObject>  //json对象
#include <QJsonDocument>    //json文档类：实现json和数组（QByteArray）之间格式转换
#include <QJsonArray>   //json数组

class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = nullptr);
    //打包数据：可以为0个，1个，2个，3个
    //默认参数值在函数声明的时候给参数赋值，函数定义时不能赋值
    //使用静态成员函数，不需要定义对象，直接使用类名来访问
    static QByteArray packData(int type,
                               QString key1 = "",QString value1 = "",
                               QString key2 = "",QString value2 = "",
                               QString key3 = "",QString value3 = "");

signals:

public slots:
};

#endif // PROTOCOL_H
