#include <gtest/gtest.h>

#include "lista.h"

using namespace std;

TEST(Borrado, 01_borrar_ultimo) {
    Lista<int> lista;
    lista.agregarAtras(1);
    lista.agregarAtras(2);

    lista.borrarUltimo();
    EXPECT_EQ(1, lista.longitud());
    EXPECT_EQ(1, lista.iesimo(0));

    lista.borrarUltimo();
    EXPECT_EQ(0, lista.longitud());
}

TEST(Borrado, 02_borrar_iesimo) {
    Lista<int> lista;
    lista.agregarAtras(1);
    lista.agregarAtras(2);
    lista.agregarAtras(3);

    lista.borrarIesimo(1);
    EXPECT_EQ(2, lista.longitud());
    EXPECT_EQ(1, lista.iesimo(0));
    EXPECT_EQ(3, lista.iesimo(1));

    lista.borrarIesimo(0);
    EXPECT_EQ(1, lista.longitud());
    EXPECT_EQ(3, lista.iesimo(0));

    lista.borrarIesimo(0);
    EXPECT_EQ(0, lista.longitud());
}
