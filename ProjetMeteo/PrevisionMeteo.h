#pragma once
#include <QtWidgets/QMainWindow>

class PrevisionMeteo:
	public QMainWindow
{
	Q_OBJECT

	public: 
		QString Prevision;

	public slots:
		void NouvellePrevision();

};

