#pragma once
#include <iostream>
#include "Electeur.hh"
 
using namespace std;
class Electeur_Droite:public Electeur
{
	private :
		int vote_;
	public :
		Electeur_Droite(Ville);
		~Electeur_Droite(){};
		void set_vote(int i);
};

/*		du coup mettre set_vote et destructeur d'electeur en virtual */
