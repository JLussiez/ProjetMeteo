#pragma once
#include <QtWidgets/QMainWindow>
#include "Dask.h"

class Capteur:
	public QMainWindow
{
	Q_OBJECT

	public:
		float Tension;
		I16 card;

	public slots:
		Capteur();
		void InitialiseCarte();

};

