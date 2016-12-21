#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utility.hh"


using namespace std;

class Program
{
public:
	Program(const char* file);
	~Program(){};
	vector<string> get_prog_gauche();
	vector<string> get_prog_droite();
private :
	std::vector<string> program_gauche_;
	std::vector<string> program_droite_;
	//std::vector<string> program_;
};
