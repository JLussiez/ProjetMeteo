#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Girouette :
	public Capteur,
	public QMainWindow
{
public:
	Girouette();
	//Convertion tension en donn�e utilisable :
	void convertionTensionCardinalite();
	//Obtenir Pression
	QString getCardinalite();
	//G�n�rer une Tension une Test
	void addCardinaliteTest();
	QString Cardinalite;
};

