#pragma once
#include "Capteur.h"
class Barometre :
	public Capteur
{

public :
	//Convertion tension en donn�e utilisable :
	float convertionTensionPression();
	float getPression();

	private : 
		float Pression;
};

