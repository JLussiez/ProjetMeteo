#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Anemometre :
	public Capteur,
	public QMainWindow
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

