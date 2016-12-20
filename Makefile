FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -std=c++11 -lm
COMPILLER=g++

all: start

start: geometry.o n-tree.o figure.o square.o trapeze.o rectangle.o TStackItem.o TStack.o repo.o main.o
	$(COMPILLER) $(FLAGS) -o oop-lab7 geometry.o n-tree.o figure.o square.o trapeze.o rectangle.o TStackItem.o TStack.o repo.o main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

geometry.o: geometry.cpp
	$(COMPILLER) -c $(FLAGS) geometry.cpp

figure.o: figure.cpp
	$(COMPILLER) -c $(FLAGS) figure.cpp

square.o: square.cpp
	$(COMPILLER) -c $(FLAGS) square.cpp

trapeze.o: trapeze.cpp
	$(COMPILLER) -c $(FLAGS) trapeze.cpp

rectangle.o: rectangle.cpp
	$(COMPILLER) -c $(FLAGS) rectangle.cpp

TStack.o: TStack.cpp
	$(COMPILLER) -c $(FLAGS) TStack.cpp

TStackItem.o: TStackItem.cpp
	$(COMPILLER) -c $(FLAGS) TStackItem.cpp

n-tree.o: n-tree.cpp
	$(COMPILLER) -c $(FLAGS) n-tree.cpp

repo.o: repo.cpp
	$(COMPILLER) -c $(FLAGS) repo.cpp

clear:
	-rm -f *.o *.gch oop-lab7

