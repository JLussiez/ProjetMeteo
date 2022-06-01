#include "PrevisionMeteo.h"
#include <QSqlQuery>

PrevisionMeteo::PrevisionMeteo()
{

}

void PrevisionMeteo::CatherineLaborde(Barometre& Barometre, Thermometre& Thermometre, DetecteurPluie& DetecteurPluie)
{
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
		if (Pluie == 1)
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
			Temps = "Ensoleill�";
		}
		
	} else if ( Pression <= 1000 && Pression > 960)
	{
		//Temp�te
		//g�n�re des vents d�passent 89 km / h
		Temps = "Tempete";
	}
}

void PrevisionMeteo::Future()
{
	//connexion � la base : 
	QSqlQuery query(db);

	//Si on connait exactement l'�tat initial
	// + Si on connait exactement les lois d'�volution
	// -> Pr�vision = parfaite (ca arrivera pas mdr)


	//Reprendre les anciennes pr�vision m�t�o : 
	//SQL pour prendre depuis BDD

	QString SQLInfoCapteur = "SELECT `Vitesse_Vent`, `Position_Vent`, `Pression`, `Humidite`, `Temperature`, `Solarimetre`,\
 `Pluviometre`, `Pluie`, `JourNuit` FROM `Capteur` ORDER BY `Date` DESC";
	QString SQLPrevision = "SELECT `Pr�vision` FROM `Pr�vision M�t�o` ORDER BY `Date` DESC";
	QSqlQuery queryInfoCapteur;
	QSqlQuery queryPrevision;
	
	//Compare les diff�rentes Pr�vision

	//Execute les commande SQL
	queryInfoCapteur.exec(SQLInfoCapteur);
	queryPrevision.exec(SQLPrevision);

	//R�cuperer les valeurs que l'on veut pour la pr�vision = la premi�re valeur stocker + la 6
	while (queryInfoCapteur.next())
	{
		for (int i = 0; i < 7; i++)
		{
			qDebug() << "R�cuperer Pr�vision stocker";
			//R�cup�re le r�sultat de la requ�te
			if (i == 0)
			{
				DernierePression = queryInfoCapteur.value(2).toString();
			}
			else if (i == 6)
			{
				PressionHmoinsUn = queryInfoCapteur.value(2).toString();
			}
			query.next();

			QString IDUser = query.value(0).toString();
		}
		//On � r�cup�rer toutes les valeurs nous interressant
		break;
	}
	float FDernierePression = DernierePression.toFloat();
	float FPressionHmoinsUn = PressionHmoinsUn.toFloat();
	//Diff�rence de pr�ssion entre actuelle et H-1
	float DiffPression = FDernierePression - FPressionHmoinsUn;

	//Augmentation 1 mBar le matin et soir

	//Toute les heures : 
	// Mont� de 0,25 � 0,5 : Venue d'une haute pr�ssion (sur long terme) = 1015 hPa = beau temps
	// Mont� de 1 � 2 : Venue d'une moyenne pression (sur court terme) = Beau Temps
	// Descente 0,25 � 0,5 : Venue d'une basse pression (sur long terme) = 1010 hPa = risque de pluie, ciel nuageux
	// Descente 1 � 2 : temp�te (�t� = orage)

	if (DiffPression >= 0,25 && DiffPression <= 0,5)
	{
		//Beau temps sur le long terme en pr�vision
		Prevision = "Beau temps";
		Duree = "Long terme";
	}
	else if (DiffPression >= 1 && DiffPression <= 2)
	{
		//??
		Duree = "Court terme";
	}
	else if (DiffPression <= -0, 25 && DiffPression >= -0, 5)
	{
		//Risque de pluie, ciel nuageux sur le long terme en pr�vision
		Prevision = "Risque de pluie";
		Duree = "Long terme";
	}
	else if (DiffPression <= -1 && DiffPression >= -2)
	{
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
			Prevision = "Temp�te";
		}
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