#include "Hygrometre.h"

Hygrometre::Hygrometre()
{
	Tension = 0;
	NumeroChannel = 4;
	this->ConnectCarte();
}

void Hygrometre::convertionTensionHumidite()
{
	qDebug() << "Tension : " << Tension;
	Humidite = 8*Tension+10;
	qDebug() << "Pression : " << Humidite;
}

float Hygrometre::getHumidite()
{
	return Humidite;
}

void Hygrometre::addHumiditeTest()
{
	Tension = QRandomGenerator::global()->bounded(0, 10);
}
