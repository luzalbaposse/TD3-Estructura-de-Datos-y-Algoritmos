#include <iostream>
#include <vector>
using namespace std;

int cantidad_de_ocurrencias_aux(const string &s, const vector<string> &v, int inicio, int fin){
    if(inicio > fin){
        return 0;}
    if(inicio == fin){
        return v[inicio] == s ? 1:0;
    }
    int mitad = inicio + (fin - inicio) / 2;
    int izq = cantidad_de_ocurrencias_aux(s, v, inicio, mitad);
    int der = cantidad_de_ocurrencias_aux(s, v, mitad + 1, fin);
    return izq + der;
    }
int cantidad_de_ocurrencias(const string &s, const vector<string> &v){
    return cantidad_de_ocurrencias_aux(s, v, 0, v.size() - 1);
}

void multiplicar_todos_aux(vector<int> &v, int n, int inicio, int fin){
    if(inicio > fin){
        return;
    }
    if(inicio == fin){
        v[inicio] *= n;
        return;
    }
    int mitad = inicio + (fin - inicio) / 2;
    multiplicar_todos_aux(v, n, inicio, mitad);
    multiplicar_todos_aux(v, n, mitad + 1, fin);
}

void multiplicar_todos(vector<int> &v, int n){
    multiplicar_todos_aux(v, n, 0, v.size() - 1);
}

int main(){
    vector<string> v;
    v.push_back("hola");
    v.push_back("hola");
    v.push_back("chau");
    v.push_back("pepito");
    cout << cantidad_de_ocurrencias("hola", v) << endl;

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    cout << "v2 antes de multiplicar todos: " << endl;
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
    multiplicar_todos(v2, 2);
    cout << "v2 despues de multiplicar todos por 2: " << endl;
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;

    return 0;
}
