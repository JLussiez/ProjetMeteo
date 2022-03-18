#include "Barometre.h"

float Barometre::convertionTensionPression()
{
	//this->Tension = 0.134;


	this->Pression = this->Tension * 7686.215303;

	//Envoyer en BDD : 


	return 0;
}

float Barometre::getPression()
{
	return this->Pression;
}

void Barometre::addTensionTest()
{
	float TensionRandom = QRandomGenerator::global()->bounded(130, 140);
	this->Tension = TensionRandom / 1000;
}

float Barometre::getTension()
{
	return this->Tension;
}

void Barometre::TestConvertionBarometre()
{
	this->convertionTensionPression();

	//Affichage de la tension dans le label

}