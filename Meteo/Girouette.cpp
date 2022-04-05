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

QString Girouette::getCardinalite()
{
	return Cardinalite;
}

void Girouette::addCardinaliteTest()
{
}
