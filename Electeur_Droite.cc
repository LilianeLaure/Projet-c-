#include "Electeur_Droite.hh"

Electeur_Droite::Electeur_Droite(Ville ville):
Electeur(ville)
{
parti=1;
}

void Electeur_Droite:: set_vote(int i)
{
	vote_=i;
}
