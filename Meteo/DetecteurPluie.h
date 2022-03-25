#pragma once
#include "Capteur.h"
class DetecteurPluie :
	public Capteur
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
};

