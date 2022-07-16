#include <iostream>
using namespace std;

// Clase Graph: Clase que abstrae el concept de grafo representandolo mediante
// una matriz de adyacencia.
class Graph{
  public:
    Graph(int n, float p);
    ~Graph();
    void add_edge(int , int);
    int get_edges();
    int** get_adj();
    float get_p();
    void print();
    int get_n();
  private:
    void generate_matrix(int , float);
    int n;
    float p;
    int **adj;
    int edges;
};
