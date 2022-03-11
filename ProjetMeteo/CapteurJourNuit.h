#pragma once
#include "Capteur.h"

class CapteurJourNuit :
	public Capteur
{
	Q_OBJECT

	public:
		bool JourNuit;

	public slots:
		void getJourNuit();
		void ConvertionTensionJourNuit();
};

