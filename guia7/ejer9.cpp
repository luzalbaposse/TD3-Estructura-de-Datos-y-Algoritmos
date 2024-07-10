#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <gtest/gtest.h>
#include <string>
using namespace std;

struct arbol_binario{
    int valor;
    arbol_binario* izq;
    arbol_binario* der;
    int cantidad_total_hijos;
};

/*
Cumple el invariante de árbol binario de búsqueda reverso, o sea que está ordenado de mayor a menor. Además, para todo nodo n del arbol, n.cantidad_total_hijos indica la cantidad total de nodos presentes en ambos subárboles 
*/

// (A) Implementar la operación que relaiza una inserción ordenada respetando el invariantte requerido por lae structura. El algoritmo debe tener complejidad O(h)

arbol_binario insertar(arbol_binario *raiz, int elem){
    if(raiz == nullptr){
    arbol_binario nuevo_elemento;
    nuevo_elemento.valor = elem;
    }
    else if(elem < raiz->valor){
    raiz->der=insertar(raiz->der, elem);
    }
    else if(elem > raiz->valor)
}

// ( B ) 

int contar_menores_a(const arbol_binario * raiz, int valor)