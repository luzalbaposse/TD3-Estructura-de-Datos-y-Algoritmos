#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

struct usuario{
string nombre;
string email;
int cantidad_de_seguidores;
};

struct persona{
 string nombre;
 int edad;
 string dni;
};

struct materia{
    string nombre;
    int codigo;
    int cantidadDeAlumnos;
    string carrera;
};

bool SeLlevanDiez(persona p1, persona p2){
    if(p1.edad - p2.edad == 10 || p2.edad - p1.edad == 10){
        return true;
    }
    else{
        return false;
    }
}

persona persona_mas_grande(const vector<persona> &lista_de_personas){
    int i = 0;
    int mayor = 0;
    persona persona_mayor;
    while(i<lista_de_personas.size()){
        if(lista_de_personas[i].edad > mayor){
            mayor = lista_de_personas[i].edad;
            persona_mayor = lista_de_personas[i];
        }
        i++;
    }
    i = 0;
    while(i<lista_de_personas.size()){
        if(lista_de_personas[i].edad == mayor){
            return lista_de_personas[i];
        }
        i++;
    }

    return persona_mayor;
}
int main(){
    struct usuario usuario1 = {"luz", "luzalbaposse@gmail.com", 0};
    struct persona persona1 = {"ana", 20, "12345678"};
    struct persona persona2 = {"pero", 30, "12345678"};
    struct persona persona3 = {"juana", 40, "12345678"};
    struct persona persona4 = {"coti", 50, "12345678"};
    struct persona persona5 = {"luis", 10, "12345678"};
    cout << SeLlevanDiez(persona1, persona2) << endl;
    cout << usuario1.nombre << endl;
    cout << usuario1.email << endl;
    cout << usuario1.cantidad_de_seguidores << endl; 
    vector<persona> lista_de_personas = {persona1, persona2, persona3, persona4, persona5};
    cout << persona_mas_grande(lista_de_personas).nombre << endl;
}