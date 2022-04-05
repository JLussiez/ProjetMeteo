#pragma once
#include <QtSql>
#include <QtSql/QtSql>
#include <qsqldatabase.h>
#include <QObject>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QDebug>
#include "Capteur.h"

#include <QtWidgets/QMainWindow>
class BDD :
	public Capteur,
	public QMainWindow
{

public:

	void Connexionbdd();
	

	void requete(bool JN);

private:
	QSqlDatabase db;
};

