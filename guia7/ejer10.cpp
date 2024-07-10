#include <iostream>
using namespace std;

struct arbol_ternario {
    int valor;
    arbol_ternario* hijo_izquierdo;
    arbol_ternario* hijo_medio;
    arbol_ternario* hijo_derecho;

    arbol_ternario(int v) : valor(v), hijo_izquierdo(nullptr), hijo_medio(nullptr), hijo_derecho(nullptr) {}
};

void multiplicar_por(arbol_ternario* raiz, int k) {
    if (raiz == nullptr) {
        return;
    }

    // Multiplicar el valor del nodo actual por k
    raiz->valor *= k;

    // Recorrer recursivamente los hijos izquierdo, medio y derecho
    multiplicar_por(raiz->hijo_izquierdo, k);
    multiplicar_por(raiz->hijo_medio, k);
    multiplicar_por(raiz->hijo_derecho, k);
}