#include "Solarimetre.h"

Solarimetre::Solarimetre()
{
	Tension = 0;
	NumeroChannel = 6;
	this->ConnectCarte();
}

void Solarimetre::convertionTensionLuminosite()
{
	Luminosite = 10*Tension;
}

float Solarimetre::getLuminosite()
{
	return Luminosite;
}

void Solarimetre::addLuminositeTest()
{
	Tension = QRandomGenerator::global()->bounded(0, 10);
}
