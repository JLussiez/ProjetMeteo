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
		//Temps ensolleill�
		QString Temps = "Ensoleille";
	} else if ( Pression <= 1015 && Pression > 1000)
	{
		if (Pluie = 1)
		{
			//Formation de neige vers -5 et 1 �C
			if (Temperature > -5 && Temperature < 1)
			{
				//Neige
				QString Temps = "Neige";
			}
			else if (Temperature < -10)
			{
				//Gr�le
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
			QString Temps = "Ensoleill�";
		}
		
	} else if ( Pression <= 1000 && Pression > 960)
	{
		//Temp�te
		//g�n�re des vents d�passent 89 km / h

		QString Temps = "Tempete";
	}
	//query.prepare("INSERT INTO `Prevision Meteo`(`Prevision`) VALUES ('" + Temps + "')");
	//query.exec();
	PrevisionMeteo::Future();
}

void PrevisionMeteo::Future()
{
	//Si on connait exactement l'�tat initial
	// + Si on connait exactement les lois d'�volution
	// -> Pr�vision = parfaite (ca arrivera pas mdr)


	//Reprendre les anciennes pr�vision m�t�o : 

	//Comparer les diff�rentes Pression

		//Toute les heures : 
		// Mont� de 0,25 � 0,5 : Venue d'une haute pr�ssion (sur long terme) = 1015 hPa = beau temps
		// Mont� de 1 � 2 : Venue d'une moyenne pression (sur court terme) = 
		// Descente 0,25 � 0,5 : Venue d'une basse pression (sur long terme) = 1010 hPa = risque de pluie, ciel nuageux
		// Descente 1 � 2 : temp�te (�t� = orage)

	//Compare les diff�rentes Pr�vision
}

void PrevisionMeteo::EnvoieDonnee(Anemometre& Anemometre, Girouette& Girouette, Barometre& Barometre, Hygrometre& Hygrometre, Thermometre& Thermometre, Solarimetre& Solarimetre, Pluviometre& Pluviometre, DetecteurPluie& DetecteurPluie, DetecteurJourNuit& DetecteurJourNuit)
{
	//Connexion � BDD
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

	//Requet envoie m�t�o dans BDD, bonne chance Louis :)
	//query.prepare("INSERT INTO `Capteur`(`Vitesse_Vent`, `Position_Vent`, `Pression`, `Humidite`, `Temperature`, `Solarim�tre`, `Pluviom�tre`, `Pluie`, `Jour/Nuit`) VALUES('"+ Vitesse_Vent +"', '" + Position_Vent +"', '" + Pression +"', '" + Humidite +"', '" + Temperature +"', '" + Luminosite +"', '" + QuantitePluie +"', '" + Pluie +"', '" + JourNuit +"'");

	if (query.exec())
	{
		qDebug() << "Insert Effectu�";
		//R�cup�re le r�sultat de la requ�te
		query.next();
		QString IDUser = query.value(0).toString();
	}
}