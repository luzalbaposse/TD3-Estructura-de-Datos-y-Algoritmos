#include <vector>
#include <iostream>
using namespace std;
#include <list>
#include <gtest/gtest.h>


/*
(a) Escribir el invariante de representación en español.
(b) Implementar las operaciones e indicar el orden de complejidad de cada una
*/
template <typename T>
class Pila{
    /*
    a. Invariante de rep: La pila es una lista de elementos de tipo T, donde el tope de la misma va a ser e igual al último elemento de la lista.
    */
    public:
        Pila() : elementos() {};
        // POST: La pila está vacía.
        bool es_vacia() const{ // O(1)
            return !(elementos.size() > 0);
        }
        const T& tope() const{ // O(1)
            return elementos.back();
        }
        // PRE: es_vacia() da falso.
        void apilar(T elem){ // O(1)
            elementos.push_back(elem);
        }
        // PRE: Verdadero
        // POST: Se agrega a la pila el valor elem, por lo tanto tope() es igual a elem.
        void desapilar(){
            elementos.pop_back();
        }
        // PRE: es_vacia() da falso.
        // POST: elimina de la pila el elemento devuelto por tope()
    private:
        list<T> elementos;
    };


    
    TEST(PilaVacia, 00){
    // Caso 1: Pila vacía
    Pila<int> pila;
    EXPECT_TRUE(pila.es_vacia());
    }
    TEST(ApilarUnElemento, 00){
    // Caso 2: Apilar un elemento
    Pila<int> pila;
    pila.apilar(1);
    EXPECT_FALSE(pila.es_vacia());
    EXPECT_EQ(1, pila.tope());
    }       
    TEST(DesapilarUnElemento, 00){
    // Caso 3: Desapilar un elemento
    Pila<int> pila;
    pila.apilar(1);
    pila.desapilar();
    EXPECT_TRUE(pila.es_vacia());
    }  
    TEST(ApilarVariosElementos, 00){
    // Caso 4: Apilar varios elementos
    Pila<int> pila;
    pila.apilar(1);
    pila.desapilar();
    pila.apilar(1);
    pila.apilar(2);
    pila.apilar(3);
    EXPECT_EQ(3, pila.tope());
    pila.desapilar();
    EXPECT_EQ(2, pila.tope());
    pila.desapilar();
    EXPECT_EQ(1, pila.tope());
    pila.desapilar();
    EXPECT_TRUE(pila.es_vacia());
    } 
        



        


        
       


