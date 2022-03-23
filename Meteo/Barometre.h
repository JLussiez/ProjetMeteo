#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Barometre :
	public Capteur
{

	public :
		//Convertion tension en donnée utilisable :
		float convertionTensionPression();
		//Obtenir Pression
		float getPression();
		//Générer un pression
		void addTensionTest();
		//Obtenir Tension
		float getTension();

		private : 
			float Pression;
			float Tension;

	private slots : 
		void TestConvertionBarometre();
};

