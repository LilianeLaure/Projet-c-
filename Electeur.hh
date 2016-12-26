#pragma once
#include <iostream>

enum Ville{Paris=0, Lyon=1, Nantes=2};



class Electeur
{
	protected:
		int num_;
		Ville ville_;
		int vote_;
	
	public: 
		static int n_;
		Electeur(Ville);
		virtual ~Electeur();
		Ville get_ville();
		virtual void set_vote(int i)=0;
		int get_num();
		int parti; //0 pour gauche ; 1 pour droite
		int get_vote();
		
};
bool minim(Electeur &e1,  Electeur &e2);
bool maxim(Electeur &e1,  Electeur &e2);
