#include "PrevisionMeteo.h"

PrevisionMeteo::PrevisionMeteo()
{
}

void PrevisionMeteo::CatherineLaborde(Barometre& Barometre)
{
	float Pression = Barometre.getPression();

	qDebug() << Pression;

	if (Pression < 960 || Pression > 1060)
	{
		//erreur : impossible

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() <<  "Impossible : Erreur";
		PrevisionMeteo::Future();

	} else if (Pression >= 1015 && Pression < 1060)
	{
		//Temps ensolleillé

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() << "Ensolleillé";
		PrevisionMeteo::Future();

	} else if ( Pression <= 1015 && Pression > 1000)
	{
		//Pluie

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() <<  "Pluvieux";
		PrevisionMeteo::Future();

	} else if ( Pression <= 1000 && Pression > 960)
	{
		//Tempête

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() << "Tempête";
		PrevisionMeteo::Future();
	}

}

void PrevisionMeteo::Future()
{
	//Reprendre les anciennes prévision météo : 

	//Comparer les différentes Pression

	//Compare les différentes Prévision

}


void PrevisionMeteo::EnvoieDonnee(Anemometre& Anemometre, Girouette& Girouette, Barometre& Barometre, Hygrometre& Hygrometre, Thermometre& Thermometre, Solarimetre& Solarimetre, Pluviometre& Pluviometre, DetecteurPluie& DetecteurPluie, DetecteurJourNuit& DetecteurJourNuit)
{
	//Connexion à BDD
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.65.201");
	db.setDatabaseName("Meteo");
	db.setUserName("root");
	db.setPassword("root");
	QSqlQuery query(db);

	float Vitesse_Vent = Anemometre.getVitesseVent();
	char Position_Vent = Girouette.getCardinalite();
	float Pression = Barometre.getPression();
	float Humidite = Hygrometre.getHumidite();
	float Temperature = Thermometre.getTemperature();
	float Luminosite = Solarimetre.getLuminosite();
	float QuantitePluie = Pluviometre.getQuantitePluie();
	bool Pluie = DetecteurPluie.getPluie();
	bool JourNuit = DetecteurJourNuit.getJourNuit();

	//Requet envoie météo dans BDD, bonne chance Louis :)
	//query.prepare("INSERT INTO `Capteur`(`Vitesse_Vent`, `Position_Vent`, `Pression`, `Humidite`, `Temperature`, `Solarimètre`, `Pluviomètre`, `Pluie`, `Jour/Nuit`) VALUES('"+ Vitesse_Vent +"', '" + Position_Vent +"', '" + Pression +"', '" + Humidite +"', '" + Temperature +"', '" + Luminosite +"', '" + QuantitePluie +"', '" + Pluie +"', '" + JourNuit +"'");

	if (query.exec())
	{
		qDebug() << "Insert Effectué";
		//Récupère le résultat de la requête
		query.next();
		QString IDUser = query.value(0).toString();
	}
}