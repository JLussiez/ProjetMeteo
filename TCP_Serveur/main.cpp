#include "TCP_Serveur.h"
#include <QtWidgets/QApplication>
#include <qcoreapplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TCP_Serveur w;
	w.StartServeur();
    //w.show();
    return a.exec();
}
