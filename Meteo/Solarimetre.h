#pragma once
#include "Capteur.h"
class Solarimetre :
	public Capteur
{
public:
	Solarimetre();
	//Convertion tension en donn�e utilisable :
	void convertionTensionLuminosite();
	//Obtenir Pression
	float getLuminosite();
	//G�n�rer une Tension une Test
	void addLuminositeTest();
	float Luminosite;
};

