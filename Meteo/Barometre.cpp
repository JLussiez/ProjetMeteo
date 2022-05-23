#include "Barometre.h"

Barometre::Barometre()
{
	Tension = 0;
	NumeroChannel = 2;
	this->ConnectCarte();
}

void Barometre::convertionTensionPression()
{
	Pression = 0.0227*Tension+111;
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