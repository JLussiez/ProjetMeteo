#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Anemometre :
	public Capteur,
	public QMainWindow
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

