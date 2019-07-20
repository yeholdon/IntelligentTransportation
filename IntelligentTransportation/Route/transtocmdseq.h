#ifndef TRANSTOCMDSEQ_H
#define TRANSTOCMDSEQ_H
#include <QSettings>
#include "route.h"

class TransToCmdSeq
{
public:
    static TransToCmdSeq* getRoutePtr();
    //小车指令生成接口
    QVector<int> getEdgeArray(QVector<int> nodeVec);
    QVector<int> getRotateArray(QVector<int> edgeVec);
    QString getCarControlInstruction(QVector<int> rotateVec);
    //旋转角配置接口
    void saveSettings();

signals:
    void carControlData(QString str);

private:
    static TransToCmdSeq* trans;
    TransToCmdSeq();
    int jam_level[32];
};

#endif // TransToCmdSeq_H
