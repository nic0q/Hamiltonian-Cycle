#include "Hamiltonian.h"

// Constructor de la clase Hamiltonian
// I: grafo
// O: void
Hamiltonian :: Hamiltonian(Graph *g){
  this->n = g->get_n();
  this->visitado = new int[n];
  this->recorrido = new int[n];
  this->g = g;
}
// Destructor de la clase Hamiltonian
// I: void
// O: void
Hamiltonian :: ~Hamiltonian(){
}
// Obtiene el camino hamiltoniano
int Hamiltonian :: buscar_camino(int nodo, int visitados){
  if(visitados == this->n && es_ciclo()){
    cout << "Encontre Ciclo Hamiltoniano ";
    this->recorer_camino();  // Se imprime el camino hamiltoniano
    return 1;
  }
  for(int i = 0; i < n; i++){
    if(this->g->get_adj()[nodo][i] && !this->visitado[i]){
      this->visitado[i] = 1;
      this->recorrido[visitados] = i;
      if(buscar_camino(i,visitados+1)){
        return 1;
      }
      else{
        this->visitado[i] = 0;
      }
    }
  }
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
  for(int i = 0; i < this->n; i++){
    cout << this->recorrido[i] << "->";
    if(this->recorrido[i+1] == -1){
      cout << 0 << endl;
      break;
    }
  }
}
int Hamiltonian :: es_ciclo(){
  int inicial = this->recorrido[0];
  int final = this->recorrido[this->n-1];
  return this->g->get_adj()[inicial][final];
}
// Obtiene el grafo
// I: void
// O: grafo
Graph *Hamiltonian :: get_graph(){
  return this->g;
}