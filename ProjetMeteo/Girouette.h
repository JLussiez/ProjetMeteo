#pragma once
#include "Capteur.h"

class Girouette :
	public Capteur
{
	Q_OBJECT

	public:
		float DirectionVent;

	public slots:
		void getDirectionVent();
		void ConvertionTensionDirectionVent();
};

