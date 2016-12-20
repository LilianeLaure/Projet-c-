#pragma once
#include <iostream>
#include "Electeur.hh"
#include "Simulateur.hh"
#include <vector>
#include <string>
#include "program.hh"
#include <cstdlib>
#include "Electeur_Gauche.hh"

class Simulateur;
using namespace std;
class Candidat_Gauche:public Electeur_Gauche
{
	private :
		int num_Candidat;
		int resultat;
		int taille_program;
		int pb_;///proba de dire des choses idiotes
		vector<string> program_perso;
		int nb_phrases_idiotes;
		//int parti_;//0 si gauche,1 si droite
	public :
		static int num_cand;
		Candidat_Gauche(int taille_prog,int pb,Simulateur* sim,Program &program);
		~Candidat_Gauche();
		int get_nb_phrases_idiotes();
		vector<string> get_phrase(Program program_);
		int get_num_Candidat();
		vector<string> get_prog();
};

std::ostream& operator<<(std::ostream& stream,Candidat_Gauche Cdt); 
