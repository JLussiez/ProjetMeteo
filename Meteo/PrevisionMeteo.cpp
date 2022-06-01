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
		//Temps ensolleillé
		Temps = "Ensoleille";
	} else if ( Pression <= 1015 && Pression > 1000)
	{
		if (Pluie == 1)
		{
			//Formation de neige vers -5 et 1 °C
			if (Temperature > -5 && Temperature < 1)
			{
				//Neige
				Temps = "Neige";
			}else if (Temperature < -10)
			{
				//Grèle
				Temps = "Grele";
			}else
			{
				//Pluvieux
				Temps = "Pluvieux";
			}
		}
		else
		{
			Temps = "Ensoleillé";
		}
		
	} else if ( Pression <= 1000 && Pression > 960)
	{
		//Tempête
		//génère des vents dépassent 89 km / h
		Temps = "Tempete";
	}
}

void PrevisionMeteo::Future()
{
	//connexion à la base : 
	QSqlQuery query(db);

	//Si on connait exactement l'état initial
	// + Si on connait exactement les lois d'évolution
	// -> Prévision = parfaite (ca arrivera pas mdr)


	//Reprendre les anciennes prévision météo : 
	//SQL pour prendre depuis BDD

	QString SQLInfoCapteur = "SELECT `Vitesse_Vent`, `Position_Vent`, `Pression`, `Humidite`, `Temperature`, `Solarimetre`,\
 `Pluviometre`, `Pluie`, `JourNuit` FROM `Capteur` ORDER BY `Date` DESC";
	QString SQLPrevision = "SELECT `Prévision` FROM `Prévision Météo` ORDER BY `Date` DESC";
	QSqlQuery queryInfoCapteur;
	QSqlQuery queryPrevision;
	
	//Compare les différentes Prévision

	//Execute les commande SQL
	queryInfoCapteur.exec(SQLInfoCapteur);
	queryPrevision.exec(SQLPrevision);

	//Récuperer les valeurs que l'on veut pour la prévision = la première valeur stocker + la 6
	while (queryInfoCapteur.next())
	{
		for (int i = 0; i < 7; i++)
		{
			qDebug() << "Récuperer Prévision stocker";
			//Récupère le résultat de la requête
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
		//On à récupérer toutes les valeurs nous interressant
		break;
	}
	float FDernierePression = DernierePression.toFloat();
	float FPressionHmoinsUn = PressionHmoinsUn.toFloat();
	//Différence de préssion entre actuelle et H-1
	float DiffPression = FDernierePression - FPressionHmoinsUn;

	//Augmentation 1 mBar le matin et soir

	//Toute les heures : 
	// Monté de 0,25 à 0,5 : Venue d'une haute préssion (sur long terme) = 1015 hPa = beau temps
	// Monté de 1 à 2 : Venue d'une moyenne pression (sur court terme) = Beau Temps
	// Descente 0,25 à 0,5 : Venue d'une basse pression (sur long terme) = 1010 hPa = risque de pluie, ciel nuageux
	// Descente 1 à 2 : tempête (été = orage)

	if (DiffPression >= 0,25 && DiffPression <= 0,5)
	{
		//Beau temps sur le long terme en prévision
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
		//Risque de pluie, ciel nuageux sur le long terme en prévision
		Prevision = "Risque de pluie";
		Duree = "Long terme";
	}
	else if (DiffPression <= -1 && DiffPression >= -2)
	{
		//Tempête, si on est en été : orage
		//Voir si on est en été :
		time_t ttime = time(0);

		char* dt = ctime(&ttime);
		QString jour = dt[0];
		QString mois = dt[1];

		if (mois == "JUL" || mois == "AUG")
		{
			//été
			Prevision = "Orage";
		} else if (mois == "JUN")
		{
			//vérifier date
			if (jour >= 21)
			{
				//été
				Prevision = "Orage";
			}
		} else if (mois == "SEP")
		{
			//Vérifier date
			if (jour < 23)
			{
				//été
				Prevision = "Orage";
			}
		} else
		{
			Prevision = "Tempête";
		}
	}

	qDebug() << "Prevision : " << Prevision;
	qDebug() << "Durée : " << Duree;
	//Envoie prévision en base

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