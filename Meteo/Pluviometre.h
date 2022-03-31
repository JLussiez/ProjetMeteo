#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Pluviometre :
	public Capteur,
	public QMainWindow
{
public:
	Pluviometre();
	//Convertion tension en donnée utilisable :
	void convertionTensionQuantitePluie();
	//Obtenir Pression
	float getQuantitePluie();
	//Générer une Tension une Test
	void addQuantitePluieTest();
	float QuantitePluie;
};

