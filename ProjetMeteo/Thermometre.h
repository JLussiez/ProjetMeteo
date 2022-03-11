#pragma once
#include "Capteur.h"

class Thermometre :
	public Capteur
{
	Q_OBJECT

	public:
		float Temperature;

	public slots:
		void getTemperature();
		void ConvertionTensionTemperature();
};

