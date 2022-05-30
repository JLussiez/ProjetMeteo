#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Meteo.h"

#include <QObject>
#include <qdebug.h>

#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QSqlQuery>
#include <QtSql>

#include "Dask.h"

#include <qtcpsocket.h>			//Bibliothèque Socket
#include <qtcpserver.h>			//Bibliothèque de création Serveur TCP

#include <QHostAddress>
#include <QFile>
#include <QTextStream>

#include "ui_Meteo.h"
#include "Anemometre.h"
#include "Girouette.h"
#include "Barometre.h"
#include "Thermometre.h"
#include "Hygrometre.h"
#include "Solarimetre.h"
#include "Pluviometre.h"
#include "DetecteurJourNuit.h"
#include "DetecteurPluie.h"
#include "PrevisionMeteo.h"
#include "BDD.h"

class Meteo : 
	public QMainWindow
{
    Q_OBJECT

	public:
		Meteo(QWidget *parent = Q_NULLPTR);
		void GererTension();
		void Prevision();
		int j = 0;

		//Les classes sont en public pour pouvoir les utiliser
		Anemometre *anemometre;
		Girouette *girouette;
		Barometre *barometre;
		Thermometre *thermometre;
		Hygrometre *hygrometre;
		Solarimetre *solarimetre;
		Pluviometre *pluviometre;
		DetecteurJourNuit *detecteurjournuit;
		DetecteurPluie *detecteurpluie;
		BDD *bdd;
		void ValeurActuelEtPrevision();

	private:
		Ui::MeteoClass ui;
		QSqlDatabase db;
		PrevisionMeteo *previsionmeteo;

		QTcpSocket socket;

	private slots:
		void TestTension();
		void onClientReadyRead();
};