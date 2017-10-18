#INC_DIR = include

all: hw3

mainTerm.o: mainTerm.cpp utStruct.h utVariable.h
	g++ -std=gnu++0x -c mainTerm.cpp 

hw3: mainTerm.o term.o atom.o variable.o number.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainTerm.o term.o atom.o variable.o number.o struct.o -lgtest
else
	g++ -o hw3 mainTerm.o term.o atom.o variable.o number.o struct.o -lgtest -lpthread
endif

term.o: term.h term.cpp
	g++ -std=gnu++0x -c term.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++0x -c atom.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++0x -c variable.cpp
number.o: number.h number.cpp
	g++ -std=gnu++0x -c number.cpp
struct.o: struct.h struct.cpp
	g++ -std=gnu++0x -c struct.cpp


clean:
	rm -f *.o hw3 mainTerm utStruct utVariable