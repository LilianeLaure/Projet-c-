#include "program.hh"
Program::Program(const char* file){
	ifstream fichier(file, ios::in);  // on ouvre le fichier en lecture
	if(fichier) {
		vector<string> chaineVectorEclate_gauche;
		vector<string> chaineVectorEclate_droite;
		vector<string> chaineVectorEclate_;
		string line;

		getline(fichier,line);
		if(line.compare("gauche:")==0){
			while(getline(fichier,line)&&line.compare("droite:")!=0)
			{
				if(!line.empty()){
	    				vector<string> chaine=split(line,";");
	    				chaineVectorEclate_gauche.push_back(chaine[0]);
	 				chaineVectorEclate_gauche.push_back(chaine[1]);
					chaineVectorEclate_.push_back(chaine[0]);
					chaineVectorEclate_.push_back(chaine[1]);
				}
			}
			program_gauche_=chaineVectorEclate_gauche;
			if(line.compare("droite:")==0){
				while(getline(fichier,line))
				{
					if(!line.empty()){
		    				vector<string> chaine=split(line,";");
		    				chaineVectorEclate_droite.push_back(chaine[0]);
		 				chaineVectorEclate_droite.push_back(chaine[1]);
						chaineVectorEclate_.push_back(chaine[0]);
						chaineVectorEclate_.push_back(chaine[1]);
					}
				}
			program_droite_=chaineVectorEclate_droite;
			}
		}
    	//	std::cout<<"s: "<<chaine[0]<<" "<<chaine[1]<<std::endl;
		
		//for(int i=0;i<(int)chaineVectorEclate_.size();++i)
			//std::cout<<chaineVectorEclate_[i]<<std::endl;
		fichier.close();  // on ferme le fichier
		program_=chaineVectorEclate_;
	}
	else{
	std::cout<<"impossible d'ouvrir le fichier"<<std::endl;
	}
}


vector<string> Program::get_prog_gauche(){
	return program_gauche_;
}

vector<string> Program::get_prog_droite(){
	return program_droite_;
}
