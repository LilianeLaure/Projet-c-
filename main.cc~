#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include "Candidat.hh"
#include "Electeur.hh"
#include "Simulateur.hh"
#include <ctime>
#include "math.h"
#include <cstdlib> 
using namespace std;

int main(){
	int n,taille,pb;
	cout<<"Combien de candidats voulez-vous? ";
	cin>>n;
	Program prog_general("program.txt");
	Simulateur simu(100);//nbre de population
	string tab="";
	for (int i=0;i<n;i++){
		tab="";
		std::cout<<std::endl;
		cout << "taille max du programme du candidat n° "<<i+1<<"?"<<std::endl;
		cin>>taille;
		cout << "probabilité en pourcentage du candidat n° "<<i+1<< " de dire des phrases idiotes ?"<<std::endl;
		cin>>pb;
		tab+="a"+to_string(i);
		std::cout << "PROGRAMME du candidat n° "<< i+1<<std::endl;
		std::cout<<"-----------------------------"<<std::endl;		
		Candidat tab(taille,pb,&simu,prog_general);
		simu.add_Candidat(tab);
		std::cout<<"-----------------------------"<<std::endl;
	}			
	simu.run();
	return 0;

}
