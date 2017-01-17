#include <iostream>
#include "Resultats.hh"

Resultats::Resultats(Simulateur *simu):s(simu){}

Resultats::~Resultats(){}

void Resultats::compter_les_votes(){
	for(auto const & it : s->get_liste_electeurs() ){
		resultats[it->get_vote()]++;
	}
}

void Resultats::resultats_election( string chaine){
	map<int, size_t> temp=resultats;
	pair<int, size_t> max;
	while(!temp.empty()){
			max = ( *std::max_element(temp.begin(), temp.end(), compare) );
			vecteur.push_back(max);
			temp.erase(max.first);
	}
	cout << endl;
	cout  << "****** Resultats du " << chaine << " ****** " << endl;
	afficher_element1(vecteur);
	afficher_element2(vecteur, s->get_nombre_electeurs() );
}


//il serait utile de creer une fiche id du candidat, genre, de gauche avec un % de proposition debiles de 60% ..., à voir
bool Resultats::premier_tour(){ //on n'a pas besoin du nb de candidats en fait
	if(!vecteur.empty()){
		if( (float)vecteur[0].second * 100 / s->get_nombre_electeurs() > 50 ){
			if(vecteur[0].first==-1){
				cout << "Les electeurs ne veulent pas de president..." << endl;
				cout << "Il y aura donc un second tour "<<endl;
				return true;
			}
			else{
				cout << "Le nouveau president est le candidat " << vecteur[0].first << " avec " << vecteur[0].second <<  " des voix ." << endl;
				return true;
			}
		}
	}
	return false;
}

void Resultats::second_tour(){
	if( !premier_tour()){
		vector<Candidat_Gauche> temp_g;
		vector<Candidat_Droite> temp_d;
		for(auto & it: s->get_liste_electeurs() ){
			it->set_vote(-1);		
		}
		for(auto & it : s->get_candidats_gauche() ){
			if(it.get_num_Candidat()==vecteur[0].first || it.get_num_Candidat()==vecteur[1].first){
					temp_g.push_back(it);
			}
		}
		for(auto & it : s->get_candidats_droite() ){
			if(it.get_num_Candidat()==vecteur[0].first || it.get_num_Candidat()==vecteur[1].first){
					temp_d.push_back(it);
			}
		}
		s->set_candidats_gauche(temp_g);
		s->set_candidats_droite(temp_d);
		cout<<endl;
	}//if ! premier tour
}

void Resultats::resultats_second_tour(){
	second_tour();
	resultats.clear();
	vecteur.clear();
	s->run();
	compter_les_votes();
	resultats_election( "second tour");
	
	if(!vecteur.empty()){
		if(vecteur[0].first==-1)
			cout << "Les electeurs ne veulent pas de president..." << endl;
		else
			cout << "Le nouveau president est le candidat " << vecteur[0].first << " avec " << vecteur[0].second <<  " des voix ." << endl;
	}
}


void Resultats::run(){
	compter_les_votes();
	resultats_election( "premier tour");
	premier_tour();
	resultats_second_tour();
}

ostream& operator<<(ostream& os, const Resultats& r)  
{  
	string s = "Le candidat " + to_string(r.vecteur[0].first) +" a remporte l'election presidentielle !" ;
	string line="";
	for(size_t i=0; i<s.size()+6; ++i)
		line+="-";
	os << line+"\n"+ "|  " + s+ "  |"+ "\n" +line+"\n";   
   return os;  
}
