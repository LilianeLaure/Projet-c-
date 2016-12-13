#include "Candidat.hh"
int Candidat::num_cand=0;

Candidat::Candidat(int size,int pb,Simulateur * sim,Program &program):
	Electeur(Paris),
	taille_program(size),
	pb_(pb)
	{
	num_Candidat=num_cand;
	program_perso=this->get_phrase(program);
	num_cand++;
	}

Candidat::~Candidat(){}

vector<string> Candidat::get_phrase(Program prog){
		vector<string> program=prog.get_prog();
		vector<string> chaine_phrase;
		int cpt=0;
		for(int i=0;i<(int)program.size()/2;++i){
			if (cpt<taille_program){ /////si on ne depasse pas la taille du programme perso
    			int random=rand()%100+1;
 				if (random<=pb_){ ////proba que le candidat dise une phrase stupide
 					chaine_phrase.push_back(program[2*i+1]);///idiote
 					nb_phrases_idiotes++;
				}
				else{
					chaine_phrase.push_back(program[2*i]);///pas idiote
				}
			cpt++;
			}
		}
	//	for(int i=0;i<(int)chaine_phrase.size();++i)
		//	std::cout<<chaine_phrase[i]<<std::endl;
		return chaine_phrase;
}

int Candidat::get_nb_phrases_idiotes(){
	return nb_phrases_idiotes;
}

int Candidat::get_num_Candidat(){
	return num_Candidat;
}
