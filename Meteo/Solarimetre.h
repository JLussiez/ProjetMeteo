#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Solarimetre :
	public Capteur,
	public QMainWindow
{
public:
	Solarimetre();
	//Convertion tension en donnée utilisable :
	void convertionTensionLuminosite();
	//Obtenir Pression
	float getLuminosite();
	//Générer une Tension une Test
	void addLuminositeTest();
	float Luminosite;
};

