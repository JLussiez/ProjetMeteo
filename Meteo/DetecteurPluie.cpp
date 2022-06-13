#include "DetecteurPluie.h"

DetecteurPluie::DetecteurPluie()
{
	Digital = 0;
	NumeroChannelDI = 10;
	this->ConnectCarte();
}

void DetecteurPluie::convertionDigitalePluie()
{
	Pluie = Digital;
	if (Digital = 1)
	{
		QPleut = "Il ne pleut pas";
	}
	else {
		QPleut = "Il pleut";
	}
	
}

float DetecteurPluie::getPluie()
{
	return Pluie;
}

void DetecteurPluie::addPluieTest()
{
	this->Pluie = QRandomGenerator::global()->bounded(0, 2);
}

QString DetecteurPluie::getQPleut()
{
	return QPleut;
}