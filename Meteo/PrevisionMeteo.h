#pragma once
#include <QObject>
#include "Barometre.h"
#include <QDebug>

class PrevisionMeteo :
	public QObject
{
	Q_OBJECT

		char Prevision;

public :
	PrevisionMeteo();
	void CatherineLaborde(Barometre& Barometre);
	void Future();
	//void EnvoieDonnee(Anemometre & Anemometre, Girouette & Girouette, Barometre & Barometre, Hygrometre & Hygrometre, Thermometre & Thermometre, Solarimetre & Solarimetre, Pluviometre & Pluviometre, DetecteurPluie & DetecteurPluie, DetecteurJourNuit & DetecteurJourNuit);
};