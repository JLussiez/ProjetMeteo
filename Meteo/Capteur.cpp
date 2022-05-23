#include "Capteur.h"

Capteur::Capteur()
{
	AI_9111_Config(card, TRIG_INT_PACER, P9111_TRGMOD_SOFT, 0);
}

void Capteur::priseTension()
{
	/*
	if (card >= 0)
	{
		qDebug() << "Ouverture carte OK";


		if (AI_VReadChannel(card, NumeroChannel, AD_B_10_V, &Tension) < 0)
		{
			qDebug() << "Erreur lecture";
		} else
		{
			qDebug() << "Tension : ";
			//Vérifier tension
		}

		//Supprimer la carte 
		//Release_Card(card);
	}
	_getch();
	*/
	
}

int Capteur::ConnectCarte()
{
	//card = Register_Card(PCI_9111DG, 0);

	return 0;
}

float Capteur::getTension()
{
	return Tension;
}