#include "Candidat_Droite.hh"
int Candidat_Droite::num_cand=0;

Candidat_Droite::Candidat_Droite(int size,int pb,Simulateur * sim,Program &program):
	Electeur_Droite(Paris),
	taille_program(size),
	pb_(pb)
	{
		num_Candidat=num_cand;
		program_perso=this->get_phrase(program);
		num_cand++;
	}

Candidat_Droite::~Candidat_Droite(){}

vector<string> Candidat_Droite::get_phrase(Program prog){
		vector<string> program;
		program=prog.get_prog_droite();
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
			//std::cout<<chaine_phrase[i]<<std::endl;
		return chaine_phrase;
}

std::ostream& operator<<(std::ostream& out,Candidat_Droite Cdt) 
{ 
	vector<string> prog=Cdt.get_prog();
	for(int i=0;i<(int)prog.size();i++){
		out<< prog[i]<<std::endl;
	} 
	return out; 
} 

vector<string> Candidat_Droite::get_prog(){
	return program_perso;
}

int Candidat_Droite::get_nb_phrases_idiotes(){
	return nb_phrases_idiotes;
}

int Candidat_Droite::get_num_Candidat(){
	return num_Candidat;
}