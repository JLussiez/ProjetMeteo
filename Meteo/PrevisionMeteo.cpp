#include "PrevisionMeteo.h"

void PrevisionMeteo::CatherineLaborde(Barometre& Barometre)
{
	float Pression = Barometre.getPression();

	if (Pression < 960 || Pression > 1060)
	{
		//erreur : impossible
	}
}
