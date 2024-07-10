#include <vector>
#include <iostream>
using namespace std;
#include <list>
#include <queue>
#include <gtest/gtest.h>
#include <string>
/*
Se quiere diseñar un tipo de datos Diccionario para asociar claves de tipo T1 con
valores de tipo T2. El Diccionario proveerá operaciones para definir el valor asociado a una clave, consultar si una clave está definida en el Diccionario y, en ese caso, obtener el valor asociado a una clave.

Los observadores de std::pair son p.first y p.second. Su documentación está en
https://en.cppreference.com/w/cpp/utility/pair.
(a) Escribir el invariante de representación en español,
(b) Implementar las operaciones e indicar el orden de complejidad de cada una.
(c) Se quiere agregar una operación void actualizar_ultimo(T2 valor) que en O(1) cambie
el valor asociado a la última clave que se definió. Para eso se agregará la siguiente variable a la estructura de representación: list< pair<T1,T2> >::iterator iterador_al_ultimo.
Implementar la nueva operación y modificar la implementación de otros métodos si es nece-
sario
*/

template <typename T1, typename T2>
// Asumir que el tipo T1 tiene operador de igualdad ==
class Diccionario{
    // Invariante de Representación: Para todo par (clave,valor) en claves_valores, no hay otro par con la misma clave.
    public:
        Diccionario() : claves_valores() {};
        // POST: El diccionario está vacío.
        bool esta_definida(T1 clave) const{ // O(n)
        // PRE: Verdadero
            for (auto it = claves_valores.begin(); it != claves_valores.end(); ++it){
                if (it -> first == clave){
                    return true;
                }
            }
            return false;
        }

        const T2 & obtener_valor(T1 clave) const{ // O(n)
        // PRE: esta_definida(clave)
            for (auto it = claves_valores.begin(); it != claves_valores.end(); ++it){
                if (it -> first == clave){
                    return it -> second;
                }
            }
        }
        void definir(T1 clave, T2 valor){
        // PRE: Verdadero
        // Agrego al final de la lista un par con clave y valor
            claves_valores.push_back(make_pair(clave,valor));

        }

        void borrar(T1 clave){
        // PRE: esta_definida(clave)
        
        for (auto it = claves_valores.begin(); it != claves_valores.end(); ++it){
            if (it -> first == clave){
                claves_valores.erase(it);
                break;
            }
        }
    
        }
       
        // POST: esta_definida(clave) es falso. El resto del diccionario
        // se mantiene igual.
    private:
        list< pair<T1,T2> > claves_valores;
};