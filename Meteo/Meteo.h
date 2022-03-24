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

#include "ui_Meteo.h"
#include "Barometre.h"
#include "PrevisionMeteo.h"

class Meteo;

class Meteo : public QMainWindow
{
    Q_OBJECT

	public:
		Meteo(QWidget *parent = Q_NULLPTR);

	private:
		Ui::MeteoClass ui;

		QSqlDatabase db;

		Barometre *barometre;

		PrevisionMeteo *previsionmeteo;

	private slots:
		void TestTension();
};
