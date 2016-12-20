#include <iostream>
#include "Simulateur.hh"

Simulateur::Simulateur(int nombre):pb_(40),pi_(15),nombre_(nombre)
{
	for(int i=0 ; i<nombre_ ; ++i)
	{
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
		if (i<nombre_/2){
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

void Simulateur::run()
{
	double alea=rand()%100;
	for( auto & it : liste_electeurs)
	{
		if(alea<pi_)
		{
			if(it->parti==0)
				it->set_vote(min_phrases_Gauche());
			else
				it->set_vote(min_phrases_Droite());
		}	
		else if(alea<pb_)
		{
			if(it->parti==0)
				it->set_vote(max_phrases_Gauche());
			else
				it->set_vote(max_phrases_Droite());	
		}
		else 
		{
			it->set_vote(-1);
		}
	}	

}


int Simulateur::max_phrases_Gauche()
{
	int n;
	
	if(!vector_candidats_gauche.empty()){
		n=vector_candidats_gauche[0].get_num_Candidat();
	}
	else
		n=-1;
	int max=vector_candidats_gauche[0].get_nb_phrases_idiotes();
	for(auto & it : vector_candidats_gauche)
	{
		if( max<it.get_nb_phrases_idiotes() )
		{
			max=it.get_nb_phrases_idiotes();
			n=it.get_num_Candidat();
		}
	}
	return n;
}
int Simulateur::max_phrases_Droite()
{
	int n;
	
	if(!vector_candidats_droite.empty()){
		n=vector_candidats_droite[0].get_num_Candidat();
	}
	else
		n=-1;
	int max=vector_candidats_droite[0].get_nb_phrases_idiotes();
	for(auto & it : vector_candidats_droite)
	{
		if( max<it.get_nb_phrases_idiotes() )
		{
			max=it.get_nb_phrases_idiotes();
			n=it.get_num_Candidat();
		}
	}
	return n;
}

int Simulateur::min_phrases_Gauche()
{
	int n;
	if(!vector_candidats_gauche.empty()){
		n=vector_candidats_gauche[0].get_num_Candidat();
	}
	else
		n=-1;
	int min=vector_candidats_gauche[0].get_nb_phrases_idiotes();
	for(auto & it : vector_candidats_gauche)
	{
		if( min>it.get_nb_phrases_idiotes() )
		{
			min=it.get_nb_phrases_idiotes();
			n=it.get_num_Candidat();
		}
	}
	return n;
}

int Simulateur::min_phrases_Droite()
{
	int n;
	if(!vector_candidats_droite.empty()){
		n=vector_candidats_droite[0].get_num_Candidat();
	}
	else
		n=-1;
	int min=vector_candidats_droite[0].get_nb_phrases_idiotes();
	for(auto & it : vector_candidats_droite)
	{
		if( min>it.get_nb_phrases_idiotes() )
		{
			min=it.get_nb_phrases_idiotes();
			n=it.get_num_Candidat();
		}
	}
	return n;
}
