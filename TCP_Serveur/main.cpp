#include "TCP_Serveur.h"
#include "MyThread.h"
#include <QtWidgets/QApplication>
#include <qcoreapplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TCP_Serveur w;
	MyThread t;
	//w.StartServeur();
    //w.show();
    return a.exec();
}
