#include "DetecteurJourNuit.h"

DetecteurJourNuit::DetecteurJourNuit()
{
	Tension = 0;
	NumeroChannel = 8;
	this->ConnectCarte();
}

void DetecteurJourNuit::convertionTensionJourNuit()
{
	if (Tension > 1) {
		JourNuit = 1;
	}
	else {
		JourNuit = 0;
	}
}

float DetecteurJourNuit::getJourNuit()
{
	return JourNuit;
}

void DetecteurJourNuit::addJourNuitTest()
{
	Tension = QRandomGenerator::global()->bounded(0, 5);
}
