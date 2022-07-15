FLAGS= -O2 -g
all: main

graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

hamiltonian.o: Hamiltonian.cpp Hamiltonian.h
	g++ -c Hamiltonian.cpp

main: hamiltonian.o graph.o
	g++ -o main hamiltonian.o graph.o main.cpp 

run:
	./main

clean:
	rm -f *.o main