#include <iostream>
#include <vector>
using namespace std;

int productoria(const vector<int> &v, int index = 0){
    if(index == v.size()){
        return 1;
    }
    else{
        return v[index] * productoria(v, index + 1);
    }
}

int cantidad_de_ocurrencias(const string &s, const vector<string> &v, int index = 0){
    if(index == v.size()){
        return 0;
    }
    else{
        if(v[index] == s){
            return 1 + cantidad_de_ocurrencias(s, v, index + 1);
        }
        else{
            return cantidad_de_ocurrencias(s, v, index + 1);
        }
    }
}

int contar_coincidencias(const vector <int> &v, int index = 0){
    if(index == v.size()){
        return 0;
    }
    else{
        if(v[index] == index){
            return 1 + contar_coincidencias(v, index + 1);
        }
        else{
            return contar_coincidencias(v, index + 1);
        }
    }
}

vector<int> solo_positivos(const vector <int> &v, int index = 0){
    if(index == v.size()){
        return {};
    }
    else{
        if(v[index] > 0){
            vector<int> res = solo_positivos(v, index + 1); // res es el vector que se va a devolver
            res.push_back(v[index]);
            return res;
        }
        else{
            return solo_positivos(v, index + 1);
        }
    }
}

void multiplicar_todos(vector<int> &v,, int n, int index = 0){
    if(index == v.size()){
        return;
    }
    else{
        v[index] = v[index] * n;
        multiplicar_todos(v, n, index + 1);
    }
}
