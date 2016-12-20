CC=g++
CCFLAGS= -Wall -Werror -std=c++0x -g 
LIBFLAGS= 
SRC= Electeur.cc main.cc Simulateur.cc utility.cc Candidat.cc program.cc 
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
