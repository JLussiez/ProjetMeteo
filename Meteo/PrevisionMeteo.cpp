#include "PrevisionMeteo.h"

PrevisionMeteo::PrevisionMeteo()
{
}

void PrevisionMeteo::CatherineLaborde(Barometre& Barometre)
{
	float Pression = Barometre.getPression();

	qDebug() << Pression;

	if (Pression < 960 || Pression > 1060)
	{
		//erreur : impossible

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() <<  "Impossible : Erreur";

	} else if (Pression >= 1015 && Pression < 1060)
	{
		//Temps ensolleill�

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() << "Ensolleill�";

	} else if ( Pression <= 1015 && Pression > 1000)
	{
		//Pluie

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() <<  "Pluvieux";

	} else if ( Pression <= 1000 && Pression > 960)
	{
		//Temp�te

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() << "Temp�te";
	}

}
