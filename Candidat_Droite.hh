#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "program.hh"
#include <cstdlib>
#include "Electeur_Droite.hh"

using namespace std;

class Candidat_Droite:public Electeur_Droite
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
		Candidat_Droite(int taille_prog,int pb,Program &program);
		~Candidat_Droite();
		int get_nb_phrases_idiotes();
		vector<string> get_phrase(Program program_);
		int get_num_Candidat();
		vector<string> get_prog();
};

std::ostream& operator<<(std::ostream& stream,Candidat_Droite Cdt); 
