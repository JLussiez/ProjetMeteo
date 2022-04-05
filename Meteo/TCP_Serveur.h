#pragma once

#include <QtWidgets/QMainWindow>
#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <qtwidgets>
#include <QtSql/QtSql>
#include <QSqlQuery>
#include <QDebug>
#include "Meteo.h"

class TCP_Serveur : public QMainWindow
{
	Q_OBJECT

public:
	TCP_Serveur(QWidget *parent = Q_NULLPTR);
	char retour;
	char requete;
	int TailleTableau = 0;
	QTcpSocket * ListClient[1000];
	Meteo *meteo;

private:

	//Ui::TCP_ServeurClass ui;
	QTcpServer * server;
	QTcpSocket * socket;
	QTcpSocket * client;
	QString username;
	QString password;
	QSqlQuery db;

public slots:
	void onServerNewConnection();
	void onClientDisconnected();
	void onClientReadyRead();
};