#include "ProjetMeteo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProjetMeteo w;
    w.show();
    return a.exec();
}
