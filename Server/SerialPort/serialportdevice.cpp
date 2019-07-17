#include "serialportdevice.h"
#include "serialportprotocol.h"
SerialportDevice* SerialportDevice::device = NULL;

SerialportDevice::SerialportDevice(QObject *parent) : QObject(parent)
{
    serial = NULL;
    device = NULL;
    //一般在构造函数中调用配置文件接口
    //saveSettings();
    readSettings();
    //初始化并打开串口
    initSerialPort();
    openSerialPort();
}

SerialportDevice *SerialportDevice::getDeviceptr()
{
    if(device == NULL)
    {
        device = new SerialportDevice;
    }
    return device;
}

void SerialportDevice::initSerialPort()
{
    if(serial == NULL)
    {
        serial = new QSerialPort;
    }
    connect(serial,SIGNAL(readyRead()),this,SLOT(readSerialPortSlot()));
    //1.设置 波特率
    serial->setBaudRate(baudRate);
    //帧格式
    //2.设置 数据位
    serial->setDataBits(QSerialPort::Data8);
    //3.设置 停止位
    serial->setStopBits(QSerialPort::OneStop);  //1个校验位
    //4.设置 校验位
    serial->setParity(QSerialPort::NoParity);   //无校验位
    //5.流控制
    serial->setFlowControl(QSerialPort::NoFlowControl); //无流控制

}

bool SerialportDevice::openSerialPort()
{
    QStringList list = getSerialPort();
    if(list.isEmpty())
    {
        return false;
    }
    if(serial == NULL)
    {
        initSerialPort();
    }
    //将serial设置为可以使用的端口名
    serial->setPortName(portName);
    if(serial->open(QIODevice::ReadWrite))
    {
        //打开串口成功，以读写的方式打开
        qDebug()<<"打开的串口名："<<serial->portName();
        return true;
    }
    return false;
}





bool SerialportDevice::writeSerialPort(const QByteArray &data)
{
    if(serial == NULL)
        return false;
    if(serial->isOpen())
    {
        if(serial->write(data))
            return true;
    }
    return false;
}

//向串口发送数据 ////////////////////////////
void SerialportDevice::writeSerialPortSlot(const DataInfo &dataInfo)
{
    qDebug() << "writeSerialPortSlot" << (QString)dataInfo.data;
    if(serial == NULL){
        qDebug() << "serial == null";
        openSerialPort();
    }
    if(serial->isOpen())
    {
        QByteArray data  = SerialPortProtocol::getSerialPortProtocolPtr()->sendDeviceData(dataInfo);
//        qDebug()<< "向串口发送数据" <<data.toHex();
        serial->write(data);
    }
}

bool SerialportDevice::getState()
{
    if(serial == NULL)
        return false;
    if(serial->isOpen())
    {
        return true;
    }
    return false;
}

QStringList SerialportDevice::getSerialPort()
{
    QStringList list;
    foreach (const QSerialPortInfo & info, QSerialPortInfo::availablePorts()) {
        list.append(info.portName());
    }
    qDebug()<<"本机串口名列表:"<<list;
    return list;
}

void SerialportDevice::saveSettings()
{
    //config.ini 为windows下的配置文件
    //组织结构：由多个组组成，每个组由多个键值对组成
    QSettings set("config.ini",QSettings::IniFormat);
    //先创建组，传入组名
    set.beginGroup("SerialPortGroup");
    //再创建键值对
    set.setValue("baudrate",57600);
    set.setValue("portname","COM3");
    //最后结束组
    set.endGroup();

}

void SerialportDevice::readSettings()
{
    //打开配置文件
    QSettings set("config.ini",QSettings::IniFormat);
    baudRate = set.value("SerialPortGroup/baudrate").toInt();
    portName = set.value("SerialPortGroup/portname").toString();
}

void SerialportDevice::readSerialPortSlot()
{
    QByteArray data;
    while(serial->bytesAvailable())
    {
        data.append(serial->readAll());
    }
    emit tranferData(data);
    qDebug()<<"从串口接收到的数据： "<<data.toHex();
}
