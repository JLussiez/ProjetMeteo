#include "Capteur.h"

Capteur::Capteur()
{
	//AI_9111_Config(card, TRIG_INT_PACER, P9111_TRGMOD_SOFT, 0);
}

void Capteur::priseTension()
{
	ConnectCarte();
	if (card >= 0)
	{
		qDebug() << "Ouverture carte OK";

		if (AI_VReadChannel(card, NumeroChannel, AD_B_10_V, &Tension) < 0)
		{
			qDebug() << "Erreur lecture";
		} else
		{
			Tension = Tension * 1000;
			qDebug() << "Tension : " << Tension;
			//Vérifier tension
		}

		//Supprimer la carte 
		Release_Card(card);
	}
	_getch();
}

void Capteur::ConnectCarte()
{
	card = Register_Card(PCI_9111DG, 0);
	if (card >= 0)
	{
		AI_9111_Config(card, TRIG_INT_PACER, P9111_TRGMOD_SOFT, 0);
	}
	else
	{
		qDebug() << "La carte ne c'est pas enregistré";
	}
}

float Capteur::getTension()
{
	return Tension;
}