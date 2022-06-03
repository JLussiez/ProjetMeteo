#include "Barometre.h"

Barometre::Barometre()
{
	Tension = 0;
	NumeroChannel = 2;
	this->ConnectCarte();
}

void Barometre::convertionTensionPression()
{
	qDebug() << "Tension : " << Tension;
	Pression = 0.533*Tension+938;
	qDebug() << "Pression : " << Pression;
}

float Barometre::getPression()
{
	return this->Pression;
}

void Barometre::addTensionTest()
{
	float TensionTest = QRandomGenerator::global()->bounded(130, 140);
 	Tension = TensionTest / 1000;
}

float Barometre::InstanciationPressionHmoins1()
{
	priseTension();
	convertionTensionPression();
	return Pression;
}

void Barometre::TestConvertionBarometre()
{
	this->convertionTensionPression();
}