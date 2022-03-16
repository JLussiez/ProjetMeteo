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

class Capteur : 
	public QObject
{
	Q_OBJECT
	float Tension;

private :
	void ConnectCarte();


};

