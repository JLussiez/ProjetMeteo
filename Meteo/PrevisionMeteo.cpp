#include "PrevisionMeteo.h"

PrevisionMeteo::PrevisionMeteo()
{
}

void PrevisionMeteo::CatherineLaborde(Barometre& Barometre, Thermometre& Thermometre, DetecteurPluie& DetecteurPluie)
{
	float Pression = Barometre.getPression();
	float Temperature = Thermometre.getTemperature();
	int Pluie = DetecteurPluie.getPluie();

	qDebug() << Pression;

	if (Pression < 960 || Pression > 1060)
	{
		//erreur : impossible
		QString Temps = "ERREUR";
	} else if (Pression >= 1015 && Pression < 1060)
	{
		//Temps ensolleillé
		QString Temps = "Ensoleille";
	} else if ( Pression <= 1015 && Pression > 1000)
	{
		if (Pluie = 1)
		{
			//Formation de neige vers -5 et 1 °C
			if (Temperature > -5 && Temperature < 1)
			{
				//Neige
				QString Temps = "Neige";
			}
			else if (Temperature < -10)
			{
				//Grèle
				QString Temps = "Grele";
			}
			else
			{
				//Pluvieux
				QString Temps = "Pluvieux";
			}
		}
		else
		{
			QString Temps = "Ensoleillé";
		}
		
	} else if ( Pression <= 1000 && Pression > 960)
	{
		//Tempête
		//génère des vents dépassent 89 km / h

		QString Temps = "Tempete";
	}
	//query.prepare("INSERT INTO `Prevision Meteo`(`Prevision`) VALUES ('" + Temps + "')");
	//query.exec();
	PrevisionMeteo::Future();
}

void PrevisionMeteo::Future()
{
	//Si on connait exactement l'état initial
	// + Si on connait exactement les lois d'évolution
	// -> Prévision = parfaite (ca arrivera pas mdr)


	//Reprendre les anciennes prévision météo : 

	//Comparer les différentes Pression

		//Toute les heures : 
		// Monté de 0,25 à 0,5 : Venue d'une haute préssion (sur long terme) = 1015 hPa = beau temps
		// Monté de 1 à 2 : Venue d'une moyenne pression (sur court terme) = 
		// Descente 0,25 à 0,5 : Venue d'une basse pression (sur long terme) = 1010 hPa = risque de pluie, ciel nuageux
		// Descente 1 à 2 : tempête (été = orage)

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