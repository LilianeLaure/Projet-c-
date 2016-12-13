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
	//Program::Program(Simulateur&);
	~Program(){};
	vector<string> get_prog();
private :
	std::vector<string> program_;
};
