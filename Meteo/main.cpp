#include "Meteo.h"
#include "websocket.h"
#include <QtWidgets/QApplication>
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Meteo w;
    w.show();
	new Meteo();
	QTimer *timer;
    return a.exec();
}