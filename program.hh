#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include "Simulateur.hh"
#include "utility.hh"


using namespace std;
class Simulateur;
class Program
{
public:
	Program(const char* file);
	//Program::Program(Simulateur&);
	~Program(){};
	vector<string> get_prog();
private :
	std::vector<string> program_;
};

vector<string> Program::get_prog(){
	return program_;
}


Program::Program(const char* file){
	ifstream fichier(file, ios::in);  // on ouvre le fichier en lecture
	if(fichier) {
		vector<string> chaineVectorEclate_;
		string line;
		//int i=0;
		while(getline(fichier,line))
		{
		if(!line.empty()){
    		vector<string> chaine=split(line,";");
    		chaineVectorEclate_.push_back(chaine[0]);
 			chaineVectorEclate_.push_back(chaine[1]);
				}
			}
    	//	std::cout<<"s: "<<chaine[0]<<" "<<chaine[1]<<std::endl;
		
		for(int i=0;i<(int)chaineVectorEclate_.size();++i)
			std::cout<<chaineVectorEclate_[i]<<std::endl;
		fichier.close();  // on ferme le fichier
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}

	
