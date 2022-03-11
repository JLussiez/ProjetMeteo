#pragma once
#include "Capteur.h"

class Luxmetre :
	public Capteur
{
	Q_OBJECT

	public:
		float Luminosite;

	public slots:
		void getLuminosite();
		void ConvertionTensionLuminosite();
};

