#pragma once
#include <iostream>
#include "Candidat.hh"
#include "Electeur.hh"
#include "program.hh"
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
		Program program_;
	public :
		Simulateur(int nombre,Program prog);
		~Simulateur();
		void add_Candidat(Candidat & candidat);
		void run();
		Program get_program();
		int max_phrases();
		int min_phrases();
		//int get_next_task();
};


