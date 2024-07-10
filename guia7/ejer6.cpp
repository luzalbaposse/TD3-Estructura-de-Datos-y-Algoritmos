#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <gtest/gtest.h>
#include <string>
using namespace std;

struct arbol_binario {
    int valor;
    arbol_binario* izq;
    arbol_binario* der;
};

/*
voy a tener un arbol q se ve por ej:
        10
       /  \
      5    15
     / \   / \
    2   7 12  20

lo que debería hacer es recorrer desde la raiz, recursivamente los hijos y verificar que el valor de la raiz sea mayor o igual a los hijos

*/
bool verificar_max_heap(const arbol_binario &raiz) {
    
    if (raiz.izq == nullptr && raiz.der == nullptr) return true;

    // solo hijo izq
    if (raiz.izq != nullptr && raiz.der == nullptr) {
    
        if (raiz.izq->valor > raiz.valor) return false;
        return verificar_max_heap(*raiz.izq);
    }

    // solo hijo der
    if (raiz.izq == nullptr && raiz.der != nullptr) {
        if (raiz.der->valor > raiz.valor) return false;
        return verificar_max_heap(*raiz.der);
    }

    // ambos hijos
    if (raiz.izq != nullptr && raiz.der != nullptr) {
        if (raiz.izq->valor > raiz.valor || raiz.der->valor > raiz.valor) return false;
        return verificar_max_heap(*raiz.izq) && verificar_max_heap(*raiz.der);
    }
    return true;
}


void run_tests() {
    // Test 1: Árbol no es max-heap
    arbol_binario nodo7 = {7, nullptr, nullptr};
    arbol_binario nodo5 = {5, nullptr, nullptr};
    arbol_binario nodo15 = {15, nullptr, nullptr};
    arbol_binario nodo10 = {10, &nodo5, &nodo15};
    arbol_binario raiz_ = {20, &nodo10, &nodo7};
    /*
    20
    / \
    10  7
    / \
    5  15

    */
    assert(verificar_max_heap(raiz_) == false);

    // Test 2: Árbol que no es Max-Heap (hijo izquierdo mayor que padre)
    arbol_binario nodo12 = {12, nullptr, nullptr};
    arbol_binario nodo30 = {30, nullptr, nullptr};
    arbol_binario nodo20 = {20, &nodo12, &nodo30};
    /*
    20
    / \
    12  30
    */
    assert(verificar_max_heap(nodo20) == false);

    // Test 3: Árbol que no es Max-Heap (hijo derecho mayor que padre)
    arbol_binario nodo18 = {18, nullptr, nullptr};
    arbol_binario nodo25 = {25, nullptr, nullptr};
    arbol_binario nodo15_2 = {15, &nodo18, &nodo25};
    /*
    18 
    / \
    15  25
    */
    assert(verificar_max_heap(nodo15_2) == false);

    // Test 4: Árbol Max-Heap con un solo hijo
    arbol_binario nodo13 = {13, nullptr, nullptr};
    arbol_binario nodo19 = {19, &nodo13, nullptr};
    /*
    19
    /
    13
    
    */
    assert(verificar_max_heap(nodo19) == true);

    // Test 5: 
    // Test 1: Árbol no es max-heap
    arbol_binario nodo7_ = {7, nullptr, nullptr};
    arbol_binario nodo5_ = {5, nullptr, nullptr};
    arbol_binario nodo15_ = {9, nullptr, nullptr};
    arbol_binario nodo10_ = {10, &nodo5_, &nodo15_};
    arbol_binario raiz__ = {20, &nodo10_, &nodo7_};
    /*
    20
    / \
    10  7
    / \
    5  9
    
    */
    assert(verificar_max_heap(raiz__) == true);

    std::cout << "Todos los tests pasaron exitosamente!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}