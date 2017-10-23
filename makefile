#INC_DIR = include

all: hw4

mainTerm.o: mainTerm.cpp utStruct.h utVariable.h utList.h
	g++ -std=gnu++0x -c mainTerm.cpp 

hw4: mainTerm.o term.o atom.o variable.o number.o struct.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 mainTerm.o term.o atom.o variable.o number.o struct.o list.o -lgtest
else
	g++ -o hw4 mainTerm.o term.o atom.o variable.o number.o struct.o list.o -lgtest -lpthread
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
list.o : list.h list.cpp
	g++ -std=gnu++0x -c list.cpp


clean:
	rm -f *.o hw4 mainTerm utStruct utVariable utList