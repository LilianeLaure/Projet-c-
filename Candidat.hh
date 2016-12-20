#pragma once
#include <iostream>
#include "Electeur.hh"
#include "Simulateur.hh"
#include <vector>
#include <string>
#include "program.hh"
#include <cstdlib>
 
class Simulateur;
using namespace std;
class Candidat:public Electeur
{
	private :
		int num_Candidat;
		int resultat;
		int taille_program;
		int pb_;///proba de dire des choses idiotes
		vector<string> program_perso;
		int nb_phrases_idiotes;
		int parti_;//0 si gauche,1 si droite
	public :
		static int num_cand;
		Candidat(int taille_prog,int pb,Simulateur* sim,Program &program);
		~Candidat();
		int get_nb_phrases_idiotes();
		vector<string> get_phrase(Program program_);
		int get_num_Candidat();
		int get_parti();
};


