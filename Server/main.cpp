#include <QCoreApplication>
#include "Network/mytcpserver.h"
#include "Database/database.h"
#include "SerialPort/serialportdevice.h"
#include "SerialPort/serialportprotocol.h"
#include "HandleData/handledata.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //启动服务器
    MyTcpServer::getServerPtr();
    //打开串口
    SerialportDevice::getDeviceptr();
    SerialPortProtocol::getSerialPortProtocolPtr();
    HandleData::getHandlePtr();

//    //数据库操作
//    database db;
//        //1.初始化数据库
//    db.initDatabase();
//        //2.建表
////    db.createTable();
////        //3.插入数据
////    db.insertData("xiaoming","male");
////    db.insertData("李白","male");
////    db.insertData("蔡文姬","female");
//        //4.查询数据
//    db.selectData();

//    //exec():进入事件循环
    return a.exec();
}
