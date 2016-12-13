#include "program.hh"
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
		
		//for(int i=0;i<(int)chaineVectorEclate_.size();++i)
			//std::cout<<chaineVectorEclate_[i]<<std::endl;
		fichier.close();  // on ferme le fichier
		program_=chaineVectorEclate_;
	}
	else{
	std::cout<<"impossible d'ouvrir le fichier"<<std::endl;
	}
}


vector<string> Program::get_prog(){
	return program_;
}
