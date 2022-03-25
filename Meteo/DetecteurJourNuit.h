#pragma once
#include "Capteur.h"
class DetecteurJourNuit :
	public Capteur
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

