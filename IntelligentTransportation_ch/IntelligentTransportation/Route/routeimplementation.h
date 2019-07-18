#ifndef ROUTEIMPLEMENTATION_H
#define ROUTEIMPLEMENTATION_H
#include <QSettings>
#include "route.h"

class RouteImplementation
{
public:
    RouteImplementation();
    static RouteImplementation* getRoutePtr();
    //小车指令生成接口
    QVector<int> getEdgeArray(int s,int e,int* jam_level);
    QVector<int> getRotateArray(QVector<int> edgeVec);
    QString getCarControlInstruction(QVector<int> rotateVec);
    //旋转角配置接口
    void saveSettings();

signals:
    void carControlData(QString str);

private:
    static RouteImplementation* routeImplementation;
};

#endif // ROUTEIMPLEMENTATION_H
