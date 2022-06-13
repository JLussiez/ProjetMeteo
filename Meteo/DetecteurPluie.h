#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class DetecteurPluie :
	public Capteur,
	public QMainWindow
{
public:
	DetecteurPluie();
	//Convertion Digitale en donnée utilisable :
	void convertionDigitalePluie();
	//Obtenir Pluie
	float getPluie();
	//Générer une valeur Digitale une Test
	void addPluieTest();
	float Pluie;
	//Chaine de caractères Pluie
	QString QPleut;
	//Obtenir la chaîne de caractère Pluie
	QString getQPleut();
};

