#pragma once
#include <iostream>
#include "Electeur.hh"
#include <cstdlib>
 
using namespace std;
class Electeur_Droite:public Electeur
{
	private :
		int vote_;
	public :
		Electeur_Droite(Ville){Electeur electeur(Ville)};
		~Electeur_Droite(){};
		void set_vote(int i);
};

/*		du coup mettre set_vote et destructeur d'electeur en virtual */
