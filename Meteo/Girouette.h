#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Girouette :
	public Capteur,
	public QMainWindow
{
public:
	Girouette();
	//Convertion tension en donnée utilisable :
	void convertionTensionCardinalite();
	//Obtenir Pression
	QString getCardinalite();
	//Générer une Tension une Test
	void addCardinaliteTest();
	QString Cardinalite;
};

