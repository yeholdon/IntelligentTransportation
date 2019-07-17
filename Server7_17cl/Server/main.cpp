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
    return a.exec();
}
