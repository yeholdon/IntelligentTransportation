#include "window/mainwindow.h"
#include <QApplication>

#include "Route/route.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Route::getRoutePtr();
    MainWindow w;
    w.show();

    return a.exec();
}
