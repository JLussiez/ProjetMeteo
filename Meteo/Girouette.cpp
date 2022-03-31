#include "Girouette.h"

Girouette::Girouette()
{
	Tension = 0;
	NumeroChannel = 1;
	this->ConnectCarte();
}

void Girouette::convertionTensionCardinalite()
{
}

float Girouette::getCardinalite()
{
	return Cardinalite;
}

void Girouette::addCardinaliteTest()
{
}
