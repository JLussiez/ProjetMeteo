#pragma once
#include "Capteur.h"
class Hygrometre :
	public Capteur
{
public:
	Hygrometre();
	//Convertion tension en donn�e utilisable :
	void convertionTensionHumidite();
	//Obtenir Pression
	float getHumidite();
	//G�n�rer une Tension une Test
	void addHumiditeTest();
	float Humidite;
};

