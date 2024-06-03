#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
using namespace std;

class Lista {
    public:
    Lista();
    ~Lista();

    int longitud();

    void agregarAtras(const int elemento);

    // Pre: 0 <= posicion < longitud()
    int iesimo(const int posicion);

    private:
        struct nodo {
            nodo(int un_elemento) : elemento(un_elemento), siguiente(nullptr) {}
            int elemento;
            nodo* siguiente;
        };

        nodo* _primero;
        int _longitud;
};

Lista::Lista() : _primero(nullptr), _longitud(0) {}

int Lista::longitud() {
    return _longitud;
}

void Lista::agregarAtras(const int elemento) {
    nodo * nuevo = new nodo(elemento);

    if (_primero == nullptr) {
          _primero = nuevo;
    } else {
        // avanzo hasta que `actual` sea el último nodo
        nodo* actual = _primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
    }
    _longitud++;
}

int Lista::iesimo(const int posicion) {
    // avanzo hasta que `actual` sea el iésimo nodo
    nodo* actual = _primero;
    int i = 0;
    while (i < posicion){
        actual = actual->siguiente;
        i++;
    }

    return actual->elemento;
}

Lista::~Lista() {
    nodo * actual = _primero;
    while (actual != nullptr) {
        nodo* sig = actual->siguiente;
        delete actual;
        actual = sig;
    }
    _primero = nullptr;
}
#endif
