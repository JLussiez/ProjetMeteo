#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class DetecteurJourNuit :
	public Capteur,
	public QMainWindow
{
public:
	DetecteurJourNuit();
	//Convertion tension en donnée utilisable :
	void convertionTensionJourNuit();
	//Obtenir Pression
	float getJourNuit();
	//Générer une Tension une Test
	void addJourNuitTest();
	float JourNuit;

};

