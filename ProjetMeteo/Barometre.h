#pragma once
#include "Capteur.h"

class Barometre :
	public Capteur
{
	Q_OBJECT

	public:
		float Pression;

	public slots:
		void getPression();
		void ConvertionTensionPression();

};

