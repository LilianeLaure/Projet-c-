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
	Program prog_general("program.txt");
	Simulateur simu(100,prog_general);//nbre de population
	Candidat a1(2,30,&simu);
	Candidat a2(3,50,&simu);
	Candidat a3(4,70,&simu);
	simu.add_Candidat(a1);
	simu.add_Candidat(a2);
	simu.add_Candidat(a3);
	simu.run();
	return 0;

}
