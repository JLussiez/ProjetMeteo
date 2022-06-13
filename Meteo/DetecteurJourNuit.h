#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class DetecteurJourNuit :
	public Capteur,
	public QMainWindow
{
public:
	DetecteurJourNuit();
	//Convertion Digitale en donn�e utilisable :
	void convertionDigitaleJourNuit();
	//Obtenir Valeur Jour/Nuit
	float getJourNuit();
	//G�n�rer une valeur digitale Test
	void addJourNuitTest();
	float JourNuit;
	//Chaine de caract�res Jour/Nuit
	QString QJournuit;
	//Obtenir la cha�ne de caract�re Jour/Nuit
	QString getQJournuit();
};

