#include "TransToCmdSeq.h"
#include<QTime>

TransToCmdSeq* TransToCmdSeq::TransToCmdSeq = NULL;

TransToCmdSeq::TransToCmdSeq()
{
//    生成jamLevel
//    int *jamLevel = new int[32];
//    for(int i=0;i<32;i++)
//    {
//        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//        int a = qrand()%2;   //随机生成0到2的随机数
//        jamLevel[i] = a;
//    }

    //生成rotateconfig.ini
    //saveSettings();
    QVector<int> edgeVec = getEdgeArray(2, 8, jamLevel);
    QVector<int> rotateVec = getRotateArray( edgeVec);
    QString str = getCarControlInstruction( rotateVec);
    qDebug()<<"cmd："<<str;
    //emit carControlData(str);   //槽函数就不写了哈，实现QString->Json
}

TransToCmdSeq *TransToCmdSeq::getRoutePtr()
{
    if(trans == NULL)
    {
        trans = new TransToCmdSeq;
    }
    return trans;
}

//得到路径数组
QVector<int> TransToCmdSeq::getEdgeArray(int startPoint, int endPoint, int *jamLevel)
{
    QVector<int> edgeVec;
    QVector<int> nodeVec = Route::getRoutePtr()->minRouteJam(startPoint,endPoint,jamLevel);
    QVector<int>::iterator iter;
    int i;
    for(iter = nodeVec.begin(),i=0; iter != nodeVec.end() - 1; iter++,i++)
    {
        edgeVec.append( Route::getRoutePtr()->getNodeToEdge(*iter,*(iter+1)) );
//        qDebug()<<"edgeVec："<<edgeVec.at(i);
    }
    return edgeVec;
}

//由路径数组得到旋转数组
QVector<int> TransToCmdSeq::getRotateArray(QVector<int> edgeVec)
{
    QVector<int> rotateVec;
    QVector<int>::iterator iter;
    int i= 0;
    //由路径数组得到旋转角数组
    QSettings set("rotateconfig.ini",QSettings::IniFormat);
    for(i = 0,iter = edgeVec.begin(); iter != edgeVec.end(); i++, iter++)
    {
        int edge = *iter;
        int rotate = set.value("TransToCmdSeqGroup/"+QString::number(edge)).toInt();
        rotateVec.append(rotate);
//        qDebug()<<"rotateVec："<<rotateVec.at(i);
    }
    return rotateVec;
}

QString TransToCmdSeq::getCarControlInstruction(QVector<int> rotateVec)
{
    QVector<int>::iterator iter;
    QString cmd;  //小车控制指令
    int i= 0;
    //由旋转角数组得到控制指令
    cmd.append("0"); //第一条道路默认前进
    for(iter = rotateVec.begin(),i=0; iter != rotateVec.end(); iter++,i++)
    {
        switch( *(iter+1) - *iter)  //后一条与前一条路径旋转角的差值
        {
            case 0 :   cmd.append("0");  break;                 //前进
            case 90:   case -270:   cmd.append("1");  break;    //左转
            case -90:  case 270:    cmd.append("2");  break;    //右转
            default:   break;
        }
    }
    return cmd;
}

//设置旋转角配置文件，只调用一次
void TransToCmdSeq::saveSettings()
{
    QSettings set("rotateconfig.ini",QSettings::IniFormat);
    set.beginGroup("TransToCmdSeqGroup");
    int rotate180[9] = {0,2,4,12,14,16,26,28,30};
    int rotate0[9] = {1,3,5,13,15,17,27,29,31};
    int rotate90[7] = {7,9,11,19,21,23,25};
    int rotate270[7] = {6,8,10,18,20,22,24};
    for(int i=0; i<9; i++)
    {
        set.setValue(QString::number(rotate180[i]),"180");
        set.setValue(QString::number(rotate0[i]),"0");
    }
    for(int i=0; i<7; i++)
    {
        set.setValue(QString::number(rotate90[i]),"90");
        set.setValue(QString::number(rotate270[i]),"270");
    }
    set.endGroup();
}
