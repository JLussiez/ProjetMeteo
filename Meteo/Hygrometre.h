#pragma once
#include "Capteur.h"
class Hygrometre :
	public Capteur
{
public:
	Hygrometre();
	//Convertion tension en donnée utilisable :
	void convertionTensionHumidite();
	//Obtenir Pression
	float getHumidite();
	//Générer une Tension une Test
	void addHumiditeTest();
	float Humidite;
};

