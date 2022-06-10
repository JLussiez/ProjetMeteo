#include "DetecteurPluie.h"

DetecteurPluie::DetecteurPluie()
{
	Digital = 0;
	NumeroChannelDI = 10;
	this->ConnectCarte();
}

void DetecteurPluie::convertionTensionPluie()
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
}

QString DetecteurPluie::getQPleut()
{
	return QPleut;
}