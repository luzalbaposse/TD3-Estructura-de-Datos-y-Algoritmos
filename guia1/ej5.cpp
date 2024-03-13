#include <iostream>
#include <vector>
using namespace std;

string reemplazar_vocales_por_a(string texto){
    int i = 0;
    while(i<texto.size()){
        if(texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u'){
            texto[i] = 'a';
        }
        i++;
}
        return texto;
}

bool suman_cero(int a, int b){
    return a+b == 0;
}

int maximo(int a, int b){
    if a < b{
        return b;
    }
    else{
        return a;
    }
}

int cantidad_de_vocales(string texto){
    int i = 0;
    int contador = 0;
    while(i<texto.size()){
        if(texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u'){
            contador++;
        }
        i++;
    }
    return contador;

    }

bool es_vocal(char caracter){
    bool vocal = false;
    if(texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u'){
        vocal = true;
    }
    return vocal;
}

int cantidadVocales2(string texto){
    int i = 0;
    int contador = 0;
    while(i<texto.size()){
        if(es_vocal(texto[i])){
            contador++;
        }
        i++;
    }
    return contador;
}