#pragma once
#include "Capteur.h"
class Pluviometre :
	public Capteur
{
public:
	Pluviometre();
	//Convertion tension en donn�e utilisable :
	void convertionTensionQuantitePluie();
	//Obtenir Pression
	float getQuantitePluie();
	//G�n�rer une Tension une Test
	void addQuantitePluieTest();
	float QuantitePluie;
};

