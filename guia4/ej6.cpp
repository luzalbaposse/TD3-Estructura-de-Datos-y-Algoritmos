#include <iostream>
#include <vector>
using namespace std;

/*Sublista de suma máxima
Resolver aplicando el esquema divide & conquer. Dado un vector de enteros v, encontrar el subvector contiguo y con al menos un elemento que tenga la suma más grande y devolver su suma. Ejemplos:
- v = {-1,2,-10,8,1,-3} -> 9
- v = {1,2,3,4,5} -> 15
- v = {1,2,-3,4,5} -> 9
- v = {1,2,-3,4,5,-1} -> 11
*/

int ssm(vector<int>&v){

    if(v.size() == 1){
        return v[0];
    }

    int mitad = v.size()/2; // Divide

    vector<int> izq(v.begin(), v.begin() + mitad); // armo vector izquierdo
    vector<int> der(v.begin() + mitad, v.end()); // armo vector derecho

    int suma_izq = ssm(izq); // Conquisto
    int suma_der = ssm(der); // Conquisto
 
    int suma_izq_max = 0; // Suma máxima de la izquierda
    int suma_izq_temp = 0; // Suma temporal de la izquierda 
   
    for(int i = mitad - 1; i >= 0; i--){
        suma_izq_temp += v[i];
        suma_izq_max = max(suma_izq_max, suma_izq_temp);
    }

    int suma_der_max = 0;
    int suma_der_temp = 0;
    for(int i = mitad; i < v.size(); i++){
        suma_der_temp += v[i];
        suma_der_max = max(suma_der_max, suma_der_temp);
    }

    return max(max(suma_izq, suma_der), suma_izq_max + suma_der_max);

}

int main(){
    vector<int> v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(-10);
    v.push_back(8);
    v.push_back(1);
    v.push_back(-3);
    cout << ssm(v) << endl;
    return 0;
}