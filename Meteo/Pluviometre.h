#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Pluviometre :
	public Capteur,
	public QMainWindow
{
public:
	Pluviometre();
	//Convertion Digitale en donnée utilisable :
	void convertionTensionQuantitePluie();
	//Obtenir Quantite pluie
	float getQuantitePluie();
	//Générer une valeur Digitale Test
	void addQuantitePluieTest();
	float QuantitePluie;
};

