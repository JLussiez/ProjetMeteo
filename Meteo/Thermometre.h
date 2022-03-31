#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Thermometre :
	public Capteur,
	public QMainWindow
{
public:
	Thermometre();
	//Convertion tension en donnée utilisable :
	void convertionTensionTemperature();
	//Obtenir Pression
	float getTemperature();
	//Générer une Tension une Test
	void addTemperatureTest();
	float Temperature;
};