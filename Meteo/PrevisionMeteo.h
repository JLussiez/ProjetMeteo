#pragma once
#include <QObject>
#include "Anemometre.h"
#include "Girouette.h"
#include "Barometre.h"
#include "Thermometre.h"
#include "Hygrometre.h"
#include "Solarimetre.h"
#include "Pluviometre.h"
#include "DetecteurJourNuit.h"
#include "DetecteurPluie.h"
#include <QDebug>
#include <QRegExp>
#include <qregularexpression.h>
#include <QByteArray.h> 
#include <QSqlQuery>
#include <string>

class PrevisionMeteo :
	public QObject
{
	Q_OBJECT
private:
		QString Prevision;
		QString Duree;
		QString DernierePression;
		QString PressionHmoinsUn;
		QSqlQuery query;
		QSqlDatabase db;
		QString Temps;

public :
	PrevisionMeteo();
	void CatherineLaborde(Barometre& Barometre, Thermometre& Thermometre, DetecteurPluie& DetecteurPluie);
	void Future();
	QString getPrevision();
	QString getDuree();
	QString getTemps();
	//void EnvoieDonnee(Anemometre & Anemometre, Girouette & Girouette, Barometre & Barometre, Hygrometre & Hygrometre, Thermometre & Thermometre, Solarimetre & Solarimetre, Pluviometre & Pluviometre, DetecteurPluie & DetecteurPluie, DetecteurJourNuit & DetecteurJourNuit);
};