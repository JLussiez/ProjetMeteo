#pragma once
#include <QObject>
#include "Barometre.h"
#include <QDebug>

class PrevisionMeteo :
	public QObject
{
	Q_OBJECT

		char Prevision;

public :
	PrevisionMeteo();
	void CatherineLaborde(Barometre& Barometre);
};