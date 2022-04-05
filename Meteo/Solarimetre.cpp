#include "Solarimetre.h"

Solarimetre::Solarimetre()
{
	Tension = 0;
	NumeroChannel = 6;
	this->ConnectCarte();
}

void Solarimetre::convertionTensionLuminosite()
{
}

float Solarimetre::getLuminosite()
{
	return Luminosite;
}

void Solarimetre::addLuminositeTest()
{
}
