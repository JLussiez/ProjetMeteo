#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class DetecteurJourNuit :
	public Capteur,
	public QMainWindow
{
public:
	DetecteurJourNuit();
	//Convertion tension en donn�e utilisable :
	void convertionTensionJourNuit();
	//Obtenir Pression
	float getJourNuit();
	//G�n�rer une Tension une Test
	void addJourNuitTest();
	float JourNuit;

};
