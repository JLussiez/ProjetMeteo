#pragma once
#include "Capteur.h"
class Anemometre :
	public Capteur
{
public:
	Anemometre();
	//Convertion tension en donnée utilisable :
	void convertionTensionVitesseVent();
	//Obtenir Pression
	float getVitesseVent();
	//Générer une Tension une Test
	void addVitesseVentTest();
	float VitesseVent;
};

