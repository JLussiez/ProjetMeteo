#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class DetecteurJourNuit :
	public Capteur,
	public QMainWindow
{
public:
	DetecteurJourNuit();
	//Convertion Digitale en donnée utilisable :
	void convertionDigitaleJourNuit();
	//Obtenir Valeur Jour/Nuit
	float getJourNuit();
	//Générer une valeur digitale Test
	void addJourNuitTest();
	float JourNuit;
	//Chaine de caractères Jour/Nuit
	QString QJournuit;
	//Obtenir la chaîne de caractère Jour/Nuit
	QString getQJournuit();
};

