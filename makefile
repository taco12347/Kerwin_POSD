INC_DIR = include



all: hw1



hw1: main.o Media.o Shapes.o Sort.o

ifeq (${OS}, Windows_NT)

	g++ -std=gnu++0x -o hw1 main.o Media.o Shapes.o Sort.o -lgtest

else

	g++ -std=gnu++0x -o hw1 main.o Media.o Shapes.o Sort.o -lgtest -lpthread

endif



main.o: main.cpp utSort.h

	g++ -std=gnu++0x -c main.cpp

Media.o: Media.cpp $(INC_DIR)/Media.h

	g++ -std=gnu++0x -c Media.cpp

Shapes.o: Shapes.cpp $(INC_DIR)/Shapes.h

	g++ -std=gnu++0x -c Shapes.cpp

Sort.o: Sort.cpp $(INC_DIR)/Sort.h

	g++ -std=gnu++0x -c Sort.cpp



clean:

ifeq (${OS}, Windows_NT)

	del *.o *.exe

else

	rm -f *.o hw1

endif