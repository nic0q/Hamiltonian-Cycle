#include <iostream>
using namespace std;

// Clase Graph: Clase que abstrae el concept de grafo representandolo mediante
// una matriz de adyacencia, la cual es conectada o no, dependiendo de una probabilidad
// de conección entregada y el número de nodos o dimensión de la matriz.
class Graph{
  public:
    Graph(int n, float p);
    ~Graph();
    int** get_adj();
    float get_p();
    void print();
    int get_n();
    void generate_matrix(int , float);
  private:
    int **adj;
    float p;
    int n;
};
