#include "Sondage.hh"


Sondage :: Sondage(Simulateur *sim , float percent) : 
	nb_villes(0), sample_(0), percent_(percent/100)
{
	for(auto const & it : sim->get_liste_electeurs() )
		vect_electeurs.push_back(it);
	nb_villes=nombre_villes();
	sample_=percent_ * vect_electeurs.size()/nb_villes;
}

Sondage::~Sondage(){}

//calcul du nombre de villes, pour la fin du code quand on aura plus de villes
int Sondage::nombre_villes(){ 
	map<Ville, size_t> compte;
	for(size_t i=0 ; i < vect_electeurs.size() ; i++)
		compte[vect_electeurs[i]->get_ville()]++;
	return compte.size();
}

void Sondage::sonder(Ville ville){
	//il faut que le nombre d'electeurs soit suffisamment grand pour que sample ne soit pas égale à 0
	size_t k=rand()%vect_electeurs.size()+1;
	size_t temp=k;
	//boucle circulaire de k à k-1 qui prend les sample 1ers electeurs d'une premiere ville (à partir de l'indice k) 
	//et les met dans le vecteur vote_electeurs
	for(size_t j=k; k<sample_+temp; j=(j+1)%vect_electeurs.size()){
		if(vect_electeurs[j]->get_ville()==ville){
			vote_electeurs.push_back(vect_electeurs[j]);
			}
		++k;
	}
}

void Sondage::result_sondage(){
	//on cree une map des votes
	map<int, size_t> resultats;
	for(size_t i=0 ; i < vote_electeurs.size() ; i++)
		resultats[vote_electeurs[i]->get_vote()]++;		
	//on prend le vainqueur du sondage - la methode compare est au debut du code et hors de la classe
	pair<int, size_t> max = (*std::max_element(resultats.begin(), resultats.end(), compare));
	//on rajoute le vainqueur dans la map vote
	vainqueur_sondage(max);
	vote_electeurs.clear();
	resultats.clear();
}

//on est dans vote_candidat
// si le candidat a deja gagne un sondage (on repete 100 fois le sondage), alors on rajoute +1
// on fait quand meme un test d'abord avec find
void Sondage::vainqueur_sondage(pair<int, size_t> p){
	std::map<int,size_t>::iterator it;
	it=resultats.find(p.first);
	if( it==resultats.end() )
		resultats[p.first]=1;
	else 
		resultats[p.first]=p.second+1;
} 

//on rajoute les electeurs de chaque ville
// et on prend les votes
void Sondage::vainqueur(){
	for(int i=0; i<nb_villes; ++i){
	 	sonder( (Ville) i);
	}
	result_sondage();
}

// on repete 100 fois l'operation
void Sondage::run(){
	for(int i=0 ; i < 100 ; ++i)
		vainqueur();
//	 vecteur=resultats;
}

