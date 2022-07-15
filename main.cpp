#include "Hamiltonian.h"

int main(){
  Graph *g = new Graph(15,0.15); // Se inicializa el grafo con 10 nodos y una probabilidad de 0.5
  Hamiltonian *h = new Hamiltonian(g); // Se inicializa el problema de encontrar el camino hamiltoniano del grafo g
  h->obtener_camino(); // Se obtiene el camino hamiltoniano
  h->get_graph()->print(); // Se imprime el grafo g
  return 0;
}