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
		//Temps ensolleillé

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() << "Ensolleillé";

	} else if ( Pression <= 1015 && Pression > 1000)
	{
		//Pluie

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() <<  "Pluvieux";

	} else if ( Pression <= 1000 && Pression > 960)
	{
		//Tempête

		//query.prepare("INSERT INTO `Prevision`(`IDUser`, `Content`) VALUES ('" + IDUser + "' , '" + MSG + "')");
		//query.exec();
		qDebug() << "Tempête";
	}

}
