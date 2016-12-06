#pragma once
#include <iostream>
#include "Electeur.hh"
#include <list>

class Candidat:public Electeur
{
	private :
		int num_Candidat;
		int resultat;
		//Program program_; ////programme général
		int pb_;///proba de dire des choses idiotes
		int taille_program;
		vector<string> program_perso;
		int nb_phrases_idiotes;
	public :
		static int num_cand;
		Candidat(int taille_prog,int pb);
		~Candidat();
		int get_nb_phrases_idiotes();
		vector<string> get_phrase_idiote(Program program_);
};

int Candidat::num_cand=0;

Candidat::Candidat(int size,int pb,Simu * sim):
	taille_program(size),
	pb_(pb),
	{
	num_Candidat=num_cand;
	program_perso=get_phrase_idiote(Program (*sim).get_program());
	num_cand++;
	}

Candidat::~Candidat(){}

vector<string> Candidat::get_phrase_idiote(Program prog){
		vector<string> program=prog.get_prog();
		vector<string> chaine_phrase;
		for(int i=0;i<(int)program.size()/2;++i){
    		int random=rand()%100+1;
 			std::cout<<random<<std::endl;
 			if (i<=taille_program){ /////si on ne depasse pas la taille du programme
 				if (random<=pb_){ ////proba que le candidat dise une phrase stupide
 					chaine_phrase.push_back(program[2*i+1]);///idiote
 					nb_phrases_idiotes++;
 				}
 				else{
					chaine_phrase.push_back(program[2*i]);///pas idiote
				}
			}
		}
		for(int i=0;i<(int)chaine_phrase.size();++i)
			std::cout<<chaine_phrase[i]<<std::endl;
		return chaine_phrase;
}

int Candidat::get_nb_phrases_idiotes(){
	return nb_phrases_idiotes;
}
