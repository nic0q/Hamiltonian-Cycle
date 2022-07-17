#include "Hamiltonian.h"

// Constructor de la clase Hamiltonian
// I: grafo
// O: void
Hamiltonian :: Hamiltonian(Graph *g){    
  this->n = g->get_n();
  this->recorrido = new int[n];
  this->visitado = new int[n];
  this->g = g;
}
// Destructor de la clase Hamiltonian
// I: void
// O: void
Hamiltonian :: ~Hamiltonian(){
}
// Busca el camino hamiltoniano
// I: nodo actual, visitados
// O: 1 se encontró ciclo, 0 no se encontró ciclo
int Hamiltonian :: buscar_ciclo(int nodo, int visitados){
  if(visitados == this->n && es_ciclo()){
    return 1;
  }
  for(int i = 0; i < n; i++){
    if(this->g->get_adj()[nodo][i] && !this->visitado[i]){
      this->visitado[i] = 1;
      this->recorrido[visitados] = i;
      if(buscar_ciclo(i,visitados+1)){
        return 1;
      }
      else{
        this->visitado[i] = 0;
      }
    }
  }
  return 0;
}
// Obtiene el ciclo hamiltoniano
// I: void
// O: void
int Hamiltonian :: obtener_ciclo(){
  int inicial = 0;
  for(int i = 0; i < n;i++){
    this->visitado[i] = 0;
    this->recorrido[i] = -1;
  }
  recorrido[0] = inicial;
  visitado[0] = 1;
  if(!buscar_ciclo(inicial,1)){
    cout << "No hay ciclo hamiltoniano" << endl;
    return 0;
  }else{
    cout << "Encontre Ciclo Hamiltoniano " << endl;
    this->recorrer_ciclo();  // Se imprime el ciclo hamiltoniano
    return 1;
  }
}
// Imrpime el recorrido del ciclo hamiltoniano
// I: void
// O: void
void Hamiltonian :: recorrer_ciclo(){
  for(int i = 0; i < this->n; i++){
    cout << this->recorrido[i] << "->";
    if(this->recorrido[i+1] == -1){
      break;
    }
  }
  cout << this->recorrido[0] << endl;
}
void Hamiltonian :: set_graph(Graph* g){
  this->g = g;
}
// Determina si el camino hamiltoniano es un ciclo
// I: void
// O: entero que indica si es ciclo o no 1 | 0
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