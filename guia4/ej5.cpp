#include <iostream>
#include <vector>
using namespace std;

/*
Más a la izquierda. Escribe un algoritmo divide & conquer que determine si un arreglo de tamaño potencia de 2 está más a la izquierda. Se dice que un arreglo está mas a la izquierda si cumple que:
- La suma de los elementos de la primera mitad es mayor o igual a la suma de los elementos de la segunda mitad.
- Ambas mitades del arreglo, a su vez, tambien estan mas a la izquierda

*/

bool mai(vector<int>& v, int izq, int der){
    if(izq == der){
        return 1;
    }
    int mitad = izq + (der - izq) / 2;
    int suma_izq = 0;
    int suma_der = 0;
    for(int i = izq; i <= mitad; i++){
        suma_izq += v[i];
    }
    for(int i = mitad + 1; i <= der; i++){
        suma_der += v[i];
    }
    if(suma_izq < suma_der){
        return 0;
    }
    return mai(v, izq, mitad) && mai(v, mitad + 1, der);
}

int main(){

vector <int> v;
v.push_back(5);
v.push_back(4);
v.push_back(3);
v.push_back(2);
v.push_back(1);

cout << mai(v, 0, v.size() - 1) << endl;
}