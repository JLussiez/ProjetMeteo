#pragma once
#include "Capteur.h"
#include <QtWidgets/QMainWindow>

class Barometre :
	public Capteur,
	public QMainWindow
{

	public :
		Barometre();
		//Convertion tension en donn�e utilisable :
		void convertionTensionPression();
		//Obtenir Pression
		float getPression();
		//G�n�rer un pression
		void addTensionTest();
		//Obtenir Tension
		float getTension();
		float Pression;

	private slots : 
		void TestConvertionBarometre();
};

