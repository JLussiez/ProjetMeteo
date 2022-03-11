#pragma once
#include "Capteur.h"

class Hygrometre :
	public Capteur
{
	Q_OBJECT

	public:
		float Humidite;

	public slots:
		void getHumidite();
		void ConvertionTensionHumidite();
};

