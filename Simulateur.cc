#include <iostream>
#include "Simulateur.hh"

Simulateur::Simulateur(int nombre,Program prog):nombre_(nombre), program_(prog),pi_(15), pb_(40)
{
	for(int i=0 ; i<nombre_ ; ++i)
	{
		int alea=rand()%3;
		Electeur electeur(alea);
		liste_electeurs.push-back(electeur);
	}
}

Simulateur::~Simulateur(){}

Program Simulateur::get_program{
	return program_;
}

void Simulateur::add_candidat(Candidat& candidat)
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
			it->set_vote(min_phrases());		
		}	
		else if(alea<pb_)
		{
			it->set_vote(max_phrases());
		}
		else 
		{
			set_vote(-1);
		}
	}	

}


int Simulateur::max_phrases()
{
	int n=vector_candidats[0].get_num_Candidat();
	int max=vector_candidats[0].get_nb_phrases_idiotes();
	for(auto & it : vector_candidats)
	{
		if( max<it.get_nb_phrases_idiotes() )
		{
			max=it.get_nb_phrases_idiotes();
			n=it.get_num_Candidat();
		}
	return n;
}
}

int Simulateur::min_phrases()
{
	int n=vector_candidats[0].get_num_Candidat();
	int min=vector_candidats[0].get_nb_phrases_idiotes();
	for(auto & it : vector_candidats)
	{
		if( min>it.get_nb_phrases_idiotes() )
		{
			min=it.get_nb_phrases_idiotes();
			n=it.get_num_Candidat();
		}
	return n;
}
}
