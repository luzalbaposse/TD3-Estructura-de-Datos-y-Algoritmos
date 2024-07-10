/*
Llamamos escalera a  cualquier secuencia ordenada de valores, ya sea en orden ascendente o en orden descendente. El vector [9,3] es una escalera descendente. [5,8,9] es ascendente.

Dado un vector de enteros v de longitud n, queremos ordenarlo en complejidad de peor caso O(N*K), donde k es la cantidad de escaleras que hay.

Entonces, mi logica va a ser:

1. Recorro el vector y encuentro las escaleras
2. Las separo en vectores auxiliares y las ordeno con sort
3. concateno los vectores auxiliares en el vector original

*/
#include <vector>
#include <iostream>

using namespace std;


void ordenar_escaleras(vector<int>& v) {
    if (v.empty()) return;

    vector<vector<int>> escaleras;
    vector<int> escalera;
    escalera.push_back(v[0]);

    for (int i = 1; i < v.size(); ++i) {
        if ((v[i] >= v[i - 1] && escalera.back() <= v[i]) ||
            (v[i] <= v[i - 1] && escalera.back() >= v[i])) {
            escalera.push_back(v[i]);
        } else {
            if (!escalera.empty()) {
                escaleras.push_back(escalera);
                escalera.clear();
            }
            escalera.push_back(v[i]);
        }
    }

    if (!escalera.empty()) {
        escaleras.push_back(escalera);
    }

    for (auto& e : escaleras) { // ordeno cada escalera con sort
        sort(e.begin(), e.end());
    }

    v.clear();
    
    for (const auto& e : escaleras) { // concateno las escaleras ordenadas
        v.insert(v.end(), e.begin(), e.end());
    }
    
    sort(v.begin(), v.end());
}

int main(){
    vector<int> v = {509,800,200,100,500};
    ordenar_escaleras(v);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}


/*
SOLUCIÓN GERVASIO:
#include <iostream>
#include <vector>
#include <list>

// Ejercicio de ordenamiento del segundo parcial del primer semestre de 2023

using namespace std;

list<int> invertir(list<int> & l) {
  list<int> ret;

  auto it = l.begin();
  while (it != l.end()) {
    ret.push_front(*it);
    ++it;
  }
  return ret;
}

list<list<int>> armar_escaleras(vector<int> v) {
  if (v.empty()) {
    return {};
  }

  // Idea:
  //   - cada escalera se agrega a `ret` al momento de completarla
  //     - para la última escalera, esto ocurre tras finalizar el ciclo
  //   - la escalera actual nunca está vacía
  //     - al terminar una escalera porque encontramos un elemento que corta la
  //     - tendencia, se crea inmediatamente una nueva escalera con ese elemento
  //   - las escaleras en ret están ordenadas crecientemente
  //     - si la escalera actual tiene tendencia decreciente, se invierte al
  //     - momento de agregarla a ret.

  list<int> escalera_actual = {v[0]};
  int signo = 0;

  // Elijo usar listas en vez de vectores porque nos permiten hacer `push_back`
  // en O(1), a diferencia de los vectores que pueden tener que redimencionarse
  // cada tanto. Con vectores tendríamos que hacer una de las siguientes:

  //   - Conocer de antemano el tamaño de cada uno, reservarlo de entrada en
  //     O(m) y luego ir seteando cada posición como hacemos en merge_escaleras
  //     (no es posible aquí ya que no sabemos el tamaño de cada escalera, ni la
  //     cantidad de escaleras).
  //
  //   - Apelar a un análisis amortizado, que no es incorrecto pero está fuera
  //     de lo que pedimos en la materia. La idea es que hacer m llamados a
  //     push_back toma O(m), aunque estén distribuídas de forma despareja (con
  //     la mayoría siendo O(1) y una de tamaño lineal al momento de
  //     redimensionar).
  list<list<int>> ret;

  // notar que arrancamos por el segundo elemento!
  unsigned int i = 1;
  while(i < v.size()) {
    int ultimo = escalera_actual.back();

    if (signo == 0) {
      // si signo=0 significa que sólo hay un elemento en la escalera o es una
      // secuencia de elementos iguales al primero, por lo que aún no pudimos
      // determinar la tendencia.
      escalera_actual.push_back(v[i]);

      if (v[i] > ultimo) {
        signo = 1;
      } else if (v[i] < ultimo) {
        signo = -1;
      }
    } else if (signo == 1) {
      if (v[i] >= ultimo) {
        // tendencia creciente y elemento mayor o igual al anterior -> agrego a
        // escalera actual.
        escalera_actual.push_back(v[i]);
      } else {
        // tendencia creciente y elemento menor al anterior -> cierro la
        // escalera y arranco una nueva.
        ret.push_back(escalera_actual);
        escalera_actual = {v[i]};
        signo = 0;
      }
    } else {
      if (v[i] <= ultimo) {
        // tendencia decreciente y elemento menor o igual al anterior -> agrego
        // a escalera actual.
        escalera_actual.push_back(v[i]);
      } else {
        // tendencia decreciente y elemento mayor al anterior -> cierro la
        // escalera actual, la agrego invertida a ret (para que quede creciente)
        // y arranco una nueva.
        ret.push_back(invertir(escalera_actual));

        escalera_actual = {v[i]};
        signo = 0;
      }
    }

    i++;
  }

  // Cierro la última escalera (aquella para la cual no llegamos a ver un
  // elemento "siguiente" que corte la tendencia).
  if (signo == -1) {
    ret.push_back(invertir(escalera_actual));
  } else {
    ret.push_back(escalera_actual);
  }

  // Notar que los llamados a "invertir" no afectan el orden de complejidad.
  // incluso si tuvieramos que invertir todas las escaleras, la cantidad de
  // total de elementos procesados por invertir (sumando todas las iteraciones)
  // sería v.size().
  //
  // Si este razonamiento no les sale, una alternativa es anotar en una
  // estructura auxiliar la tendencia de cada escalera y usar eso para
  // determinar cómo recorrerla después al momento de mergear.

  return ret;
}

// Generalización del "merge" de merge sort, que toma una cantidad arbitraria de
// vectores ordenados crecientemente y los combina de forma ordenada.
//
// IMPORTANTE: A los efectos de este problema, se podrían haber hecho también
// (k-1) llamados a la función merge ya conocida, lo cual seguramante hubiera
// sido más sabio durante un parcial :-)
vector<int> merge_escaleras(list<list<int>> & escaleras) {
  unsigned total = 0;
  for(auto it = escaleras.begin(); it != escaleras.end(); ++it) {
    total += it->size();
  }

  // Notar que inicializamos ret sabiendo ya su tamaño, para no depender de la
  // complejidad amortizada de push_back.
  vector<int> ret = vector<int>(total, 0);
  unsigned int proximo = 0;

  // al final de cada iteración se agrega exactamente un elemento de alguna de
  // las listas y se lo quita. por esto sabemos que ret.size() crece hasta
  // llegar a `total`, y que en cada iteración siempre habrá al menos un
  // elemento para elegir.
  while (proximo < total) {
    // la lista de la cual se obtuvo el mínimo.
    list<int>* l_min = nullptr;

    for(auto it = escaleras.begin(); it != escaleras.end(); ++it) {
      if (!it->empty()) {
        if (l_min == nullptr || it->front() <= l_min->front()) {
          l_min = &(*it);
        }
      }
    }

    ret[proximo] = l_min->front();
    proximo++;
    l_min->pop_front();
  }

  return ret;
}

// Ordena el vector particionandolo en escaleras ordenadas crecientemente y
// luego mergeandolas con una generalización del algoritmo "merge" de mergesort.
//
// Tiene complejidad de peor caso O(n * k), donde n es la cantidad de elementos
// y k es la cantidad de escaleras.
//
// No es óptimo en el peor caso (como sí es mergesort) ya que la cantidad de
// escaleras podría ser O(n), resultando en O(n^2) operaciones.
//
// Ejemplo: { 1, 2, 1, 2, 1, 2}, o en general cuando los valores suben y bajan
// constantemente ~~~> n/2 escaleras.
vector<int> ordenar_escaleras(vector<int> & v) {
  list<list<int>> escaleras = armar_escaleras(v);
  return merge_escaleras(escaleras);
}

*/