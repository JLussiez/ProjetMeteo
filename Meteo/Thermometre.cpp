#include "Thermometre.h"

Thermometre::Thermometre()
{
	Tension = 0;
	NumeroChannel = 3;
	this->ConnectCarte();
}

void Thermometre::convertionTensionTemperature()
{
}

float Thermometre::getTemperature()
{
	return Temperature;
}

void Thermometre::addTemperatureTest()
{
}
