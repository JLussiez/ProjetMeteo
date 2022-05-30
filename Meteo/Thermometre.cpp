#include "Thermometre.h"

Thermometre::Thermometre()
{
	Tension = 0;
	NumeroChannel = 3;
	this->ConnectCarte();
}

void Thermometre::convertionTensionTemperature()
{
	Temperature = 7*Tension-35;
}

float Thermometre::getTemperature()
{
	return Temperature;
}

void Thermometre::addTemperatureTest()
{
	Tension = QRandomGenerator::global()->bounded(0, 10);
}
