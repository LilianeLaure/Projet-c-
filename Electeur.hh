#pragma once
#include <iostream>

enum Ville{Paris=0, Lyon=1, Nantes=2};

class Electeur
{
	private:
		int num_;
		Ville ville_;
		int vote_;
	public: 
		static int n_;
		Electeur(Ville);
		~Electeur();
		Ville get_ville();
		int get_vote();
		int get_num();
};

