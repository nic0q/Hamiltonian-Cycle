FLAGS= -O2 -g
all: test_Hamiltonian test_Graph test_Eficiencia main

graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

hamiltonian.o: Hamiltonian.cpp Hamiltonian.h
	g++ -c Hamiltonian.cpp

test_Graph: test_Graph.cpp graph.o
	g++ -o test_Graph test_Graph.cpp graph.o

test_Hamiltonian: test_Hamiltonian.cpp graph.o hamiltonian.o
	g++ -o test_Hamiltonian test_Hamiltonian.cpp graph.o hamiltonian.o

main: main.cpp graph.o hamiltonian.o
	g++ -o main main.cpp graph.o hamiltonian.o

test_Eficiencia: test_Eficiencia.cpp graph.o hamiltonian.o
	g++ -o test_Eficiencia test_Eficiencia.cpp graph.o hamiltonian.o

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