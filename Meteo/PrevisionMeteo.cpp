#include "PrevisionMeteo.h"
#include <QSqlQuery>

PrevisionMeteo::PrevisionMeteo()
{

}

void PrevisionMeteo::CatherineLaborde(Barometre& Barometre, Thermometre& Thermometre, DetecteurPluie& DetecteurPluie)
{
	//R�cup�re les valeurs des barom�tre
	float Pression = Barometre.getPression();
	float Temperature = Thermometre.getTemperature();
	int Pluie = DetecteurPluie.getPluie();

	qDebug() << "CatherineLaborde / Pression" << Pression;
	qDebug() << "CatherineLaborde / Temperature" << Temperature;
	qDebug() << "CatherineLaborde / Pluie" << Pluie;

	if (Pression < 960 || Pression > 1060)
	{
		//erreur : impossible
		Temps = "ERREUR";
	} else if (Pression >= 1015 && Pression < 1060)
	{
		//Temps ensolleill�
		Temps = "Ensoleille";
	} else if ( Pression <= 1015 && Pression > 1000)
	{
		if (Pluie == 0)
		{
			//Formation de neige vers -5 et 1 �C
			if (Temperature > -5 && Temperature < 1)
			{
				//Neige
				Temps = "Neige";
			}else if (Temperature < -10)
			{
				//Gr�le
				Temps = "Grele";
			}else
			{
				//Pluvieux
				Temps = "Pluvieux";
			}
		}
		else
		{
			Temps = "Ensoleille";
		}
	} else if ( Pression <= 1000 && Pression > 960)
	{
		//Temp�te
		//g�n�re des vents d�passent 89 km / h
		//V�rifi� avec An�mom�tre (si on poss�de un anm�om�tre fonctionnel)
		Temps = "Tempete";
	}
	//Envoie en base meteo
}

void PrevisionMeteo::Future(float Pression, float PressionHmoins1)
{
	//connexion � la base : 
	QSqlQuery query(db);

	//Si on connait exactement l'�tat initial
	// + Si on connait exactement les lois d'�volution
	// -> Pr�vision = parfaite (ca arrivera pas mdr)
	
	//Diff�rence de pr�ssion entre actuelle et H-1
	DiffPression = Pression - PressionHmoins1;
	qDebug() << DiffPression;
	//Augmentation 1 mBar le matin et soir

	//Toute les heures : 
	// Mont� de 0,25 � 0,5 : Venue d'une haute pr�ssion (sur long terme) = 1015 hPa = beau temps
	// Mont� de 1 � 2 : Venue d'une moyenne pression (sur court terme) = Beau Temps
	// Descente 0,25 � 0,5 : Venue d'une basse pression (sur long terme) = 1010 hPa = risque de pluie, ciel nuageux
	// Descente 1 � 2 : temp�te (�t� = orage)

	if (DiffPression >= 02)
	{
		//Beau temps sur le long terme en pr�vision
		qDebug() << "DiffPression >= 0,25 && DiffPression <= 0,5";
		Prevision = "Beau temps";
		Duree = "Long terme";
	}
	else if (DiffPression >= 07.5 && DiffPression <= 2)
	{
		qDebug() << "DiffPression >= 1 && DiffPression <= 2";
		Prevision = "Beau temps";
		Duree = "Court terme";
	}
	else if (DiffPression <= -2.7 && DiffPression >= -07.5)
	{
		qDebug() << "DiffPression <= -0,25 && DiffPression >= -0,5";
		//Risque de pluie, ciel nuageux sur le long terme en pr�vision
		Prevision = "Risque de pluie";
		Duree = "Long terme";
	}
	else if (DiffPression <= 02.5 && DiffPression >= -02.7)
	{
		qDebug() << "DiffPression <= 0.25 && DiffPression >= -0.25";
		Prevision = "Beau temps";
		Duree = "";
	} else if (DiffPression <= -7.5)
	{
		qDebug() << "DiffPression <= -1 && DiffPression >= -2";
		//Temp�te, si on est en �t� : orage
		//Voir si on est en �t� :
		time_t ttime = time(0);

		char* dt = ctime(&ttime);
		QString jour = dt[0];
		QString mois = dt[1];

		if (mois == "JUL" || mois == "AUG")
		{
			//�t�
			Prevision = "Orage";
		} else if (mois == "JUN")
		{
			//v�rifier date
			if (jour >= 21)
			{
				//�t�
				Prevision = "Orage";
			}
		} else if (mois == "SEP")
		{
			//V�rifier date
			if (jour < 23)
			{
				//�t�
				Prevision = "Orage";
			}
		} else
		{
			Prevision = "Tempete";
		}
	}else
	{
		Prevision = "ERREUR : logiquement Impossible";
		Duree = "ERREUR : logiquement Impossible";
	}

	qDebug() << "Prevision : " << Prevision;
	qDebug() << "Dur�e : " << Duree;
	//Envoie pr�vision en base

}

QString PrevisionMeteo::getPrevision()
{
	return Prevision;
}

QString PrevisionMeteo::getDuree()
{
	return Duree;
}

QString PrevisionMeteo::getTemps()
{
	return Temps;
}

float PrevisionMeteo::getDiffPression()
{
	return DiffPression;
}

void PrevisionMeteo::TestActuel(float Pression, float Temperature, int Pluie)
{
	qDebug() << "TestActuel / Pression" << Pression;
	qDebug() << "TestActuel / Temperature" << Temperature;
	qDebug() << "TestActuel / Pluie" << Pluie;

	if (Pression < 960 || Pression > 1060)
	{
		//erreur : impossible
		Temps = "ERREUR";
	}
	else if (Pression >= 1015 && Pression < 1060)
	{
		//Temps ensolleill�
		Temps = "Ensoleille";
	}
	else if (Pression <= 1015 && Pression > 1000)
	{
		if (Pluie == 0)
		{
			//Formation de neige vers -5 et 1 �C
			if (Temperature >= -5 && Temperature < 1)
			{
				//Neige
				Temps = "Neige";
			}
			else if (Temperature < -5)
			{
				//Gr�le
				Temps = "Grele";
			}
			else
			{
				//Pluvieux
				Temps = "Pluvieux";
			}
		}
		else
		{
			Temps = "Ensoleille";
		}
	}
	else if (Pression <= 1000 && Pression > 960)
	{
		//Temp�te
		//g�n�re des vents d�passent 89 km / h
		//V�rifi� avec An�mom�tre (si on poss�de un anm�om�tre fonctionnel)
		Temps = "Tempete";
	}
	//Envoie en base meteo
}