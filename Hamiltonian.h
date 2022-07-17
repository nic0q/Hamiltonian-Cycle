#include <iostream>
#include "Graph.h"
using namespace std;

// Clase Hamiltonian: Clase que representa el problema de encontrar
// el ciclo hamiltoniano de un grafo, su solucion es encontrar el ciclo 
// hamiltoniano del grafo entregado.
class Hamiltonian{
  public:
    Hamiltonian(Graph *);
    ~Hamiltonian();
    int obtener_ciclo();
    void print();
    void set_graph(Graph *);
  private:
    Graph *g;
    int n;
    int *visitado;
    int *recorrido;
    int es_ciclo();
    Graph *get_graph();
    void recorrer_ciclo();
    int buscar_ciclo(int, int);
};
