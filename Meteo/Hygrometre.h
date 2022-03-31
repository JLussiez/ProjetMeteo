#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Hygrometre :
	public Capteur,
	public QMainWindow
{
public:
	Hygrometre();
	//Convertion tension en donnée utilisable :
	void convertionTensionHumidite();
	//Obtenir Pression
	float getHumidite();
	//Générer une Tension une Test
	void addHumiditeTest();
	float Humidite;
};

