#ifndef TRANSTOCMDSEQ_H
#define TRANSTOCMDSEQ_H
#include <QSettings>
#include "route.h"

class TransToCmdSeq
{
public:
    TransToCmdSeq();
    static TransToCmdSeq* getRoutePtr();
    //小车指令生成接口
    QVector<int> getEdgeArray(int s,int e,int* jam_level);
    QVector<int> getRotateArray(QVector<int> edgeVec);
    QString getCarControlInstruction(QVector<int> rotateVec);
    //旋转角配置接口
    void saveSettings();

signals:
    void carControlData(QString str);

private:
    static TransToCmdSeq* trans;
};

#endif // TransToCmdSeq_H
