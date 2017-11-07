#INC_DIR = include

all: hw5

hw5: mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o
ifeq (${OS}, Windows_NT)
	g++ -o hw5 mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o -lgtest
else
	g++ -o hw5 mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o -lgtest -lpthread
endif



mainTerm.o: mainTerm.cpp utTerm.h
	g++ -std=gnu++0x -c mainTerm.cpp 
#mainVariable.o: mainVariable.cpp utVariable.h 
#	g++ -std=c++11 -c mainVariable.cpp
#mainStruct.o: mainStruct.cpp utStruct.h
#	g++ -std=gnu++0x -c mainStruct.cpp
#mainList.o: mainList.cpp utList.h
#	g++ -std=gnu++0x -c mainList.cpp
#mainParser.o: mainParser.cpp utParser.h
#	g++ -std=c++11 -c mainParser.cpp

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
parser.o : parser.h parser.cpp
	g++ -std=gnu++0x -c parser.cpp
scanner.o : scanner.h scanner.cpp
	g++ -std=gnu++0x -c scanner.cpp



clean:
	rm -f *.o hw5 mainTerm utStruct utVariable utList utParser