#pragma once
#include <QObject>
#include "Barometre.h"

class PrevisionMeteo :
	public QObject
{
	Q_OBJECT

		char Prevision;

public :
	PrevisionMeteo();
	void CatherineLaborde(Barometre& Barometre);
};

