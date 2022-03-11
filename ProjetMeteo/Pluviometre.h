#pragma once
#include "Capteur.h"

class Pluviometre :
	public Capteur
{
	Q_OBJECT

	public:
		float NivPluie;

	public slots:
		void getNivPluie();
		void ConvertionTensionNivPluie();
};

