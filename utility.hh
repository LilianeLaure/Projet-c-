#pragma once
#include <string>
#include <vector>
#include <list>
#include<iostream>
#include<map>
//#include "Electeur.hh"
using namespace std;

// From a string s and given a set of character s_s considered as seprator,
// returns a vector of string for each substring in s separeted by 
// at least one character in s_s 
std::vector<std::string> split(const std::string& s, const std::string& s_s);

bool compare(std::pair <int, size_t> p, std::pair <int, size_t> q );

void afficher_element1( vector< pair<int, size_t> > v);
void afficher_element2( vector< pair<int, size_t> > v, int nombre);

//vector<Electeur*> convert(list<Electeur*>);
