#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class DetecteurPluie :
	public Capteur,
	public QMainWindow
{
public:
	DetecteurPluie();
	//Convertion tension en donnée utilisable :
	void convertionTensionPluie();
	//Obtenir Pression
	float getPluie();
	//Générer une Tension une Test
	void addPluieTest();
	float Pluie;
	QString QPleut;
	QString getQPleut();
};

