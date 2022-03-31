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

class PrevisionMeteo :
	public QObject
{
	Q_OBJECT

		char Prevision;

public :
	PrevisionMeteo();
	void CatherineLaborde(Barometre& Barometre);
	void Future();
	void EnvoieDonnee(Anemometre & Anemometre, Girouette & Girouette, Barometre & Barometre, Hygrometre & Hygrometre, Thermometre & Thermometre, Solarimetre & Solarimetre, Pluviometre & Pluviometre, DetecteurPluie & DetecteurPluie, DetecteurJourNuit & DetecteurJourNuit);
};