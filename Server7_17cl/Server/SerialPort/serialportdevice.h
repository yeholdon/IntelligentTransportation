#ifndef SERIALPORTDEVICE_H
#define SERIALPORTDEVICE_H
/*串口设备类*/

#include <QObject>
#include <QSerialPortINfo>  //列举本机串口信息
#include <QSerialPort>      //串口设备类
#include <QDebug>
#include <QStringList>  //字符串列表
#include <QSettings>    //配置文件类
#include "datainfo.h"

//单例模式类
class SerialportDevice : public QObject
{
    Q_OBJECT
private:
     explicit SerialportDevice(QObject *parent = nullptr);
public:
    static SerialportDevice* getDeviceptr();
    void initSerialPort();  //初始化串口的接口
    bool openSerialPort();  //打开串口的接口 
    bool getState();        //判断串口状态的接口
    QStringList getSerialPort();    //返回本机所有的串口
    //读写配置文件接口
    void saveSettings();
    void readSettings();
signals:
    void tranferData(const QByteArray& data);
public slots:
    //从串口读数据时，需要使用回调机制，所以用槽函数
    //当串口传来数据时，会发出信号，进而触发此槽函数
    void readSerialPortSlot();  //从串口读取数据的接口
    void writeSerialPortSlot(struct DataInfo dataInfo);   //向串口中写入data数据的接口
private:
    QSerialPort* serial;    //代表一个串口设备
    static SerialportDevice *device;
    qint32 baudRate;
    QString portName;

};

#endif // SERIALPORTDEVICE_H
