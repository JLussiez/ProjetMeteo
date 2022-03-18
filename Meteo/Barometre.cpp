#include "Barometre.h"

float Barometre::convertionTensionPression()
{
	this->Tension = 0.134;


	this->Pression = this->Tension * 7686.215303;

	//Envoyer en BDD : 


	return 0;
}

float Barometre::getPression()
{
	return this->Pression;
}
