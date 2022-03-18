#pragma once
#include "Capteur.h"
class Barometre :
	public Capteur
{

public :
	//Convertion tension en donnée utilisable :
	float convertionTensionPression();
	float getPression();

	private : 
		float Pression;
};

