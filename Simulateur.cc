#include <iostream>
#include "Simulateur.hh"

Simulateur::Simulateur(int nombre):pb_(40),pi_(15),nombre_electeurs_(nombre)
{
	for(int i=0 ; i<nombre_electeurs_ ; ++i){
		int alea=rand()%3;
		Ville ville;
		switch (alea){
			case 0:
				ville=Paris;break;
			case 1:
				ville=Lyon;break;
			default:
				ville=Nantes;break;
			break;
		}
		if (i<nombre_electeurs_/2){
			Electeur_Gauche* electeur=new Electeur_Gauche(ville);
			liste_electeurs.push_back(electeur);
		}
		else{
			Electeur_Droite* electeur=new Electeur_Droite(ville);
			liste_electeurs.push_back(electeur);
		}	
	}
}

Simulateur::~Simulateur(){
	for(list<Electeur*>::iterator it = liste_electeurs.begin();it!=liste_electeurs.end();it++){
		delete (*it);
	}
}

void Simulateur::add_Candidat_Gauche(Candidat_Gauche & candidat)
{
	vector_candidats_gauche.push_back(candidat);
}

void Simulateur::add_Candidat_Droite(Candidat_Droite & candidat)
{
	vector_candidats_droite.push_back(candidat);
}

void Simulateur::run(){
	double alea;
	for( auto & it : liste_electeurs){
		alea=rand()%100;
		cout << "alea = " << alea << endl;
		if(it->get_vote()==-1){ //seulement s'il n'est pas candidat, s'il est candidat, il vote pour lui-meme
			if(alea<pi_){
				if(it->parti==0){
					it->set_vote(min_phrases_Gauche());
					cout << "min_phrases_gauche " << min_phrases_Gauche() << endl;
					}
				else{
					it->set_vote(min_phrases_Droite());
					cout << "min_phrases_droite" << min_phrases_Droite() << endl;
					}
			}	
			else if(alea>pb_){
				if(it->parti==0){
					it->set_vote(max_phrases_Gauche());
					cout << "max_phrases_gauche" << max_phrases_Gauche() << endl;
					}
				else{
					it->set_vote(max_phrases_Droite());	
					cout << "max_phrases_droite " << max_phrases_Droite() << endl;
					}
			}
			else{
					alea=rand()%100+1;
					if(alea<50){
					cout << "j'ai vote au hasard" << endl; 
					it->set_vote( vote_au_hasard() );
					} //on initialisait deja les votes a -1 donc pas de else
					else{
					cout << "je vote blanc" << endl; 
					}
			}
		}//if candidat
		//cout << it->get_vote() << endl;
	}	
}

int Simulateur::max_phrases_Gauche(){
	int n;
	if(vector_candidats_gauche.empty())
		n=-1;
	else if(vector_candidats_gauche.size()==1)
		n=vector_candidats_gauche[0].get_num_Candidat();
	else{
		vector<Candidat_Gauche> :: iterator max = max_element(vector_candidats_gauche.begin(), vector_candidats_gauche.end(), maxim);
		n=max->get_num_Candidat();
	}
	return n;
}

int Simulateur::max_phrases_Droite(){
	int n;
	if(vector_candidats_droite.empty())
		n=-1;
	else if(vector_candidats_droite.size()==1)
		n=vector_candidats_droite[0].get_num_Candidat();
	else{
		vector<Candidat_Droite> :: iterator max = max_element(vector_candidats_droite.begin(), vector_candidats_droite.end(), maxim);
		n=max->get_num_Candidat();
	}
	return n;
}

int Simulateur::min_phrases_Gauche(){
	int n;
	if(vector_candidats_gauche.empty())
		n=-1;
	else if(vector_candidats_gauche.size()==1)
		n=vector_candidats_gauche[0].get_num_Candidat();
	else{
		vector<Candidat_Gauche> :: iterator min = min_element(vector_candidats_gauche.begin(), vector_candidats_gauche.end(), minim);
		n=min->get_num_Candidat();
	}
	return n;
}

int Simulateur::min_phrases_Droite(){
	int n;
	if(vector_candidats_droite.empty())
		n=-1;
	else if(vector_candidats_droite.size()==1)
		n=vector_candidats_droite[0].get_num_Candidat();
	else{
		vector<Candidat_Droite> :: iterator min = min_element(vector_candidats_droite.begin(), vector_candidats_droite.end(), minim);
		n=min->get_num_Candidat();
	}
	return n;
}

list<Electeur*> Simulateur :: get_liste_electeurs(){
	return liste_electeurs;
}

int Simulateur :: get_nombre_candidats(){
	return vector_candidats_droite.size()+vector_candidats_gauche.size();
}

int Simulateur::vote_au_hasard(){
	double alea=rand()%get_nombre_candidats();
	return alea;
}

int Simulateur::get_nombre_electeurs(){
	return nombre_electeurs_;
}

vector<Candidat_Droite> Simulateur::get_candidats_droite(){
	return vector_candidats_droite;
}

vector<Candidat_Gauche> Simulateur::get_candidats_gauche(){
	return vector_candidats_gauche;
}
