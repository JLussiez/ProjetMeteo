#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Pluviometre :
	public Capteur,
	public QMainWindow
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

