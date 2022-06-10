#include "Pluviometre.h"

Pluviometre::Pluviometre()
{
	Digital = 0;
	NumeroChannelDI = 4;
	this->ConnectCarte();
}

void Pluviometre::convertionTensionQuantitePluie()
{
	QuantitePluie = Digital;
}

float Pluviometre::getQuantitePluie()
{
	return QuantitePluie;
}

void Pluviometre::addQuantitePluieTest()
{
}
