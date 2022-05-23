#pragma once
#include <QtSql>
#include <QtSql/QtSql>
#include <qsqldatabase.h>
#include <QObject>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QDebug>
#include "Capteur.h"

#include <QtWidgets/QMainWindow>
class BDD :
	public Capteur,
	public QMainWindow
{

public:

	BDD();
	

	void requete(float VitesseVent,QString PositionVent,float Pression, float Humidite,float Temperature,float Solarimetre, float Pluviometre,bool Pluie,bool JourNuit);

	void requetePrevision(QString Prevision,QString Duree);

private:
	QSqlDatabase db;
};

