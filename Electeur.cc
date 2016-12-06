#include "Electeur.hh"

int Electeur :: n_=0;

Electeur::Electeur(Ville ville): vote_(-1), ville_(ville), num_(Electeur::n_++){}
Electeur::~Electeur(){}
Ville Electeur :: get_ville()
{
	return ville_;
}
int Electeur:: get_vote()
{
	return vote_;
}		
int Electeur::get_num()
{
	return num_;
}
