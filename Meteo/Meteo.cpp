#include "Meteo.h"
#include "Dask.h"
#include "PrevisionMeteo.h"

Meteo::Meteo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	previsionmeteo = new PrevisionMeteo;

	/*
	anemometre = new Anemometre;
	girouette = new Girouette;
	*/
	barometre = new Barometre;
	/*
	hygrometre = new Hygrometre;
	thermometre = new Thermometre;
	solarimetre = new Solarimetre;
	pluviometre = new Pluviometre;
	detecteurpluie = new DetecteurPluie;
	detecteurjournuit = new DetecteurJourNuit;
	*/
}

void Meteo::TestTension()
{
	barometre->addTensionTest();
	barometre->convertionTensionPression();

	float Pression = barometre->getPression();
	//Convertion float QString
	QString QPression = QString::number(Pression);

	ui.Pression->setText(QPression +" mBar");

	//float Tension = (*barometre).getTension();
	float Tension = barometre->getTension();
	QString QTension = QString::number(Tension);

	ui.Tension->setText(QTension +" V");

	previsionmeteo->CatherineLaborde( *barometre );
}