#pragma once
#include "Capteur.h"

class Anemometre :
	public Capteur
{
	Q_OBJECT

	public:
		float VitesseVent;

	public slots:
		void getVitesseVent();
		void ConvertionTensionVitesseVent();
};

