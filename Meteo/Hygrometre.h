#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Hygrometre :
	public Capteur,
	public QMainWindow
{
public:
	Hygrometre();
	//Convertion tension en donn�e utilisable :
	void convertionTensionHumidite();
	//Obtenir Pression
	float getHumidite();
	//G�n�rer une Tension une Test
	void addHumiditeTest();
	float Humidite;
};

