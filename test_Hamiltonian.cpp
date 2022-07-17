#include "Hamiltonian.h"

int main(){
  Graph *g = new Graph(10,0.5); // Se inicializa el grafo con 10 nodos y una probabilidad de 0.5
  Hamiltonian *h = new Hamiltonian(g); // Se inicializa el problema de encontrar el ciclo hamiltoniano del grafo g
  cout << "Se crea el grafo" << endl;
  g->print(); // Se imprime el grafo
  cout << "Se intenta encontrar un ciclo Hamiltoniano" << endl;
  h->obtener_ciclo(); // Se obtiene el ciclo hamiltoniano
  h->~Hamiltonian(); // Se destruye el objeto Hamiltonian
  return 0;
}
