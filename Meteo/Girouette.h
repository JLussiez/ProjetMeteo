#pragma once
#include "Capteur.h"
class Girouette :
	public Capteur
{
public:
	Girouette();
	//Convertion tension en donnée utilisable :
	void convertionTensionCardinalite();
	//Obtenir Pression
	float getCardinalite();
	//Générer une Tension une Test
	void addCardinaliteTest();
	float Cardinalite;
};

