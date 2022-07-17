#include "Hamiltonian.h"
#include <time.h>

int main(){
  float p = 1.0 / 30, PP = 0; // Probabilidad de conexión, Probabilidad de conexión promedio
  int N, nodos = 15;       // Número de nodos, Número de iteraciones
  double time, time2;      // Tiempo de ejecución, Tiempo de ejecución promedio
  unsigned t0, t1;       // Tiempo de inicio, Tiempo de fin
  cout << "Numero de iteraciones: " << endl;  // Se pide el número de iteraciones
  cin >> N;              // Se lee el número de iteraciones
  Graph *g = new Graph(nodos, p); // Se inicializa el grafo con 10 nodos y una probabilidad de 0.5
  Hamiltonian *h = new Hamiltonian(g);    // Se inicializa el problema de encontrar el ciclo hamiltoniano del grafo g
  for(int i = 0; i < N; i++){             // Se ejecuta N veces el algoritmo de encontrar el ciclo hamiltoniano 
    g->generate_matrix(nodos, p);       // Se genera la matriz de adyacencia del grafo g
    t0 = clock();                      // Se inicia el tiempo de ejecución
    while(!h->obtener_ciclo()){       // Se ejecuta el algoritmo de encontrar el ciclo hamiltoniano
      p += 1.0 / 30;                 // Se incrementa la probabilidad de conexión
      g->generate_matrix(nodos,p);  // Se genera la matriz de adyacencia del grafo g
      h->set_graph(g);            // Se asigna el grafo g al problema de encontrar el ciclo hamiltoniano
    }
    t1 = clock();                    // Se finaliza el tiempo de ejecución
    time2 = (double(t1 - t0) / CLOCKS_PER_SEC); // Se calcula el tiempo de ejecucion del algoritmo
    time += time2;
    cout << "Iter time " << time2 << "[s]" <<endl;  // Se imprime el tiempo de ejecución de la iteración
    PP += p;  // Acumulador de probabilidad
  }
  cout << "Tiempo promedio: " << time / N << "[s]" << endl; // Se imprime el tiempo promedio de ejecución
  cout << "Probabilidad promedio: " << PP / N << endl;  // Se imprime la probabilidad promedio de conexión
  return 1;
}