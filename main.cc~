#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include "Sondage.hh"
#include "Resultats.hh"
#include <cstdlib> 
using namespace std;

int main(){
	srand(time(NULL));
	int n,n1,n2,taille,pb;
	cout<<"Combien de candidats voulez-vous de gauche ? ";
	cin>>n1;
	std::cout<<n1<<endl;
	cout<<"Combien de candidats voulez-vous de droite ? ";
	cin>>n2;
	std::cout<<n2<<endl;
	n=n1+n2;
	Program prog_general("program.txt");
	Simulateur simu(100);//nbre de population
	string tab="";
	for (int i=0;i<n;i++){
		tab="";
		std::cout<<std::endl;
		cout << "taille max du programme du candidat n° "<<i+1<<"?";
		cin>>taille;
		cout<<taille<<endl;
		cout << "probabilité en pourcentage du candidat n° "<<i+1<< " de dire des phrases idiotes ?";
		cin>>pb;
		cout<<pb<<endl;
		tab+="a"+to_string(i);
		std::cout << "PROGRAMME du candidat n° "<< i+1<<std::endl;
		std::cout<<"-----------------------------"<<std::endl;
		if (i<n1){
			//gauche
			Candidat_Gauche tab(taille,pb,prog_general);
			simu.add_Candidat_Gauche(tab);
			cout<<tab;
		}
		else{
			//droite
			Candidat_Droite tab(taille,pb,prog_general);
			simu.add_Candidat_Droite(tab);
			cout<<tab;
		}
		std::cout<<"-----------------------------"<<std::endl;
	}			
	simu.run();
	//Sondage sondage(&simu, 0.18);
	//sondage.run();
	Resultats res(&simu);
	res.run();
	
	return 0;

}
