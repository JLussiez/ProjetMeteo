#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Barometre :
	public Capteur,
	public QMainWindow
{

	public :
		//Convertion tension en donnée utilisable :
		float convertionTensionPression();
		float getPression();
		void addTensionTest();
		float getTension();

		private : 
			float Pression;
			float Tension;

	private slots : 
		void TestConvertionBarometre();
};

