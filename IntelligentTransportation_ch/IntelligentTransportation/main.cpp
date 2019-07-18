#include "window/mainwindow.h"
#include <QApplication>

#include "Route/route.h"
#include "Route/routeimplementation.h"
#include "Network/network.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //启动路径
    Route::getRoutePtr();
    RouteImplementation::getRoutePtr();
    //启动网络
    Network::getNetPtr()->initNetwork();
    MainWindow w;
    w.show();



    return a.exec();
}
