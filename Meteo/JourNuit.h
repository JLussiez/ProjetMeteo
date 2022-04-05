#pragma once
#include <QtWidgets/QMainWindow>
#include <qdebug.h>
#include <QObject>
#include <QRandomGenerator>

class JourNuit:
	public QMainWindow
{
	public:
		//Récuperer données
		bool getDIJourNuit();
		void AddValue();

	private:
		bool JourNuit;
};

