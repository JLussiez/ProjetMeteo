#pragma once
#include "Capteur.h"
class Anemometre :
	public Capteur
{
public:
	Anemometre();
	//Convertion tension en donn�e utilisable :
	void convertionTensionVitesseVent();
	//Obtenir Pression
	float getVitesseVent();
	//G�n�rer une Tension une Test
	void addVitesseVentTest();
	float VitesseVent;
};

