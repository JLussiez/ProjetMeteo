#include "JourNuit.h"

bool JourNuit::getDIJourNuit()
{
	return this->JourNuit;
}

//G�n�re valeur al�atoire entre 1 et 0
void JourNuit::AddValue()
{
	this->JourNuit = QRandomGenerator::global()->bounded(0, 2);
}
