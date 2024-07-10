/*
Implementar una función bool buscar(int n, nodo*arbol ) que devuelva true
si el elemento n está presente en algun nodo del arbol
Sugerencia: divide and conquer
*/

#include <iostream>
#include <vector>

using namespace std;

struct nodo{
    int valor;
    nodo* izq;
    nodo* der;
};

bool buscar(nodo* raiz, int n){
    if(raiz == NULL) return false;
    if(raiz->valor == n) return true;
    return buscar(raiz->izq, n) || buscar(raiz->der, n);
}

//? Necesito almacenar elementos distintos ordenados y agregar/quitar/buscar de manera eficiente: -> agregar en o log n quitar en o log n y buscar en o log n. 
//* Para esto, la idea es almacenarlos de manera conveniente en un arbol binario. El elemento de la raíz es mayor quelos de la izquierda y menor que los de la derecha. Así mantengo la altura cercana a log n
