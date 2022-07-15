#include "Hamiltonian.h"

// Constructor de la clase Hamiltonian
// I: grafo
// O: void
Hamiltonian :: Hamiltonian(Graph *g){
  this->matriz = g->get_adj();
  this->visitado = new int[n];
  this->recorrido = new int[n];
  this->n = g->get_n();
  this->g = g;
}
// Destructor de la clase Hamiltonian
// I: void
// O: void
Hamiltonian :: ~Hamiltonian(){
}
void Hamiltonian :: buscar_camino(int nodo, int visitados){
  if(visitados == this->n){
    cout << "Encontre Hamiltoniano" << endl;
    this->recorer_camino();  // Se imprime el camino hamiltoniano
  }
  for(int i = 0; i < n; i++){
    if(this->matriz[nodo][i] && !this->visitado[i]){
      this->visitado[i] = 1;
      this->recorrido[visitados] = i;
      buscar_camino(i,visitados+1);
      this->visitado[i] = 0;
    }
  }  
}
int Hamiltonian :: es_ciclo(){
  return 0;
}
void Hamiltonian :: obtener_camino(){
  int inicial = 0;
  for(int i = 0; i < n;i++){
    this->visitado[i] = 0;
    this->recorrido[i] = -1;
  }
  recorrido[0] = inicial;
  visitado[0] = 1;
  buscar_camino(inicial,1);
}
void Hamiltonian :: recorer_camino(){
  cout << endl;
  for(int i = 0; i < this->n; i++){
    cout << this->recorrido[i] << "->";
    if(this->recorrido[i+1] == -1){
      break;
    }
  }
  cout << endl;
}
// Obtiene el grafo
// I: void
// O: grafo
Graph *Hamiltonian :: get_graph(){
  return this->g;
}