#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Meteo.h"

#include <QObject>
#include <qdebug.h>

#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QSqlQuery>
#include <QtSql>
#include <QTimer>
#include "Dask.h"

#include <qtcpsocket.h>			//Bibliothèque Socket
#include <qtcpserver.h>			//Bibliothèque de création Serveur TCP
#include <QtWebSockets/qwebsocketserver.h>
#include <QtWebSockets/QtWebSockets>

#include <QHostAddress>
#include <QFile>
#include <QTextStream>

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

#include "Include/json.hpp"

// for convenience
using json = nlohmann::json;

class Meteo : 
	public QMainWindow
{
    Q_OBJECT

	public:
		Meteo(QWidget *parent = Q_NULLPTR);
		void GererTension();
		void Prevision();
		int j = 0;
		void SendJSONvalue();

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
		QString ValeurActuelEtPrevision();
		QTimer *timer;
		QWebSocket *unnomrandom;
		void Timer();

		QVector<QWebSocket *> ClientWeb;
		int ListeClient;

		~Meteo();

	private:
		Ui::MeteoClass ui;
		QSqlDatabase db;
		PrevisionMeteo *previsionmeteo;

		QTcpSocket socket;
		float PressionHmoins1 = 0;

		QWebSocketServer *webServer;
		

	private slots:
		void TestTension();
		void onClientReadyRead();
		void PriseMeteo();
		void onWebServerNewConnection();

		void onWebClientDisconnected();
		void slotSendJSONvalue();
};