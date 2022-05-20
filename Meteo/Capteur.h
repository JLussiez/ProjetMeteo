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

class Capteur : 
	public QObject
{
	protected :
		Capteur();
		int ConnectCarte();
		I16 card;
		int NumeroChannel;

	public :
		double Tension;
		float getTension();

	private slots :
		void onServerNewConnection();
};

