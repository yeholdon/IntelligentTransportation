#ifndef ROUTE_H
#define ROUTE_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <cstdio>
#include <QDebug>
#include <QString>

const int MAXV = 12;    //图中顶点个数
const int INF = 0x3f3f3f3f;

class Route : public QObject
{
    Q_OBJECT
private:
    explicit Route(QObject *parent = nullptr);
public:
    static Route* getRoutePtr();
    //路径规划接口
    void initNodeToEdge();               //初始化
    void initRouteJam(int* jam_level);   //图的初始化 考虑拥堵
    void initRoute();                    //图的初始化 不考虑拥堵
    QVector<int> minRouteJam(int s,int e,int* jam_level);    //考虑拥堵
    QVector<int> minRoute(int s,int e);  //不考虑拥堵
    void dfs(int v,int s);
    int getNodeToEdge(int a,int b);      //由顶点得到对应的边

signals:

public slots:

private:
    static Route* route;
    int G[MAXV][MAXV];      //存放图
    int JAM[MAXV][MAXV];    //存放路的拥堵值
    int d[MAXV];            //当前最短路径值
    int c[MAXV];            //当前拥堵最小值
    int vis[MAXV] = {0};    //标记数组
    int pre[MAXV];          //存放最短路径的前驱节点
    QVector<int> vec;            //最短路径
    int nodeToEdge[MAXV][MAXV];         //邻接矩阵，由路口得到对应道路
};

#endif // ROUTE_H
