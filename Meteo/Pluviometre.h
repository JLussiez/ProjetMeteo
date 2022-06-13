#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Pluviometre :
	public Capteur,
	public QMainWindow
{
public:
	Pluviometre();
	//Convertion Digitale en donn�e utilisable :
	void convertionTensionQuantitePluie();
	//Obtenir Quantite pluie
	float getQuantitePluie();
	//G�n�rer une valeur Digitale Test
	void addQuantitePluieTest();
	float QuantitePluie;
};

