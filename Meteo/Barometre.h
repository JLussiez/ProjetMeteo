#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Barometre :
	public Capteur,
	public QMainWindow
{
	public :
		Barometre();
		//Convertion tension en donnée utilisable :
		void convertionTensionPression();
		//Obtenir Pression
		float getPression();
		//Générer une Tension une Test
		void addTensionTest();
		float Pression;

	private slots : 
		//Test avec QT : 
		void TestConvertionBarometre();
};

