#include "Hygrometre.h"

Hygrometre::Hygrometre()
{
	Tension = 0;
	NumeroChannel = 4;
	this->ConnectCarte();
}

void Hygrometre::convertionTensionHumidite()
{
}

float Hygrometre::getHumidite()
{
	return Humidite;
}

void Hygrometre::addHumiditeTest()
{
}
