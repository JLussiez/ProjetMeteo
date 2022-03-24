#include "Barometre.h"

Barometre::Barometre()
{
}

void Barometre::convertionTensionPression()
{
	//this->Tension = 0.134;


	Pression = Tension * 7686.215303;

	//Envoyer en BDD : 
}

float Barometre::getPression()
{
	return this->Pression;
}

void Barometre::addTensionTest()
{
	float TensionTest = QRandomGenerator::global()->bounded(130, 140);
 	Tension = TensionTest / 1000;
	qDebug() << TensionTest;
	qDebug() << Tension;

}

float Barometre::getTension()
{
	return Tension;
}

void Barometre::TestConvertionBarometre()
{
	this->convertionTensionPression();

	//Affichage de la tension dans le label

}