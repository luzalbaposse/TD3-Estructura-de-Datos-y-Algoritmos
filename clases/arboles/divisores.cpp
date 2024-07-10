/*
A partir de un número entero N>0 de entrada, devolver un arbol binario tal que:
- N esté en la raíz
- Si un nodo padre K no es primo, agregarle dos hijos p>1 y q>1 tales que K = pq 
Si es primo, no agregarle hijos
Sugerencia: definir recursivamente nodo* descomponer(int n)
*/

#include <iostream>
#include <vector>

using namespace std;

struct nodo{
    int valor;
    nodo* izq;
    nodo* der;
};

bool es_primo(int n){
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

nodo* descomponer(int n){
    nodo* nuevo = new nodo;
    nuevo->valor = n;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if(es_primo(n)) return nuevo;
    for(int i = 2; i <= n/2; i++){ // busco el divisor
        if(n%i == 0){
            nuevo->izq = descomponer(i);
            nuevo->der = descomponer(n/i);
            break;
        }
    }
    return nuevo;
}

void imprimir(nodo* raiz){
    if(raiz == NULL) return;
    cout << raiz->valor << " ";
    imprimir(raiz->izq);
    imprimir(raiz->der);
}


int main(){
    int n;
    cin >> n;
    nodo* raiz = descomponer(n);
    imprimir(raiz);
    return 0;
}