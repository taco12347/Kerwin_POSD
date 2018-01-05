#INC_DIR = include

all: hw8 shell

hw8: mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o exp.o conjExp.o matchExp.o disjExp.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o exp.o conjExp.o matchExp.o disjExp.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o -lgtest
else
	g++ -o hw8 mainTerm.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o exp.o conjExp.o matchExp.o disjExp.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o -lgtest -lpthread
endif

shell: shell.cpp term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o exp.o conjExp.o matchExp.o disjExp.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o
ifeq (${OS}, Windows_NT)
	g++ -c -std=gnu++0x shell.cpp
	g++ -o shell shell.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o exp.o conjExp.o matchExp.o disjExp.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o -lgtest
else
	g++ -c -std=gnu++0x shell.cpp
	g++ -o shell shell.o term.o atom.o variable.o number.o struct.o list.o parser.o scanner.o exp.o conjExp.o matchExp.o disjExp.o iterator.o structIterator.o listIterator.o nullIterator.o dfsIterator.o bfsIterator.o -lgtest -lpthread
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
exp.o: exp.h exp.cpp
	g++ -std=gnu++0x -c exp.cpp
conjExp.o: conjExp.h conjExp.cpp
	g++ -std=gnu++0x -c conjExp.cpp
matchExp.o: matchExp.h matchExp.cpp
	g++ -std=gnu++0x -c matchExp.cpp
disjExp.o: disjExp.h disjExp.cpp
	g++ -std=gnu++0x -c disjExp.cpp
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
	rm -f *.o hw8 shell mainTerm utStruct utVariable utList utParser utIterator