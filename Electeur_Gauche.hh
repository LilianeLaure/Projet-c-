#pragma once
#include <iostream>
#include "Electeur.hh"
 
using namespace std;
class Electeur_Gauche:public Electeur
{
	private :
		int vote_;
	public :
		Electeur_Gauche(Ville);
		~Electeur_Gauche(){};
		void set_vote(int i);
};

