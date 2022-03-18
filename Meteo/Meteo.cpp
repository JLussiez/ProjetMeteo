#include "Meteo.h"
#include "Dask.h"

Meteo::Meteo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Barometre barometre;
}

void Meteo::TestTension()
{
	(*barometre).addTensionTest();

	(*barometre).convertionTensionPression();

	float Pression = (*barometre).getPression();
	//Convertion float QString
	QString QPression = QString::number(Pression);

	ui.Pression->setText(QPression);

	float Tension = (*barometre).getTension();
	QString QTension = QString::number(Tension);

	ui.Tension->setText(QTension);
}