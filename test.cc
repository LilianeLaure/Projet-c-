#include <map> 
#include <string> 
#include <iostream> 
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(int argc, char **argv) { 
	ifstream fichier(argv[1], ios::in);  // on ouvre le fichier en lecture
	if(fichier) {
		string line;
		getline(fichier,line);
		if(line.compare("gauche:")==0){
			std::cout<<"gauche"<<std::endl;
			while(getline(fichier,line)&&line.compare("droite:")!=0){
				std::cout<<line<<std::endl;
			}
			getline(fichier,line);
			if(line.compare("droite:")==0){
				std::cout<<"droite"<<std::endl;
			}
		}
	}
			
	
  return 0; 
}
