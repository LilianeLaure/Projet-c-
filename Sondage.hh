#pragma once 
#include <iostream>
#include "Simulateur.hh"
#include <map>
#include <list>

list& operator=( const list& other );
class Sondage
{
	public : 
		int xbarre();
	
	private : 
		Simulateur s*;
		int sample_; //sample est inferieur a la taille de la population : checker avec get nombre
		int percent_;
		map<int, int> vote_candidats_;
		list liste_electors_;

}
