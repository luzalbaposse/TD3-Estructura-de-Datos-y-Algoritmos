#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
using namespace std;

template <typename T>
class Lista {
public:
    Lista();
    ~Lista();

    int longitud() const;

    void agregarAtras(const T& elemento);

    // Pre: 0 <= posicion < longitud()
    T iesimo(int posicion) const;

    T cursor() const;

    void avanzar();
    void retroceder();

    void borrarUltimo();
    void borrarIesimo(int posicion);

private:
    struct nodo {
        nodo(const T& un_elemento) : elemento(un_elemento), siguiente(nullptr), anterior(nullptr) {}
        T elemento;
        nodo* siguiente;
        nodo* anterior;
    };

    nodo* _primero;
    nodo* _cursor;
    int _longitud;
};

template <typename T>
Lista<T>::Lista() : _primero(nullptr), _cursor(nullptr), _longitud(0) {}

template <typename T>
Lista<T>::~Lista() {
    nodo* actual = _primero;
    while (actual != nullptr) {
        nodo* sig = actual->siguiente;
        delete actual;
        actual = sig;
    }
    _primero = nullptr;
    _cursor = nullptr;
}

template <typename T>
int Lista<T>::longitud() const {
    return _longitud;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elemento) {
    nodo* nuevo = new nodo(elemento);

    if (_primero == nullptr) {
        _primero = nuevo;
        _cursor = nuevo;
    } else {
        nodo* actual = _primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
    _longitud++;
}

template <typename T>
T Lista<T>::iesimo(int posicion) const {
    nodo* actual = _primero;
    int i = 0;
    while (i < posicion) {
        actual = actual->siguiente;
        i++;
    }
    return actual->elemento;
}

template <typename T>
T Lista<T>::cursor() const {
    // if (_cursor == nullptr) { // No se si poner esto o no : )
    //     throw runtime_error("ups, no hay cursor : ("); 
    // }
    return _cursor->elemento;
}

template <typename T>
void Lista<T>::avanzar() {
    if (_cursor != nullptr && _cursor->siguiente != nullptr) {
        _cursor = _cursor->siguiente;
    }
}

template <typename T>
void Lista<T>::retroceder() {
    if (_cursor != nullptr && _cursor->anterior != nullptr) {
        _cursor = _cursor->anterior;
    }
}

template <typename T>
void Lista<T>::borrarUltimo() {
    if (_primero == nullptr) {
        return;
    }
    if (_primero->siguiente == nullptr) {
        delete _primero;
        _primero = nullptr;
        _cursor = nullptr;
    } else {
        nodo* actual = _primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        if (_cursor == actual) {
            _cursor = actual->anterior;
        }
        actual->anterior->siguiente = nullptr;
        delete actual;
    }
    _longitud--;
}

template <typename T>
void Lista<T>::borrarIesimo(int posicion) {
    if (posicion == 0) {
        nodo* aBorrar = _primero;
        _primero = aBorrar->siguiente;
        if (_primero != nullptr) {
            _primero->anterior = nullptr;
        }
        if (_cursor == aBorrar) {
            _cursor = _primero;
        }
        delete aBorrar;
    } else {
        nodo* actual = _primero;
        int i = 0;
        while (i < posicion - 1) {
            actual = actual->siguiente;
            i++;
        }
        nodo* aBorrar = actual->siguiente;
        actual->siguiente = aBorrar->siguiente;
        if (aBorrar->siguiente != nullptr) {
            aBorrar->siguiente->anterior = actual;
        }
        if (_cursor == aBorrar) {
            if (aBorrar->siguiente != nullptr) {
                _cursor = aBorrar->siguiente;
            } else {
                _cursor = actual;
            }
        }
        delete aBorrar;
    }
    _longitud--;
}

#endif
