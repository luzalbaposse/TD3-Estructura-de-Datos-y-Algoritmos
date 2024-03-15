#include <iostream>
#include <vector>
using namespace std;

void function_A(int n){
    n = 5;
}

void function_B(int & n){
    n = 5;
}

void encerrar_entre_parentesis(string & s){
    s = "(" + s + ")";
}

int reemplazar_numero(vector<int> & lista, int n){
    /*Toma un vector de enteros y un entero n y devuelve un entero. Debe modificar cada aparición de n en el vector por un 0 y además devolver la cantidad de aparicionesd e n en el vector original*/

    int contador = 0;
    for (int i = 0; i<lista.size(); i++){
        if (lista[i] == n){
            lista[i] = 0;
            contador++;
        }
    }
    return contador;
}

int main(){
    int numero = 10;
    cout <<"numero: " << numero << endl;
    function_A(numero);
    cout <<"numero: " << numero << endl;
    function_B(numero);
    cout <<"numero: " << numero << endl;
    string hola = "hola";
    cout << hola << endl;
    encerrar_entre_parentesis(hola);
    cout << hola << endl;
    vector<int> numeraskis = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << reemplazar_numero(numeraskis, 10) << endl;
    return 0;
}

/*

- ¿Qué se imprimirá por pantalla al ejecutar el programa?
numero: 10
numero: 10
numero: 5

- ¿En qué se diferencian las dos funciones que está implementadas?

La función A recibe un parámetro por valor, por lo que no modifica el valor de la variable original.
La función B recibe un parámetro por referencia, por lo que modifica el valor de la variable original.

- ¿Qué significa que el tipo de retorno de la función sea void? 

Significa que no va a devolver un valor, solo efectúa cambios.

*/