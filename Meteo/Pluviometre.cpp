#include "Pluviometre.h"

Pluviometre::Pluviometre()
{
	Tension = 0;
	NumeroChannel = 9;
	this->ConnectCarte();
}

void Pluviometre::convertionTensionQuantitePluie()
{
}

float Pluviometre::getQuantitePluie()
{
	return QuantitePluie;
}

void Pluviometre::addQuantitePluieTest()
{
}
