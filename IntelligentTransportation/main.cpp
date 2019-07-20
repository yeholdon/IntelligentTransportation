#include <QApplication>
#include "UI/widget.h"
#include "Route/route.h"
#include "Network/network.h"
#include "Background/background.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Route::getRoutePtr();
    Network::getNetPtr();
    Network::getNetPtr()->initNetwork();
    Background *bgp = Background::getBgPtr();
//    bgp->routePlanSlot();
//    MainWindow w;
//    w = new Widget;
    Widget w;
//    Right w;
    w.show();

    return a.exec();
}
