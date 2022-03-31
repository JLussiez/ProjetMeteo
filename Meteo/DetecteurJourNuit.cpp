#include "DetecteurJourNuit.h"

DetecteurJourNuit::DetecteurJourNuit()
{
	Tension = 0;
	NumeroChannel = 8;
	this->ConnectCarte();
}

void DetecteurJourNuit::convertionTensionJourNuit()
{
}

float DetecteurJourNuit::getJourNuit()
{
	return JourNuit;
}

void DetecteurJourNuit::addJourNuitTest()
{
}
