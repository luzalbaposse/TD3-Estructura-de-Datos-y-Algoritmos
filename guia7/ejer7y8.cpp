#include <vector>
#include <iostream>
#include <list>
#include <queue>
#include <gtest/gtest.h>
#include <string>
using namespace std;
/*
Ejercicio 7. Se quiere diseñar un tipo de datos DiccionarioDeInt para asociar claves de tipo
int con valores de tipo T. La interfaz es similar a Diccionario pero agregamos explícitamente el
destructor ~DiccionarioDeInt(). Se eligió como estructura de representación un Arbol Binario
de Búsqueda

(a) Escribir el invariante de representación en español,
(b) Implementar las operaciones esta_definida y definir e indicar el orden de complejidad
de cada una en peor caso.
(c) El mejor caso para la complejidad de los algoritmos es que el árbol esté perfectamente ba-
lanceado a la hora de llamar a una función. ¿Cuál sería la complejidad de las operaciones
en ese caso?

*/

/*
Ejercicio 8. Se quiere extender el DiccionarioDeInt con una operacion
list<int> aplanar_ordenado() const que devuelva una lista de enteros con todas las claves
del diccionario en orden ascendente. La operación debe recorrer el árbol de forma inorder.
(a) Implementar aplanar_ordenado sin hacer recursión, usando una variable auxiliar de tipo
std::stack.
(b) Implementar aplanar_ordenado con un algoritmo recursivo siguiendo la estrategia Divide
& Conquer.

*/
template <typename T>
class DiccionarioDeInt{
/*
(a) Invariante de Representación: 
Como es un árbol binario de búsqueda, entonces:
- Cada nodo padre tiene a lo sumo 2 hijos
- Cada nodo izquierdo es menor al padre
- Cada nodo derecho es mayor al padre
- No hay nodos repetidos
- No hay nodos nulos
- No hay ciclos

*/
    public:
        DiccionarioDeInt();
        const T& obtener_valor(int clave) const;
       
        void borrar(int clave);
        ~DiccionarioDeInt();
            bool esta_definida(int clave, nodo*n) const{
        if(n == nullptr) return false; // O(1)
        if(n->clave == clave) return true; // O(1)
        // Si la clave es menor que la clave del nodo actual, busco en el hijo izquierdo
        if(clave < n->clave) return esta_definida(clave, n->hijo_izq); // O(log n)
        // Si la clave es mayor que la clave del nodo actual, busco en el hijo derecho
        return esta_definida(clave, n->hijo_der); // O(log n)
    } // O(log n)

    void definir(int clave, T valor){
        if(raiz == nullptr){ // O(1)
            raiz = new nodo(clave, valor);
            return;
        }
        // si la clave ya está definida, actualizo el valor
        if(esta_definida(clave,raiz)){
            nodo*n = raiz;
            while(n->clave != clave){
                if(clave < n->clave) n = n->hijo_izq;
                else n = n->hijo_der;
            }
            n->valor = valor;
            return;
        }

        // si no está, lo agrego
        nodo*n = raiz;
        // busco el lugar donde agregar el nodo
        while(true){
            if(clave < n->clave){
                if(n->hijo_izq == nullptr){
                    n->hijo_izq = new nodo(clave, valor);
                    return;
                }
                n = n->hijo_izq;
            }else{
                if(n->hijo_der == nullptr){
                    n->hijo_der = new nodo(clave, valor);
                    return;
                }
                n = n->hijo_der;
            }
        }
    }

    list<int> aplanar_ordenado_a() const{
        /*
Devuelva una lista de enteros con todas las claves
del diccionario en orden ascendente. La operación debe recorrer el árbol de forma inorder.
(a) Implementar aplanar_ordenado sin hacer recursión, usando una variable auxiliar de tipo
std::stack.
        */
       list<int> res;
       stack<nodo*> pila; //
       nodo* n = raiz;

       while(n!=nullptr || !pila.empty()){
        while(n!=nullptr){
            pila.push(n);
            n = n->hijo_izq;
        }
        n = pila.top();
        pila.pop();
        res.push_back(n->clave);

        n = n->hijo_der;

       }
       return res;
    }
    list<int> aplanar_ordenado_b() const{
    //(b) Implementar aplanar_ordenado con un algoritmo recursivo siguiendo la estrategia Divide & Conquer.
    list<int> res;
    aplanar_ordenado_b_aux(raiz, res);
    return res;
    }
    void aplanar_ordenado_b_aux(nodo*n, list<int>&res) const{
        if(n == nullptr) return; // caso base
        aplanar_ordenado_b_aux(n->hijo_izq, res);
        res.push_back(n->clave);
        aplanar_ordenado_b_aux(n->hijo_der, res);
    }

    private:
    //( b ) Complejidad de esta_definida: O(log n)
    //      Complejidad de esta_definida en el mejor caso: O(1)

    // Complejidad de definir: O(log n)
    // Complejidad de definir en el mejor caso: O(1)
        struct nodo {
            nodo(int c, T v) : clave(c), valor(v), hijo_izq(nullptr), hijo_der(nullptr) {}
            int clave;
            T valor;
            nodo* hijo_izq;
            nodo* hijo_der;
        };
    nodo* raiz;
};