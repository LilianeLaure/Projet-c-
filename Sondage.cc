#include "Sondage.hh"

Sondage :: Sondage( Simulateur *sim , float percent) : s_( sim ), percent_(percent) 
{
	liste_electors(s.get_liste_electeurs().begin(),s.get_liste_electeurs.end()); 
	//on determine le nombre de villes
	int nb_villes;
	map<string, size_t> compte;
	for(size_t i=0 ; i<mol_.size() ; i++)
	{
		compte[s.get_liste_electeurs()_get_ville()]++;
	}
	nb_villes=compte.size();
	
	//on definit de l'echantillon
	sample_=percent_*s.get_nombre();
	
	//remplir liste_electors
	int j=alea=rand()%sample_+1;
	for(int i=j; i<sample%i+j ; ++i)
	liste_electors=s.get_liste_electeurs();	
}

Sondage::~()
{
	delete *s;
}
/*
list& Sondage :: operator=( const list& other )
{
	copy( &other[0], &other[0]+other.size(), &liste_electors[0]);
	
	return *(this)->liste_electors;
}
*/


void xbarre()
{ 
		
	for(int i = 0 ; i < s.get_liste_electeurs().size() ; ++i)
	{
		vote_candidats[s.get_liste_electeurs()[i]];
	}
	
}
