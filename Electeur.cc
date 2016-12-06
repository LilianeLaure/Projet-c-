#include "Electeur.hh"

int Electeur :: n_=0;

Electeur::Electeur(Ville ville): vote_(-1), ville_(ville), num_(Electeur::n_++){}
Electeur::~Electeur(){}
Ville Electeur :: get_ville()
{
	return ville_;
}
void Electeur:: set_vote(int i)
{
	vote_=i;
}		
int Electeur::get_num()
{
	return num_;
}
