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

		QString Prevision;
		QString Duree;
		QString DernierePression;
		QString PressionHmoinsUn;
		QSqlQuery query;
		QSqlDatabase db;

public :
	PrevisionMeteo();
	void CatherineLaborde(Barometre& Barometre, Thermometre& Thermometre, DetecteurPluie& DetecteurPluie);
	void Future();
	//void EnvoieDonnee(Anemometre & Anemometre, Girouette & Girouette, Barometre & Barometre, Hygrometre & Hygrometre, Thermometre & Thermometre, Solarimetre & Solarimetre, Pluviometre & Pluviometre, DetecteurPluie & DetecteurPluie, DetecteurJourNuit & DetecteurJourNuit);
};