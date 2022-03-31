#include "Barometre.h"

Barometre::Barometre()
{
	Tension = 0;
	NumeroChannel = 2;
	this->ConnectCarte();
}

void Barometre::convertionTensionPression()
{
	Pression = Tension * 7686.215303;
}

float Barometre::getPression()
{
	return this->Pression;
}

void Barometre::addTensionTest()
{
	float TensionTest = QRandomGenerator::global()->bounded(130, 140);
 	Tension = TensionTest / 1000;
}

void Barometre::TestConvertionBarometre()
{
	this->convertionTensionPression();
}