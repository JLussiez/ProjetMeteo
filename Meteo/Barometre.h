#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Barometre :
	public Capteur
{

	public :
		//Convertion tension en donn�e utilisable :
		float convertionTensionPression();
		//Obtenir Pression
		float getPression();
		//G�n�rer un pression
		void addTensionTest();
		//Obtenir Tension
		float getTension();

		private : 
			float Pression;
			float Tension;

	private slots : 
		void TestConvertionBarometre();
};

