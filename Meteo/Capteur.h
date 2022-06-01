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

class Capteur : 
	public QObject
{
	protected :
		Capteur();
		void ConnectCarte();
		I16 card;
		int NumeroChannel;

	public :
		double Tension;
		float getTension();
		void priseTension();

	private slots :
		void onServerNewConnection();
};