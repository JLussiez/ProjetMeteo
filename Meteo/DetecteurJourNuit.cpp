#include "DetecteurJourNuit.h"

DetecteurJourNuit::DetecteurJourNuit()
{
	Digital = 0;
	NumeroChannelDI = 8;
	this->ConnectCarte();
}

void DetecteurJourNuit::convertionTensionJourNuit()
{
	JourNuit = Digital;
	if (Digital = 1) {
		QJournuit = "Il fait jour";
	}
	else {
		QJournuit = "Il fait nuit";
	}

	
}

float DetecteurJourNuit::getJourNuit()
{
	return JourNuit;
}

void DetecteurJourNuit::addJourNuitTest()
{

}

QString DetecteurJourNuit::getQJournuit()
{
	return QJournuit;
}
