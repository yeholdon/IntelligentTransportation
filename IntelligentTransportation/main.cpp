#include "window/mainwindow.h"
#include <QApplication>

#include "Route/route.h"
#include "Network/network.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Route::getRoutePtr();
    Network::getNetPtr();
    Network::getNetPtr()->initNetwork();
    MainWindow w;
    w.show();

    return a.exec();
}
