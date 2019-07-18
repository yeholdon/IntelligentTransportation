#include "route.h"

Route* Route::route = NULL;

Route::Route(QObject *parent) : QObject(parent)
{
    initNodeToEdge();
}

Route* Route::getRoutePtr()
{
    if(route == NULL)
    {
        route = new Route;
    }
    return route;
}

int Route::getNodeToEdge(int a, int b)
{
    //当0<=a<=11和0<=a<=11时，返回对应的边值
    if(a>=0&&a<12&&b>=0&&b<12)
        return nodeToEdge[a][b];
    else
    //否则返回-1
        return -1;
}

void Route::initNodeToEdge()
{
    //当两个路口之间没有直接相连的道路时返回-1
    for(int i = 0;i<MAXV;i++)
        for(int j = 0;j<MAXV;j++)
            nodeToEdge[i][j] = -1;
    nodeToEdge[1][0] = 0;nodeToEdge[7][3] = 11;nodeToEdge[6][10] = 22;
    nodeToEdge[0][1] = 1;nodeToEdge[5][4] = 12;nodeToEdge[10][6] = 23;
    nodeToEdge[2][1] = 2;nodeToEdge[4][5] = 13;nodeToEdge[7][11] = 24;
    nodeToEdge[1][2] = 3;nodeToEdge[6][5] = 14;nodeToEdge[11][7] = 25;
    nodeToEdge[3][2] = 4;nodeToEdge[5][6] = 15;nodeToEdge[9][8] = 26;
    nodeToEdge[2][3] = 5;nodeToEdge[7][6] = 16;nodeToEdge[8][9] = 27;
    nodeToEdge[0][4] = 6;nodeToEdge[6][7] = 17;nodeToEdge[10][9] = 28;
    nodeToEdge[4][0] = 7;nodeToEdge[4][8] = 18;nodeToEdge[9][10] = 29;
    nodeToEdge[1][5] = 8;nodeToEdge[8][4] = 19;nodeToEdge[11][10] = 30;
    nodeToEdge[5][1] = 9;nodeToEdge[5][9] = 20;nodeToEdge[10][11] = 31;
    nodeToEdge[3][7] = 10;nodeToEdge[9][5] = 21;
}

void Route::initRouteJam(int *jam_level)
{
    //初始化图的边权（距离）
    for(int i = 0;i<3;i++)
        G[i][i+1] = G[i+1][i] = 1;
    for(int i = 4;i<7;i++)
        G[i][i+1] = G[i+1][i] = 1;
    for(int i = 8;i<11;i++)
        G[i][i+1] = G[i+1][i] = 1;
    G[0][4] = G[4][0] = 1;
    G[1][5] = G[5][1] = 1;
    G[3][7] = G[7][3] = 1;
    G[4][8] = G[8][4] = 1;
    G[5][9] = G[9][5] = 1;
    G[6][10] = G[10][6] = 1;
    G[7][11] = G[11][7] = 1;
    //初始化交通拥堵
    for(int i = 0;i<MAXV;i++)
    {
        for(int j = 0;j<MAXV;j++)
        {
            if(nodeToEdge[i][j] != -1)
            {
                JAM[i][j] = jam_level[nodeToEdge[i][j]];
            }
        }
    }
}

void Route::initRoute()
{
    //初始化图的边权（距离）
    for(int i = 0;i<3;i++)
        G[i][i+1] = G[i+1][i] = 1;
    for(int i = 4;i<7;i++)
        G[i][i+1] = G[i+1][i] = 1;
    for(int i = 8;i<11;i++)
        G[i][i+1] = G[i+1][i] = 1;
    G[0][4] = G[4][0] = 1;
    G[1][5] = G[5][1] = 1;
    G[3][7] = G[7][3] = 1;
    G[4][8] = G[8][4] = 1;
    G[5][9] = G[9][5] = 1;
    G[6][10] = G[10][6] = 1;
    G[7][11] = G[11][7] = 1;

}
QVector<int> Route::minRouteJam(int s, int e, int *jam_level)
{

    //初始化
    for(int i = 0;i<MAXV;i++)
        for(int j = 0;j<MAXV;j++)
            G[i][j] = INF;
    initRouteJam(jam_level);
    for(int i= 0;i<MAXV;i++)
        d[i] = INF;
    d[s] = 0;
    for(int i= 0;i<MAXV;i++)
        c[i] = INF;
    c[s] = 0;
    for(int i = 0;i<MAXV;i++)
        pre[i] = i;
    for(int i = 0;i<MAXV;i++)
        vis[i] = 0;
    //dijkstra算法
    for(int i = 0;i<MAXV;i++)
    {
        int temp = INF;int u = -1;
        for(int j = 0;j<MAXV;j++)
        {
            if(!vis[j] && temp > d[j])
            {
                temp = d[j];
                u = j;
            }
        }
        vis[u] = 1;
        for(int v= 0;v<MAXV;v++)
        {
            if(!vis[v] && G[u][v] != INF)
            {
                if(d[u]+G[u][v] < d[v])
                {
                    d[v] = d[u]+G[u][v];
                    c[v] = c[u] + JAM[u][v];
                    pre[v] = u;
                }
                else if(d[u]+G[u][v] == d[v]){
                    if(c[u]+JAM[u][v] < c[v])
                    {
                        c[v] = c[u]+JAM[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
    vec.clear();
    dfs(e,s);
    //输出最短路径和最小的拥塞值
//    qDebug()<<d[0]<<" "<<c[0];
    return vec;
}

QVector<int> Route::minRoute(int s, int e)
{
    //初始化
    for(int i = 0;i<MAXV;i++)
        for(int j = 0;j<MAXV;j++)
            G[i][j] = INF;
    initRoute();
    for(int i= 0;i<MAXV;i++)
        d[i] = INF;
    d[s] = 0;
    for(int i = 0;i<MAXV;i++)
        pre[i] = i;
    for(int i = 0;i<MAXV;i++)
        vis[i] = 0;

    //dijkstra算法
    for(int i = 0;i<MAXV;i++)
    {
        int temp = INF;int u;
        for(int j = 0;j<MAXV;j++)
        {
            if(!vis[j] && temp > d[j])
            {
                temp = d[j];
                u = j;
            }
        }
        vis[u] = 1;
        for(int v= 0;v<MAXV;v++)
        {
            if(!vis[v] && G[u][v] != INF && d[u]+G[u][v] < d[v])
            {
                d[v] = d[u]+G[u][v];
                pre[v] = u;
            }
        }
    }
    vec.clear();
    dfs(e,s);
    //输出最短路径值
    qDebug()<<d[0];
    return vec;
}

void Route::dfs(int v, int s)
{
    if(v == s)
    {
        vec.push_back(v);
        return;
    }
    dfs(pre[v],s);
    vec.push_back(v);
}
