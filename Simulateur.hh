#pragma once
#include <iostream>
#include "Candidat.hh"
#include <vector>
#include <list>

using namespace std;
class Candidat;
class Simulateur
{
	private :
		int pb_; 
		int pi_;
		std::vector <Candidat> vector_candidats;
		std::list <Electeur> liste_electeurs;
		int nombre_;//nombre electeurs
	public :
		Simulateur(int nombre);
		~Simulateur(){};
		void add_Candidat(Candidat & candidat);
		void run();
		int max_phrases();
		int min_phrases();
		//int get_next_task();
};


