#include <vector>
#include <iostream>

using namespace std;

/*
Se quiere implementar la función
int sumar_picos(const vector<int> & v)
que debe calcular la sumatoria de los valores de los picos que contiene un vector. Llamamos pico a cualquier posición que es estrictamente mayor que sus dos posiciones vecinas. Los extremos de un vector nunca son picos. Por ejemplo, el vector v = {0,1,0,0,0,10,1,9,8} tiene tres picos en lasposiciones1,5y7;ysumar_picos(v) = 1 + 10 + 9 = 20.
(a) Implementar sumar_picos con recursión simple utilizando un sólo llamado recursivo. Se debe recorrer el vector en orden inverso.
(b) Implementar sumar_picos con la técnica Divide & Conquer, partiendo el problema en 2 y utilizando 2 llamados recursivos.
En cada caso, si necesita cambiar los parámetros de la función debe hacerlo en una función auxiliar y mostrar cómo le llama a esa función auxiliar desde la función sumar_picos original.
*/
int sumar_picos_aux(const vector<int> &v, int i, int &res){
    if(i == 0 || i == v.size()){
        return res;
    }
    if (v[i] > v[i-1] && v[i] > v[i+1]){
        res += v[i];

    }
    return sumar_picos_aux(v, i-1, res);
}

int sumar_picos(const vector<int> &v){
    int res = 0;
    return sumar_picos_aux(v, (v.size()-1), res);
}

int s_p_aux(int desde, int hasta, const vector<int>& v, int r){
    if (desde <= 0 || desde >= v.size() - 1)
    {
        return r;
    }
    if(desde == hasta){
        return r;
    }
    if(v[desde] > v[desde-1] && v[desde] > v[desde+1]){
        r += v[desde];
    }
    return s_p_aux(desde+1, hasta, v, r);
}

int sumar_picos_dc(const vector<int> &v){
    int mitad = v.size()/2;
    int res1 = 0;
    int res2 = 0;
    res1 = s_p_aux(1, mitad, v, res1); 
    res2 = s_p_aux(mitad, v.size()-1, v, res2); 
    return res1 + res2;
}

int main(){
    vector<int> v; // 0 1 0 0 0 10 1 9 8 -> los picos son 1, 10 y 9 y el resultado debería ser 20
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(10);
    v.push_back(1);
    v.push_back(9);
    v.push_back(8);
    cout << "Debería dar 20" << endl;
    cout << sumar_picos(v) << endl;
    cout << sumar_picos_dc(v) << endl;

    // testio otro caso de prueba
    vector<int> v2;
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(99);
    v2.push_back(0);
    v2.push_back(10);
    cout << "Debería dar 110" << endl;
    cout << sumar_picos(v2) << endl;
}