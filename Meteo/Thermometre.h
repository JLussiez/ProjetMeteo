#pragma once
#include "Capteur.h"
class Thermometre :
	public Capteur
{
public:
	Thermometre();
	//Convertion tension en donn�e utilisable :
	void convertionTensionTemperature();
	//Obtenir Pression
	float getTemperature();
	//G�n�rer une Tension une Test
	void addTemperatureTest();
	float Temperature;
};

