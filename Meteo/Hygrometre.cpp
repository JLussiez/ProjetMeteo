#include "Hygrometre.h"

Hygrometre::Hygrometre()
{
	Tension = 0;
	NumeroChannel = 4;
	this->ConnectCarte();
}

void Hygrometre::convertionTensionHumidite()
{
	Humidite = 8*Tension+10;
}

float Hygrometre::getHumidite()
{
	return Humidite;
}

void Hygrometre::addHumiditeTest()
{
	Tension = QRandomGenerator::global()->bounded(0, 10);
}
