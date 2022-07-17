#include "Hamiltonian.h"
#include <time.h>

int main(){
  float p = 0.5, PP = 0;
  int N = 50, nodos = 300;
  double time, time2;
  unsigned t0, t1;
  cout << "Numero de iteraciones: " << endl;
  cin >> N;
  Graph *g = new Graph(nodos, p); // Se inicializa el grafo con 10 nodos y una probabilidad de 0.5
  Hamiltonian *h = new Hamiltonian(g);    // Se inicializa el problema de encontrar el ciclo hamiltoniano del grafo g
  for(int i = 0; i < N; i++){
    g->generate_matrix(nodos, p);
    t0 = clock();
    while(!h->obtener_ciclo()){
      p += 1.0 / 30;
      g->generate_matrix(nodos,p);
      h->set_graph(g);
    }
    t1 = clock();
    time2 = (double(t1 - t0) / CLOCKS_PER_SEC); // Se calcula el tiempo de ejecucion del algoritmo
    time += time2;
    cout << "Iter time " << time2 << "[s]" <<endl;
    PP += p;  // Acumulador de probabilidad
  }
  cout << "Tiempo promedio: " << time / N << "[s]" << endl;
  cout << "Probabilidad promedio: " << PP / N << endl;
  return 0;
}