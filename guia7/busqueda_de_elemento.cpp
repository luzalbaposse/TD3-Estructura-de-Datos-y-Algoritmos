#include<iostream>
#include<vector>
using namespace std;


struct nodo{
    int clave;
    nodo* hijo_izq;
    nodo* hijo_der;
};

nodo* crear_hoja(int elem){
    return new nodo({elem, nullptr, nullptr});
}

bool buscar(int n, nodo*arbol){
    // Divide and conquer
    if(arbol == nullptr) return false;
    if(arbol->clave == n) return true;
    return buscar(n, arbol->hijo_der) || buscar(n,arbol->hijo_izq);
}

int main(){
    nodo* raiz = crear_hoja(10);
    raiz->hijo_der = crear_hoja(9);
    raiz->hijo_izq = crear_hoja(695);

    cout << buscar(695, raiz) << endl;
    cout << buscar(400, raiz) << endl;

}
