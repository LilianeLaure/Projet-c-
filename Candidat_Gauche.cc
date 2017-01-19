#include "Candidat_Gauche.hh"
int Candidat_Gauche::num_cand=0;

Candidat_Gauche::Candidat_Gauche(int size,int pb,Program &program,Ville ville):
	Electeur_Gauche(ville),
	taille_program(size),
	pb_(pb)
	{
		num_Candidat=num_cand;
		set_vote(num_Candidat); //il vote pour lui-meme
		program_perso=get_phrase(program);
		num_cand++;
	}

Candidat_Gauche::~Candidat_Gauche(){}

vector<string> Candidat_Gauche::get_phrase(Program prog){
	vector<string> program;
	program=prog.get_prog_gauche();
	vector<string> chaine_phrase;
	int cpt=0;
	int a=1; //pour éviter les répétitions des phrases choisies aléatoirement dans les programmes
	for(cpt=0;cpt<taille_program;++cpt){////on ne depasse pas la taille du programme perso
		a=1;
		int i= rand()%(int)program.size()/2;
		int random=rand()%100+1;
		if (random<=pb_){ ////proba que le candidat dise une phrase stupide
			if(cpt!=0){
				while(a==1){
					a=0;
					for(auto it : chaine_phrase) {
						if((it).compare(program[2*i+1])==0){
							a=1;
						}
					}
					if (a==1 && cpt<(int)program.size()/2){//pas de phrases redondantes sauf si on dépasse la taille du programme
							i=rand()%(int)program.size()/2; //si a=1 on change i
				
					}
					else{
						a=0;
						chaine_phrase.push_back(program[2*i+1]);///idiote
						nb_phrases_idiotes++;
					
					}
				}
			}
			else{
				chaine_phrase.push_back(program[2*i+1]);///idiote
				nb_phrases_idiotes++;
			}
		}
		else{
			if(cpt!=0){
				while(a==1){
					a=0;
					for(auto it : chaine_phrase) {
						if((it).compare(program[2*i])==0){
							a=1;
					
						}
					}
					if (a==1 && cpt<(int)program.size()/2){
							i=rand()%(int)program.size()/2; //si a=1 on change i
					}
					else{
						chaine_phrase.push_back(program[2*i]);///pas idiote
					}
				}
			}
			else{
				chaine_phrase.push_back(program[2*i]);///pas idiote
			}
		}
	}
//	for(int i=0;i<(int)chaine_phrase.size();++i)
		//std::cout<<chaine_phrase[i]<<std::endl;
	return chaine_phrase;
}

std::ostream& operator<<(std::ostream& out,Candidat_Gauche Cdt) 
{ 
	vector<string> prog=Cdt.get_prog();
	for(int i=0;i<(int)prog.size();i++){
		out<< prog[i]<<std::endl;
	} 
	return out; 
} 

vector<string> Candidat_Gauche::get_prog(){
	return program_perso;
}

int Candidat_Gauche::get_nb_phrases_idiotes(){
	return nb_phrases_idiotes;
}

int Candidat_Gauche::get_num_Candidat(){
	return num_Candidat;
}
