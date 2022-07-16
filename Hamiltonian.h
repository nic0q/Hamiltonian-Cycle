#include <iostream>
#include "Graph.h"
using namespace std;

// Clase Hamiltonian: Clase que representa el problema de encontrar
// el camino hamiltoniano de un grafo
class Hamiltonian{
  public:
    Hamiltonian(Graph *);
    ~Hamiltonian();
    void obtener_camino();
    void print();
    Graph *get_graph();
    void recorer_camino();
  private:
    Graph *g;
    int n;
    int *visitado;
    int *recorrido;
    int es_ciclo();
    int buscar_camino(int, int);
};
