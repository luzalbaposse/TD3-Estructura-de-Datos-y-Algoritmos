#include<iostream>
#include<vector>
using namespace std;

struct nodo{
    int clave;
    nodo* hijo_izq;
    nodo* hijo_der;
};

bool es_primo(int n){
    if(n<2) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

nodo* crear_hoja(int elem){
    return new nodo({elem, nullptr, nullptr});
}
/*
El algoritmo es:
1. Entra N -> Es primo?
    a. Si es primo, creo hoja y retorno.
    b. Si no es primo, busco el divisor y llamo recursivamente a la función
*/

nodo* descomponer (int n){
    if(es_primo(n)){ return crear_hoja(n);} 
    else{
        nodo*raiz=crear_hoja(n);
        for(int i=2; i*i<=n;i++){ 
            if(n%i==0 && es_primo(i)){
            raiz->hijo_izq = descomponer(i);
            raiz->hijo_der = descomponer(n/i);
            break;
            }
        }
     return raiz;
        }
}

void imprimir_arbol(nodo* raiz, int espacio = 0, int incremento = 5) {
    if (raiz == nullptr)
        return;

    espacio += incremento;

    imprimir_arbol(raiz->hijo_der, espacio);

    cout << endl;
    for (int i = incremento; i < espacio; i++)
        cout << " ";
    cout << raiz->clave << "\n";

    imprimir_arbol(raiz->hijo_izq, espacio);
}
int main() {
    vector<int> test_cases = {10, 15, 18, 23, 49};

    for (int test_case : test_cases) {
        cout << "Descomponiendo " << test_case << " en un árbol binario:" << endl;
        nodo* arbol = descomponer(test_case);
        imprimir_arbol(arbol);
        cout << "---------------------------------" << endl;
    }

    return 0;
}