#include <gtest/gtest.h>

#include "lista.h"

using namespace std;

TEST(Cursor, 01_cursor_apunta_al_primer_elemento_agregado) {
    Lista<int> lista;
    lista.agregarAtras(123);

    EXPECT_EQ(123, lista.cursor());
}

TEST(Cursor, 02_cursor_apunta_al_siguiente_tras_borrar) {
    Lista<int> lista;

    lista.agregarAtras(123);
    lista.agregarAtras(456);
    lista.borrarIesimo(0);

    EXPECT_EQ(456, lista.cursor());
}

TEST(Cursor, 03_avanzar_cambia_el_cursor_al_siguiente_elemento) {
    Lista<int> lista;

    lista.agregarAtras(123);
    lista.agregarAtras(456);
    lista.agregarAtras(789);

    EXPECT_EQ(123, lista.cursor());

    lista.avanzar();
    EXPECT_EQ(456, lista.cursor());

    lista.avanzar();
    EXPECT_EQ(789, lista.cursor());
}

TEST(Cursor, 04_avanzar_se_mantiene_en_el_ultimo_elemento) {
    Lista<int> lista;

    lista.agregarAtras(123);
    EXPECT_EQ(123, lista.cursor());

    lista.avanzar();
    EXPECT_EQ(123, lista.cursor());
}

TEST(Cursor, 05_cursor_apunta_al_anterior_tras_borrar_si_no_hay_siguiente) {
    Lista<int> lista;

    lista.agregarAtras(123);
    lista.agregarAtras(456);
    lista.avanzar();
    lista.borrarIesimo(1);

    EXPECT_EQ(123, lista.cursor());
}
