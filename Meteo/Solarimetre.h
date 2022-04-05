#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Solarimetre :
	public Capteur,
	public QMainWindow
{
public:
	Solarimetre();
	//Convertion tension en donn�e utilisable :
	void convertionTensionLuminosite();
	//Obtenir Pression
	float getLuminosite();
	//G�n�rer une Tension une Test
	void addLuminositeTest();
	float Luminosite;
};

