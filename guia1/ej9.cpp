
#include <vector>
#include <iostream>

using namespace std;

enum class Color {Blanco, Negro, Rojo, Verde, Azul};
Color un_color = Color::Blanco;
Color otro_color = Color::Rojo; 

/*
(b) Utilizando la definición del tipo Color del punto anterior, implemente una función que dado
un vector<Color> cuente la cantidad de veces que contiene el color rojo.
*/

int ContadorDeColores(vector<Color> v){
    int i = 0;
    int j = 0;
    while(i<v.size()){
        if(v[i] == Color::Rojo){
            j++;
        }
        i++;
    }
    return j;
}
/*
(c) Escribir un programa que utilice un tipo enumerado para almacenar un día de la semana y
escribir una función que tome un día de la semana e indique si es fin de semana o no.
*/

enum class Semana {Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo};

Semana dia = Semana::Martes;
Semana diaDos = Semana::Domingo;

bool EsFinde(Semana d){
    if(d == Semana::Sabado || d == Semana::Domingo){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    /*(a) qué tipo imprime*/
    // cout << un_color << endl; // Es de tipo Color y vale Blanco
    // cout << un_color == otro_color << endl; // Es de tipo bool, devuelve 0
    // cout << un_color == Color::Blanco << endl; // Es de tipo bool y va a dar 1
    // cout << Color::Blanco == Color::Azul << endl; // Es de tipo bool y da 0

    vector<Color> v = {Color::Blanco, Color::Rojo, Color::Verde, Color::Rojo, Color::Azul};
    cout << ContadorDeColores(v) << endl;

    cout << EsFinde(diaDos) << endl;
}