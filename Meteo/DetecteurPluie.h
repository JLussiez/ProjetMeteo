#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class DetecteurPluie :
	public Capteur,
	public QMainWindow
{
public:
	DetecteurPluie();
	//Convertion Digitale en donn�e utilisable :
	void convertionDigitalePluie();
	//Obtenir Pluie
	float getPluie();
	//G�n�rer une valeur Digitale une Test
	void addPluieTest();
	float Pluie;
	//Chaine de caract�res Pluie
	QString QPleut;
	//Obtenir la cha�ne de caract�re Pluie
	QString getQPleut();
};

