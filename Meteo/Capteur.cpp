#include "Capteur.h"

Capteur::Capteur()
{

}

float Capteur::getTension()
{
	/*
	if (card >= 0)
	{
		qDebug() << "Ouverture carte OK";

		AI_9111_Config(card, TRIG_INT_PACER, P9111_TRGMOD_SOFT, 0);

		if (AI_VReadChannel(card, NumeroChannel, AD_B_10_V, &Tension) < 0)
		{
			qDebug() << "Erreur lecture";
		} else
		{
			qDebug() << "Tension : ";
		}

		//Supprimer la carte 
		//Release_Card(cardId);
	}

	_getch();
	*/
	return Tension;
}

int Capteur::ConnectCarte()
{
	//card = Register_Card(PCI_9111DG, 0);

	return 0;
}