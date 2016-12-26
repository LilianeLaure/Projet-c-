#pragma once 
#include <iostream>
#include "Simulateur.hh"
#include <map>
#include <list>

class Sondage
{
	public :
		Sondage(Simulateur *sim , float percent);
		~Sondage(); 
		int nombre_villes(); 
		void sonder(Ville ville);
		void vainqueur_sondage(pair<int, size_t> p);
		void vainqueur();
		void run();
		void result_sondage();
	private : 
		int nb_villes;
		vector <Electeur*> vect_electeurs;
		vector <Electeur*> vote_electeurs;
		int sample_; // regarder sample pour les proportions d'habitants dans chaque ville
		int percent_;
		map<int, size_t> resultats;
};


