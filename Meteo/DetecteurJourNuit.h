#pragma once
#include "Capteur.h"
class DetecteurJourNuit :
	public Capteur
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

