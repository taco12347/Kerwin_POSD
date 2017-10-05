#INC_DIR = include

all: hw2

mainTerm.o: mainTerm.cpp utTerm.h
	g++ -std=gnu++0x -c mainTerm.cpp 

hw2: mainTerm.o atom.o variable.o number.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainTerm.o atom.o variable.o number.o -lgtest
else
	g++ -o hw2 mainTerm.o atom.o variable.o number.o -lgtest -lpthread
endif

atom.o: atom.h atom.cpp
	g++ -std=gnu++0x -c atom.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++0x -c variable.cpp
number.o: number.h number.cpp
	g++ -std=gnu++0x -c number.cpp

clean:
	rm -f *.o hw2 utTerm mainTerm