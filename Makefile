all: test_Hamiltonian test_Graph test_Eficiencia main

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

Hamiltonian.o: Hamiltonian.cpp Hamiltonian.h
	g++ -c Hamiltonian.cpp

test_Graph: test_Graph.cpp Graph.o
	g++ -o test_Graph test_Graph.cpp Graph.o

test_Hamiltonian: test_Hamiltonian.cpp Graph.o Hamiltonian.o
	g++ -o test_Hamiltonian test_Hamiltonian.cpp Graph.o Hamiltonian.o

main: main.cpp Graph.o Hamiltonian.o
	g++ -o main main.cpp Graph.o Hamiltonian.o

test_Eficiencia: test_Eficiencia.cpp Graph.o Hamiltonian.o
	g++ -o test_Eficiencia test_Eficiencia.cpp Graph.o Hamiltonian.o

run_test_Hamiltonian:
	./test_Hamiltonian

run_test_Eficiencia:
	./test_Eficiencia

run_test_Graph:
	./test_Graph

run:
	./main

clean:
	rm -f *.o test_Eficiencia test_Hamiltonian test_Graph main *.exe