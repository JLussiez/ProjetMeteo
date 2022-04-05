#include "Meteo.h"
#include "Dask.h"
#include "PrevisionMeteo.h"

Meteo::Meteo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	previsionmeteo = new PrevisionMeteo;


	anemometre = new Anemometre;
	girouette = new Girouette;
	barometre = new Barometre;
	//
	hygrometre = new Hygrometre;
	thermometre = new Thermometre;
	solarimetre = new Solarimetre;
	//
	pluviometre = new Pluviometre;
	detecteurpluie = new DetecteurPluie;
	detecteurjournuit = new DetecteurJourNuit;

	//Lancer le programme ici : boucle infini avec une attente de 10 minutes entre chaque execution ?
	//+ une variable partant de 0 jusqu'à 6, si =6 -> prévision météo
	int i = 1;
	int j = 0;

	//Boucle infini
	while (i == 1)
	{
		Projet();
		//Attente 10 minutes
		Sleep(600);
		j++;
		//Si ca fait 1h
		if (j == 6)
		{
			//Prévision météo
			previsionmeteo->Future();
			//Reset compteur
			j = 0;
		}
	}
	
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

	previsionmeteo->CatherineLaborde( *barometre, *thermometre, *detecteurpluie);
}

void Meteo::Projet()
{
	//Choper chaque valeur de chaque capteur
	GererTension();

	//Envoie en base + temps
	previsionmeteo->EnvoieDonnee(*anemometre, *girouette, *barometre, *hygrometre, *thermometre, *solarimetre, *pluviometre, *detecteurpluie, *detecteurjournuit);

}

void Meteo::GererTension()
{
	//getTension() de chaque capteur
	anemometre->getTension();
	girouette->getTension();
	barometre->getTension();
	//
	hygrometre->getTension();
	thermometre->getTension();
	solarimetre->getTension();
	//
	pluviometre->getTension();
	detecteurpluie->getTension();
	detecteurjournuit->getTension();

	//Convertion des données :
	anemometre->convertionTensionVitesseVent();
	girouette->convertionTensionCardinalite();
	barometre->convertionTensionPression();
	//
	hygrometre->convertionTensionHumidite();
	thermometre->convertionTensionTemperature();
	solarimetre->convertionTensionLuminosite();
	//
	pluviometre->convertionTensionQuantitePluie();
	detecteurpluie->convertionTensionPluie();
	detecteurjournuit->convertionTensionJourNuit();
}
