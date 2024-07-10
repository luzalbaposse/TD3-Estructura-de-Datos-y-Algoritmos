#include <gtest/gtest.h>

TEST(PunterosTest, 00) {
    int numero = 2;
    int *puntero_a_numero;

    // TODO: Hacer que puntero_a_numero apunte a numero
    puntero_a_numero = &numero;
    


    EXPECT_EQ(2, *puntero_a_numero);

    // TODO: Pensar... ¿es necesario liberar memoria? -> No, porque no se reservó memoria en el heap
}

TEST(PunterosTest, 01) {
    int *numero;

    // TODO: Reservar memoria para un entero en el heap, hacer que la variable
    // numero apunte a dicho espacio y guardar un 2.
    numero = new int;
    *numero = 2;

    EXPECT_EQ(2, *numero);

    // TODO: Liberar memoria y asegurarse de que no queden referencias a
    // punteros inválidos apuntando a la posición que ya no podemos acceder.
    delete numero;
    numero = nullptr;

    EXPECT_EQ(nullptr, numero);
}

TEST(PunterosTest, 02) {
    int *numero = new int(2);

    // TODO: Sumar 3 al valor existente en `numero`.
    *numero += 3;

    EXPECT_EQ(5, *numero);

    // TODO: Liberar memoria y asegurarse de que no queden referencias a
    // punteros inválidos apuntando a la posición que ya no podemos acceder.
    delete numero;
    numero = nullptr;

    EXPECT_EQ(nullptr, numero);
}

TEST(PunterosTest, 03) {
    int numero = 2;
    int *puntero_a_numero;

    // TODO: Hacer que `puntero_a_numero` apunte exactamente a la posición de
    // memoria donde está el valor de `numero`.
    puntero_a_numero = &numero;
    EXPECT_EQ(2, *puntero_a_numero);
}


TEST(PunterosTest, 04) {
    int *numero = new int;
    int *alias_de_numero;
    *numero = 2;

    // TODO: Hacer que `alias_de_numero` apunte a la misma posicion de memoria
    // que `numero`. No está permitiro reservar memoria nueva para `alias_de_numero`.
    alias_de_numero = numero;

    EXPECT_EQ(numero, alias_de_numero);
    EXPECT_EQ(2, *alias_de_numero);

    delete alias_de_numero;
    alias_de_numero = nullptr;
    EXPECT_EQ(nullptr, alias_de_numero);

    // TODO: Pensar... ¿a dónde apunta con `numero` ahora? ¿Qué ocurre si
    // queremos acceder al valor en dicha posición de memoria? -> Apunta a la misma dirección de memoria que alias_de_numero, si se accede a la dirección de memoria se obtiene un error
}
