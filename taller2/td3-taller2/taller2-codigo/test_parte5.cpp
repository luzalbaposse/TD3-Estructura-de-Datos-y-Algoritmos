#include <gtest/gtest.h>

#include "lista.h"

using namespace std;

TEST(Retroceder, 01_retroceder_cambia_el_cursor_al_elemento_anterior) {
    Lista<int> lista;

    lista.agregarAtras(123);
    lista.agregarAtras(456);
    lista.agregarAtras(789);

    lista.avanzar();
    lista.avanzar();

    EXPECT_EQ(789, lista.cursor());

    lista.retroceder();
    EXPECT_EQ(456, lista.cursor());

    lista.retroceder();
    EXPECT_EQ(123, lista.cursor());
}

TEST(Retroceder, 02_retroceder_se_manitene_en_el_primer_elemento) {
    Lista<int> lista;

    lista.agregarAtras(123);
    EXPECT_EQ(123, lista.cursor());

    lista.retroceder();
    EXPECT_EQ(123, lista.cursor());
}

TEST(Retroceder, 03_avanzar_y_retroceder_funcionan_tras_borrar_elementos) {
    Lista<int> lista;

    lista.agregarAtras(0);
    lista.agregarAtras(1);
    lista.agregarAtras(2);
    lista.agregarAtras(3);
    lista.agregarAtras(4);
    lista.agregarAtras(5);
    lista.agregarAtras(6);
    lista.agregarAtras(7);

    lista.borrarIesimo(7);
    lista.borrarIesimo(5);
    lista.borrarIesimo(3);
    lista.borrarIesimo(1);

    // estado actual: { 0, 2, 4, 6 }

    EXPECT_EQ(0, lista.cursor());

    lista.avanzar();
    EXPECT_EQ(2, lista.cursor());

    lista.avanzar();
    EXPECT_EQ(4, lista.cursor());

    lista.avanzar();
    EXPECT_EQ(6, lista.cursor());

    lista.retroceder();
    EXPECT_EQ(4, lista.cursor());

    lista.retroceder();
    EXPECT_EQ(2, lista.cursor());

    lista.retroceder();
    EXPECT_EQ(0, lista.cursor());
}
