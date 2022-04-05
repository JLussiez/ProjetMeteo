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

#include <QWebSocket>
#include <QWebSocketServer>

#include <qtcpsocket.h>			//Bibliothèque Socket
#include <qtcpserver.h>			//Bibliothèque de création Serveur TCP

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

class Meteo;

class Meteo : public QMainWindow
{
    Q_OBJECT

	public:
		Meteo(QWidget *parent = Q_NULLPTR);
		void GererTension();

		//Les classes sont en public pour pouvoir les 
		Anemometre *anemometre;
		Girouette *girouette;
		Barometre *barometre;
		Thermometre *thermometre;
		Hygrometre *hygrometre;
		Solarimetre *solarimetre;
		Pluviometre *pluviometre;
		DetecteurJourNuit *detecteurjournuit;
		DetecteurPluie *detecteurpluie;
	private:
		Ui::MeteoClass ui;

		QSqlDatabase db;

		

		PrevisionMeteo *previsionmeteo;

		void Projet();

	private slots:
		void TestTension();

};