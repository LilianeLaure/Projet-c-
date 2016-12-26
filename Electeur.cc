#include "Electeur.hh"

int Electeur :: n_=0;

Electeur::Electeur(Ville ville): num_(Electeur::n_++), ville_(ville),vote_(-1){}

Electeur::~Electeur(){}

Ville Electeur :: get_ville(){
	return ville_;
}
		
int Electeur::get_num(){
	return num_;
}

int Electeur::get_vote(){
	return vote_;
}

bool minim(Electeur &e1,  Electeur &e2){
  return e1.get_vote() < e2.get_vote();
}

bool maxim(Electeur &e1,  Electeur &e2){
  return e1.get_vote() > e2.get_vote();
}
