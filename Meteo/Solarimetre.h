#pragma once
#include "Capteur.h"
class Solarimetre :
	public Capteur
{
public:
	Solarimetre();
	//Convertion tension en donnée utilisable :
	void convertionTensionLuminosite();
	//Obtenir Pression
	float getLuminosite();
	//Générer une Tension une Test
	void addLuminositeTest();
	float Luminosite;
};

