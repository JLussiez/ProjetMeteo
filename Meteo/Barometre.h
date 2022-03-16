#pragma once
#include "Capteur.h"
class Barometre :
	public Capteur
{

public :
	//Convertion tension en donnée utilisable : 
	int convertionTensionPression();
};

