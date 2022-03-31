#include "Anemometre.h"

Anemometre::Anemometre()
{
	Tension = 0;
	NumeroChannel = 0;
	this->ConnectCarte();
}

void Anemometre::convertionTensionVitesseVent()
{
}

float Anemometre::getVitesseVent()
{
	return VitesseVent;
}

void Anemometre::addVitesseVentTest()
{
}
