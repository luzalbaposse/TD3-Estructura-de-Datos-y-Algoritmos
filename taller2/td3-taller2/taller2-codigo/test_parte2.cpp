#include <gtest/gtest.h>

#include "lista.h"

using namespace std;


TEST(ListaGenerica, 01_lista_vacia) {
    Lista<int> lista;
    
    EXPECT_EQ(0, lista.longitud());
}

TEST(ListaGenerica, 02_agregar_elementos_incrementa_la_longitud) {
    Lista<int> lista;
    lista.agregarAtras(2);
    
    EXPECT_EQ(1, lista.longitud());

    lista.agregarAtras(10);
    
    EXPECT_EQ(2, lista.longitud());
}

TEST(ListaGenerica, 03_puedo_acceder_a_los_elementos) {
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    
    Lista<int> lista;
    lista.agregarAtras(primer_elemento);
    lista.agregarAtras(segundo_elemento);
    
    EXPECT_EQ(primer_elemento, lista.iesimo(0));
    EXPECT_EQ(segundo_elemento, lista.iesimo(1));
}


TEST(ListaGenerica, 04_tipo_de_datos_complejo) {
    struct punto2d {
        int x;
        int y;

        punto2d(int a, int b) : x(a), y(b) {}
        bool operator==(const punto2d b) const {return this->x == b.x && this->y == b.y;}
    };

    Lista<punto2d> l;
    punto2d p(0,1);
    l.agregarAtras(p);
    l.agregarAtras(punto2d(1,1));

    EXPECT_EQ(p, l.iesimo(0));
}

