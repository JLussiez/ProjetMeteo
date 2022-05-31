#include "DetecteurPluie.h"

DetecteurPluie::DetecteurPluie()
{
	Tension = 0;
	NumeroChannel = 7;
	this->ConnectCarte();
}

void DetecteurPluie::convertionTensionPluie()
{
	if (Tension > 3) {
		Pluie = 0;
	}
	else {
		Pluie = 1;
	}
}

float DetecteurPluie::getPluie()
{
	return Pluie;
}

void DetecteurPluie::addPluieTest()
{
	Tension = QRandomGenerator::global()->bounded(0, 4);
}
