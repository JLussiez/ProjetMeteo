#pragma once
#include "Capteur.h"
class DetecteurPluie :
	public Capteur
{
public:
	DetecteurPluie();
	//Convertion tension en donn�e utilisable :
	void convertionTensionPluie();
	//Obtenir Pression
	float getPluie();
	//G�n�rer une Tension une Test
	void addPluieTest();
	float Pluie;
};

