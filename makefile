#INC_DIR = include

all: hw7

hw7: mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o node.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o
ifeq (${OS}, Windows_NT)
	g++ -o hw7 mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o node.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o -lgtest
else
	g++ -o hw7 mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o node.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o -lgtest -lpthread
endif

mainTerm.o: mainTerm.cpp utTerm.h
	g++ -std=gnu++0x -c mainTerm.cpp 

term.o: term.h term.cpp
	g++ -std=gnu++0x -c term.cpp
atom.o: atom.h atom.cpp
	g++ -std=gnu++0x -c atom.cpp
variable.o: variable.h variable.cpp
	g++ -std=gnu++0x -c variable.cpp
parser.o : parser.h parser.cpp
	g++ -std=gnu++0x -c parser.cpp
scanner.o : scanner.h scanner.cpp
	g++ -std=gnu++0x -c scanner.cpp
node.o: node.h node.cpp
	g++ -std=gnu++0x -c node.cpp
iterator.o: iterator.h iterator.cpp
	g++ -std=gnu++0x -c iterator.cpp
structIterator.o: structIterator.h structIterator.cpp
	g++ -std=gnu++0x -c structIterator.cpp	
listIterator.o: listIterator.h listIterator.cpp
	g++ -std=gnu++0x -c listIterator.cpp
nullIterator.o: nullIterator.h nullIterator.cpp
	g++ -std=gnu++0x -c nullIterator.cpp
dfsIterator.o: dfsIterator.h dfsIterator.cpp
	g++ -std=gnu++0x -c dfsIterator.cpp
bfsIterator.o: bfsIterator.h bfsIterator.cpp
	g++ -std=gnu++0x -c bfsIterator.cpp
number.o: number.h number.cpp
	g++ -std=gnu++0x -c number.cpp
struct.o: struct.h struct.cpp
	g++ -std=gnu++0x -c struct.cpp
list.o : list.h list.cpp
	g++ -std=gnu++0x -c list.cpp

clean:
	rm -f *.o hw7 mainTerm utStruct utVariable utList utParser utIterator