#pragma once
#include <QtWidgets/QMainWindow>
#include <qdebug.h>
#include <QObject>
#include <QRandomGenerator>

class JourNuit:
	public QMainWindow
{
	public:
		//R�cuperer donn�es
		bool getDIJourNuit();
		void AddValue();

	private:
		bool JourNuit;
};

