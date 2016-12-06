main: main.o 
	g++ -Wall -g -o main main.o Simulateur.o
    
main.o: main.cc 
	g++ -g -Wall -c main.cc

Simulateur.o: Simulateur.cc
	g++ -g -Wall -c Simulateur.cc
    
clean:
	rm -rf *.o
	
mrproper: clean
	rm -rf *


