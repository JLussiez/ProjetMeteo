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
		//Temps ensolleill�

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() << "Ensolleill�";
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
		//Temp�te

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() << "Temp�te";
		PrevisionMeteo::Future();
	}

}

void PrevisionMeteo::Future()
{
	//Reprendre les anciennes pr�vision m�t�o : 

	//Comparer les diff�rentes Pression

	//Compare les diff�rentes Pr�vision

}

/*
void PrevisionMeteo::EnvoieDonnee(Anemometre& Anemometre, Girouette& Girouette, Barometre& Barometre, Hygrometre& Hygrometre, Thermometre& Thermometre, Solarimetre& Solarimetre, Pluviometre& Pluviometre, DetecteurPluie& DetecteurPluie, DetecteurJourNuit& DetecteurJourNuit)
{
	//Connexion � BDD
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.65.201");
	db.setDatabaseName("Meteo");
	db.setUserName("root");
	db.setPassword("root");
	QSqlQuery query(db);

	Vitesse_Vent = Anemometre.getVitesseVent();
	Position_Vent = Girouette.getCardinalite();
	Pression = Barometre.getPression();
	Humidite = Hygrometre.getHumidite();
	Temperature = Thermometre.getTemperature();
	Luminositee = Solarimetre.getLuminosite();
	QuantitePluie = Pluviometre.getQuantitePluie();
	Pluie = CapteurPluie.getPluie();
	JourNuit = DetecteurJourNuit.getJourNuit();

	//query.prepare("INSERT INTO `Capteur`(`Vitesse_Vent`, `Position_Vent`, `Pression`, `Humidite`, `Temperature`, `Solarim�tre`, `Pluviom�tre`, `Pluie`, `Jour/Nuit`) VALUES('" + VitesseVent +"', '" + PosVent +"', '" + Pression +"', '" + Humidite +"', '" + Temperature +"', '" + Luminosite +"', '" + QuantitePluie +"', '" + Pluie +"', '" + JourNuit +"'");

	if (query.exec())
	{
		qDebug() << "Insert Effectu�";

		/*
		//R�cup�re le r�sultat de la requ�te
		query.next();
		QString IDUser = query.value(0).toString();

		query.prepare("INSERT INTO `Message`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		query.exec();

		//On r�cup�re le MSG100
		obj->write("MSG100");
	}
}
*/
