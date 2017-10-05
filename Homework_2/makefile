hw2: mainTerm.o
	g++ -o hw2 mainTerm.o -lgtest -lpthread
mainTerm.o: mainTerm.cpp atom.h number.h variable.h
	g++ -std=gnu++0x -c mainTerm.cpp 

clean:
	rm -f *.o hw2 utTerm mainTerm