#pragma once
#include "Capteur.h"
class Girouette :
	public Capteur
{
public:
	Girouette();
	//Convertion tension en donn�e utilisable :
	void convertionTensionCardinalite();
	//Obtenir Pression
	float getCardinalite();
	//G�n�rer une Tension une Test
	void addCardinaliteTest();
	float Cardinalite;
};

