#ifndef DATAINFO_H
#define DATAINFO_H

typedef struct DataInfo
{
    quint8 addr[2]; //短地址
    quint8 len;     //有效数据长度
    quint8 type;
    QByteArray data;//有效数据
}sendInfo,receiveInfo;

#endif // DATAINFO_H
