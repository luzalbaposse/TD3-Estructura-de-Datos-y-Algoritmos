#include <vector>
#include <iostream>
using namespace std;
#include <list>
#include <queue>
#include <gtest/gtest.h>
#include <string>

/*
(a) Escribir el invariante de representación en español.
(b) Implementar las operaciones e indicar el orden de complejidad de cada una.
(c) Extender la implementación para aceptar mayor cantidad de cajas. Se indicará la cantidad de
cajas en el constructor FilaDeSuper(int cantidad_cajas). Puede modificar la estructura
de representación.
(d) Extender la implementación agregando un método int siguiente_caja_disponible() const
cuya precondición es que haya algúna caja disponible y debe devolver en O(1) la caja dispo-
nible con número más bajo. Puede modificar la estructura de representación
*/

class FilaDeSuper{
    /*
    (a) Invariante de Representación: fila_de_espera >= 0 ^ caja_uno_ocupada = false <=> fila_de_espera = 0 ^ caja_dos_ocupada = false <=> fila_de_espera = 0 
    */
    private:
        queue<string> fila_de_espera;
        bool caja_uno_ocupada;
        bool caja_dos_ocupada; 
    public:
        FilaDeSuper() : fila_de_espera(), caja_uno_ocupada(false), caja_dos_ocupada(false) {};
        // POST: La FilaDeSuper es vacía y sus cajas están libres.
        int cantidad_esperando() const{
            return fila_de_espera.size();
        }
        string siguiente() const{
            return fila_de_espera.front();
        }
        bool esta_ocupada(int caja) const{ // O(1)
            if (caja == 1){
                return caja_uno_ocupada;
            }
            if (caja == 2){
                return caja_dos_ocupada;
            }
            if(caja != 1 && caja != 2){
                throw invalid_argument("La caja ingresada no es válida");
            }
        }
        void llega_persona(string dni){ // O(1)
        // PRE: dni es un dni válido
        // POST: El dni se agrega al final de la fila
            fila_de_espera.push(dni);
        }

        void atender_siguiente(int caja){ // O(1)
        // PRE: caja es igual a 1 o 2, cantidad_esperando() no es 0 y esta_ocupada(caja) es false.
        // POST: Se quita de la fila a la siguiente() persona que estaba esperando.
        // Y esta_ocupada(caja) se vuelve true.
            if (caja == 1 && caja_uno_ocupada == false){
                caja_uno_ocupada = true;
                fila_de_espera.pop();
            }
            if (caja == 2 && caja_dos_ocupada == false){
                caja_dos_ocupada = true;
                fila_de_espera.pop();
            }
            if (caja != 1 && caja != 2){
                throw invalid_argument("La caja ingresada no es válida");
            }
        }

        void liberar_caja(int caja){ // O(1)
        // PRE: caja es igual a 1 o 2, esta_ocupada(caja) es true.
        // POST: esta_ocupada(caja) se vuelve false.
            if (caja == 1 && caja_uno_ocupada == true){
                caja_uno_ocupada = false;
            }
            if (caja == 2 && caja_dos_ocupada == true){
                caja_dos_ocupada = false;
            }
            if (caja != 1 && caja != 2){
                throw invalid_argument("La caja ingresada no es válida");
            }
        }
};

TEST(test_FilaDeSuper, test_constructor){
    FilaDeSuper fila;
    EXPECT_EQ(fila.cantidad_esperando(), 0);
}

TEST(test_FilaDeSuper, test_llega_persona){
    FilaDeSuper fila;
    fila.llega_persona("12345678");
    EXPECT_EQ(fila.cantidad_esperando(), 1);
}

TEST(test_FilaDeSuper, test_siguiente){
    FilaDeSuper fila;
    fila.llega_persona("12345678");
    EXPECT_EQ(fila.siguiente(), "12345678");
}

TEST(test_FilaDeSuper, test_atender_siguiente){
    FilaDeSuper fila;
    fila.llega_persona("12345678");
    fila.atender_siguiente(1);
    EXPECT_EQ(fila.cantidad_esperando(), 0);
}

TEST(test_FilaDeSuper, test_liberar_caja){
    FilaDeSuper fila;
    fila.llega_persona("12345678");
    fila.atender_siguiente(1);
    fila.liberar_caja(1);
    EXPECT_EQ(fila.esta_ocupada(1), false);
}


