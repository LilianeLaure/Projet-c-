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
		Electeur electeur(ville);
		liste_electeurs.push_back(electeur);
	}
}

//Simulateur::~Simulateur(){}


void Simulateur::add_Candidat(Candidat& candidat)
{
	vector_candidats.push_back(candidat);
}

void Simulateur::run()
{
	double alea=rand()%100;
	for( auto & it : liste_electeurs)
	{
		if(alea<pi_)
		{
			it.set_vote(min_phrases());		
		}	
		else if(alea<pb_)
		{
			it.set_vote(max_phrases());
		}
		else 
		{
			it.set_vote(-1);
		}
	}	

}


int Simulateur::max_phrases()
{
	int n;
	if(!vector_candidats.empty()){
		n=vector_candidats[0].get_num_Candidat();
	}
	else
		n=-1;
	int max=vector_candidats[0].get_nb_phrases_idiotes();
	for(auto & it : vector_candidats)
	{
		if( max<it.get_nb_phrases_idiotes() )
		{
			max=it.get_nb_phrases_idiotes();
			n=it.get_num_Candidat();
		}
	}
	return n;
}

int Simulateur::min_phrases()
{
	int n;
	if(!vector_candidats.empty()){
		n=vector_candidats[0].get_num_Candidat();
	}
	else
		n=-1;
	int min=vector_candidats[0].get_nb_phrases_idiotes();
	for(auto & it : vector_candidats)
	{
		if( min>it.get_nb_phrases_idiotes() )
		{
			min=it.get_nb_phrases_idiotes();
			n=it.get_num_Candidat();
		}
	}
	return n;
}
