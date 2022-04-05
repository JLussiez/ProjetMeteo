#include "DetecteurPluie.h"

DetecteurPluie::DetecteurPluie()
{
	Tension = 0;
	NumeroChannel = 7;
	this->ConnectCarte();
}

void DetecteurPluie::convertionTensionPluie()
{
}

float DetecteurPluie::getPluie()
{
	return Pluie;
}

void DetecteurPluie::addPluieTest()
{
}
