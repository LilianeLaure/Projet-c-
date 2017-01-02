#pragma once
#include <iostream>
#include "Candidat_Gauche.hh"
#include "Candidat_Droite.hh"
#include <vector>
#include <list>
#include <algorithm>
#include <map>


//attention, etre sure que le candidat vote pour lui-meme!!! //rajout dans candidat
//attention au test, quand 
using namespace std;
class Candidat_Gauche;
class Candidat_Droite;
class Simulateur
{
	private :
		int pb_; 
		int pi_;
		std::vector <Candidat_Droite> vector_candidats_droite;
		std::vector <Candidat_Gauche> vector_candidats_gauche;
		std::list <Electeur*> liste_electeurs;
		int nombre_electeurs_;//nombre electeurs
	public :
		Simulateur(int nombre);
		~Simulateur();
		void add_Candidat_Gauche(Candidat_Gauche & candidat);
		void add_Candidat_Droite(Candidat_Droite & candidat);
		void run();
		int max_phrases_Gauche();
		int max_phrases_Droite();
		int min_phrases_Droite();
		int min_phrases_Gauche();
		list<Electeur*> get_liste_electeurs();
		int get_nombre_candidats();
		int vote_au_hasard_gauche();
		int vote_au_hasard_droite();
		int get_nombre_electeurs();
		vector<Candidat_Gauche> get_candidats_gauche();
		vector<Candidat_Droite> get_candidats_droite();
		void set_candidats_gauche(vector <Candidat_Gauche> vg);
		void set_candidats_droite(vector <Candidat_Droite> vd);
		int get_nombre_villes();
};


