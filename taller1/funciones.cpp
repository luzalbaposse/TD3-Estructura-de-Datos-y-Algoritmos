#include "funciones.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    /*
    Requiere: el nombre de un archivo de texto
    Devuelve: un vector con todas las palabras del archivo
    */
    vector<string> listado;
    ifstream infile(nombre_archivo);
    if (infile.good() == false){
        cerr << "Error al abrir el archivo " << nombre_archivo << endl;
        return listado;
    }
    string line;
    while(getline(infile, line)){
        listado.push_back(line);
    }
    infile.close();
    return listado;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
    /*
   Requiere: un intento, una palabra secreta y un listado de palabras
   Devuelve: true si el intento es válido, es decir, si está en el listado y tiene la misma longitud que la palabra secreta. False en caso contrario
   */
   int i = 0;
   bool res = false;
   while(i < listado.size()){
        if(intento == listado[i] && intento.size() == palabra_secreta.size()){
            res = true;
            break;
        }
    i++;
   }
   return res;
}

bool charExistsInString(char c, const string& str) {
/*
Requiere: un caracter y un string
Devuelve: True si el caracter está en el string, False en caso contrario
*/
    for (char strChar : str) {
        if (strChar == c) {
            return true;
        }
    }
    return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    /*
    Requiere: un intento y una palabra secreta
    Devuelve: un vector de EstadoLetra que indica para cada letra del intento si está en la palabra secreta y si está en el lugar correcto o no.
    */
    vector<EstadoLetra> respuesta;
    for(int i = 0; i < intento.size(); i++){
        if(intento[i] == palabra_secreta[i]){
            respuesta.push_back(EstadoLetra::LugarCorrecto);
        } else if(charExistsInString(intento[i], palabra_secreta)){
            respuesta.push_back(EstadoLetra::LugarIncorrecto);
        } else {
            respuesta.push_back(EstadoLetra::NoPresente);
        }
    }
    return respuesta;
}



string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    /*
    Requiere: un vector de EstadoLetra
    Devuelve: un string que representa la respuesta en forma de + (Lugar Correcto), - (Lugar Incorrecto) y X (No Presente)
    */
   string res = "";
    for(int i = 0; i < respuesta.size(); i++){
         if(respuesta[i] == EstadoLetra::LugarCorrecto){
              res += "+";
         } else if(respuesta[i] == EstadoLetra::LugarIncorrecto){
              res += "-";
         } else {
              res += "X";
         }
}
return res;
}
