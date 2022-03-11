#pragma once
#include "Capteur.h"

class CapteurPluie :
	public Capteur
{
	Q_OBJECT

	public : 
		bool Pluie;

	public slots:
		void getPluie();
		void ConvertionTensionPluie();
};

