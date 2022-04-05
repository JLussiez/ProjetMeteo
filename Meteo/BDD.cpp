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
		qDebug() << "Déco";
		qDebug() << db.lastError();
	}

}

void BDD::requete(bool JN)
{
	QSqlQuery req;
	req.prepare("INSERT INTO Capteur (Date, Vitesse_Vent, Position_Vent, Pression, Humidite, Temperature, Solarimetre, Pluviometre, Pluie, JourNuit) VALUES(?,?,?,?,?,?,?,?,?,?) ");
	req.addBindValue("2022-04-01");
	req.addBindValue(0);
	req.addBindValue("N");
	req.addBindValue(0);
	req.addBindValue(0);
	req.addBindValue(20);
	req.addBindValue(0);
	req.addBindValue(0);
	req.addBindValue(0);
	req.addBindValue(JN);

	if (req.exec()) {
		qDebug() << "requete envoyer";
	}
	else
	{
		qDebug() << "Pas envoyer";
		qDebug() << req.lastError();

	}

}

