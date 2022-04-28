#include "BDD.h"

void BDD::Connexionbdd()
{		
	this->db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.65.201");
	db.setDatabaseName("Meteo");
	db.setUserName("admin");
	db.setPassword("admin");

	if (db.open()) {
		qDebug() << "Connecter a la bdd";
	}
	else {
		qDebug() << "D�co";
		qDebug() << db.lastError();
	}

}

void BDD::requete(float VitesseVent, QString PositionVent, float Pression, float Humidite, float Temperature, float Solarimetre, float Pluviometre, bool Pluie, bool JourNuit)
{
	QSqlQuery req;
	req.prepare("INSERT INTO Capteur (Vitesse_Vent, Position_Vent, Pression, Humidite, Temperature, Solarimetre, Pluviometre, Pluie, JourNuit) VALUES(?,?,?,?,?,?,?,?,?) ");
	req.addBindValue(VitesseVent);
	req.addBindValue(PositionVent);
	req.addBindValue(Pression);
	req.addBindValue(Humidite);
	req.addBindValue(Temperature);
	req.addBindValue(Solarimetre);
	req.addBindValue(Pluviometre);
	req.addBindValue(Pluie);
	req.addBindValue(JourNuit);

	if (req.exec()) {
		qDebug() << "requete envoyer";
	}
	else
	{
		qDebug() << "Pas envoyer";
		qDebug() << req.lastError();

	}

}

