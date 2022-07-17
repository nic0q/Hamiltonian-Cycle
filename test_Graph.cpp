#include "Graph.h"
main(){
  cout << "Se crea el grafo" << endl;
  Graph *g = new Graph(10,0.5);
  cout << "Es representado mediante una matriz de adyacencia" << endl;
  g->print();
  cout << "El numero de nodos del grafo es: " << g->get_n() << endl;
  cout << "La probabilidad de conectar 2 nodos es " << g->get_p() << endl;
  cout << "El grafo tiene un el valor " << g->get_adj()[0][1] << " entre los nodos 0 y 1" << endl;
  cout << "El grafo tiene un el valor " << g->get_adj()[0][2] << " entre los nodos 0 y 2" << endl;
  cout << "Se genera una nueva matriz de adyacencia" << endl;
  g->generate_matrix(10,0.5);
  g->print();
  g->~Graph();
  cout << "Se destruye el objeto Graph" << endl;
}