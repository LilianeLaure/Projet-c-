#pragma once
#include <iostream>
#include "Candidat.hh"
#include "Electeur.hh"
#include <vector>
#include <list>

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
		Simulateur(int time_units);
		~Simulateur();
		void add_Candidat(Candidat candidat);
		void run();
		//int get_next_task();
};
