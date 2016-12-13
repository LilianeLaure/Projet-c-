#include <map> 
#include <string> 
#include <iostream> 
#include <vector>
#include <cstdlib>
#include <ctime>

int main() { 
	srand(time(NULL));
 /* std::map<std::string,unsigned> map_mois_idx; 
  map_mois_idx["janvier"] = 1; 
  map_mois_idx["février"] = 2; 
  //... 
  std::map<std::string,unsigned>::const_iterator 
    mit (map_mois_idx.begin()), 
    mend(map_mois_idx.end()); 
  for(;mit!=mend;++mit) {
    std::cout << mit->first << '\t' << mit->second << std::endl; 
  }
  
  */
  std::vector<int> v;
  for (int i=0; i<15; ++i)
  {
  	v.push_back(i);
	//std::cout<<v[i]<< " "<<std::endl;
  }
  int j=rand()%15;
  std::cout << j<<std::endl;
  for(int i=j; i<(i+j)%15; i=i++)
  	std::cout<<v[i]<< " "<<std::endl;
  return 0; 
}
