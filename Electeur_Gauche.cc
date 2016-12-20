#include "Electeur_Gauche.hh"

Electeur_Gauche::Electeur_Gauche(Ville ville):
Electeur(ville)
{
parti=0;
}

void Electeur_Gauche:: set_vote(int i)
{
	vote_=i;
}
