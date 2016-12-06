#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include "utility.cc"


using namespace std;

class Program
{
public:
	Program(FILE* fichier);
	~Program(){};
	Program get_phrase_idiote(Program program_);
private :
	std::vector<string> program_;
};

Program::Program(FILE * file):{
	ifstream fichier(file, ios::in);  // on ouvre le fichier en lecture
	if(fichier) {
		vector<string> chaineVectorEclate_;
		string line;
		int i=0;
		while(getline(fichier,line))
		{
		if(!line.empty()){
    		vector<string> chaine=split(line,";");
    		chaineVectorEclate_.push_back(chaine[0]);
 			chaineVectorEclate_.push_back(chaine[1]);
				}
			}
    		std::cout<<"s: "<<chaine[0]<<" "<<chaine[1]<<std::endl;
    		
		}
		}
		for(int i=0;i<(int)chaineVectorEclate_.size();++i)
			std::cout<<chaineVectorEclate_[i]<<std::endl;
		fichier.close();  // on ferme le fichier
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}

	
