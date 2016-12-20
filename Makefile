CC=g++
CCFLAGS= -Wall -Werror -std=c++0x -g 
LIBFLAGS= 
SRC= main.cc utility.cc Electeur.cc Electeur_Droite.cc Electeur_Gauche.cc Simulateur.cc Candidat_Gauche.cc Candidat_Droite.cc program.cc 
OBJ= $(SRC:.cc=.o)
EXEC=main


all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC)  $^ -o $@  $(LIBFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC)

