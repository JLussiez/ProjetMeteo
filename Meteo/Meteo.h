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

#include <qtcpsocket.h>			//Biblioth�que Socket
#include <qtcpserver.h>			//Biblioth�que de cr�ation Serveur TCP

#include <QFile>
#include <QTextStream>

class Meteo;

class Meteo : public QMainWindow
{
    Q_OBJECT

	public:
		Meteo();
		Meteo(quint16 port);

	private:
		Ui::MeteoClass ui;

	private:

		QSqlDatabase db;

		QTimer *timer;
};
