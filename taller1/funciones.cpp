#include "funciones.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    /*
    Toma el nombre de un archivo que contiene una palabra por línea y devuelve un vector de strings con todas las palabras tal como están en el archivo
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
    Toma un intento, una palabra secreta y un listado de palabras e indica si el intento es legal o no. 
    Un intento es legal si tiene la misma longitud que la palabra secreta y si es una palabra reconocida en el listado de palabras
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
    for (char strChar : str) {
        if (strChar == c) {
            return true;
        }
    }
    return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    /*
    Toma un intento y una palabra secreta, y devuelve un vector con la respuesta para cada una de las letras del 
    intento. 
    
    Una letra del intento puede estar en LugarCorrect si la palabra secreta tiene esa misma letra en esa 
    posición, puede estar en un LugarIncorrecto si la palabra secreta contiene esa letra pero en otra posición o 
    puede estar NoPresente si la palabra secreta no contiene esa letra
    
    Por ejemplo: si la palabra secreta es "bolsa" y el intento es "aviso", se espera que esta función devuelva el 
    vector {LugarIncorrecto, NoPresente, NoPresente, LugarCorrecto, LugarIncorrecto}.
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
    Toma el vector de EstadoLetra que devuelve evaluar_intento y devuevle un string que se puede imprimir por pantalla para indicar esa respuesta al usuario. Se espera que LugarCorrecto se indique con el caracter +, LugarIncorrecto con - y NoPresente con X
    Por ejemplo: si el vector en entrada es {LugarIncorrecto, NoPresente, NoPresente, LugarCorrecto, LugarIncorrecto} se espera que el string de salida sea "-XX+-".
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
