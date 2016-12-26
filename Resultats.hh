#pragma once
#include <iostream>
#include "Simulateur.hh"

//inclusion de Sondage pour la fonction compare

//dans utility
//void afficher_element1( vector< pair<int, size_t> > v);
//void afficher_element2( vector< pair<int, size_t> > v);

class Resultats{
	public:
		Resultats(Simulateur *simu);
		~Resultats();
		void resultats_election(string);
		void compter_les_votes();
		bool premier_tour();
		void second_tour();
		void resultats_second_tour();
		void run();
		//void resultats_par_ville(Ville ville);
	private:
		Simulateur *s;
		map<int, size_t> resultats;
		vector< pair<int, size_t> > vecteur;
		
};
