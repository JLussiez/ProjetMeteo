#include "Capteur.h"

Capteur::Capteur()
{
	//ui.setupUi(this);
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
			//Si on lit la valeur du baromètre : 
			if (NumeroChannel == 2)
			{
				Tension = Tension * 1000;
				qDebug() << "Tension : " << Tension << " mV";
			}
			else
			{
				qDebug() << "Tension : " << Tension << " V";
			}
			//Vérifier tension


		}

		//Supprimer la carte 
		Release_Card(card);
	}
	_getch();
}

void Capteur::priseDigital()
{
	ConnectCarte();
	if (card >= 0)
	{
		if (DI_ReadLine(card, P9111_CHANNEL_DI, NumeroChannelDI, &Digital) < 0)
			qDebug() << "Erreur lecture Channel Digital";
		else
		{
			qDebug() << "Valeur Digital" << Digital;
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

bool Capteur::getDigital()
{
	return Digital;
}

float Capteur::getTension()
{
	return Tension;
}