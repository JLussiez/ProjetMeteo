#pragma once
#include <QObject>
#include <qdebug.h>

#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QSqlQuery>
#include <QtSql>

#include "Dask.h"

#include <QWebSocket>
#include <QWebSocketServer>
#include <QFile>
#include <QTextStream>
#include <Windows.h>

#include <conio.h>
#include <iostream>
#include "Include/Dask64.h"

#include <QtWidgets/QMainWindow>
#include "ui_Meteo.h"
class Capteur : 
	public QObject
	//public QMainWindow
{
	protected :
		Capteur();
		void ConnectCarte();
		I16 card;
		int NumeroChannel;
		int NumeroChannelDI;
		//Ui::MeteoClass ui;

	public :
		U16 Digital;
		double Tension;
		float getTension();
		bool getDigital();
		void priseTension();
		void priseDigital();

	private slots :
		void onServerNewConnection();
};