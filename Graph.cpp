#include "Graph.h"

// Constructor de la clase Graph
// I: numero de nodos, probabilidad de conexion
// O: void
Graph :: Graph(int n, float p){
  this->n = n;
  this->p = p;
  int** adj = new int*[n];
  for(int i = 0; i < n; i++){
    adj[i] = new int[n];
    for(int j = 0; j < n; j++){
      adj[i][j] = 0;
    }
  }
  this->adj = adj;
  generate_matrix(n,p);
}
// Generación de matriz de adyacencia, asigna al atributo adj
// I: número de nodos, probabilidad de conexión
// O: void
void Graph :: generate_matrix(int n, float p){
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(double(rand())/RAND_MAX < p){
        this->adj[i][j] = 1;
        this->adj[j][i] = 1;
      }
      else{
        this->adj[i][j] = 0;
        this->adj[j][i] = 0;
      }
    }
  }
  this->adj = adj;
}
// Destructor de la clase Graph
// I: void
// O: void
Graph :: ~Graph(){
  for(int i = 0; i < n; i++){
    delete[] adj[i];
  }
  delete[] adj;
}
// Obtiene el número de nodos
// I: void
// O: número de nodos
int Graph :: get_n(){
  return n;
}
// Obtiene la probabilidad de conexión
// I: void
// O: probabilidad de conexión
float Graph :: get_p(){
  return p;
}
// Obtiene la matriz de adyacencia
// I: void
// O: matriz de adyacencia
int** Graph :: get_adj(){
  return adj;
}
// Imprime la matriz de adyacencia
// I: void
// O: void
void Graph :: print(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
}