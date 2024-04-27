#include <iostream>
#include <vector>
using namespace std;

int potencia(int n, int m){
/*
Calcula con divide & conquer la ptencia entre dos numeros
*/
    if(m == 0){
        return 1;
    }
    if(m == 1){
        return n;
    }
    int mitad = m / 2;
    int res = potencia(n, mitad);
    if(m % 2 == 0){
        return res * res;
    }
    else{
        return res * res * n;
    }
}

/*
Vector montaña: toma un vector montaña de enteros y devuelve el valor que está en el pico. Un vector es montaña si tienen una primera parte que es estrictamente creciente y una segunda parte que es estrictamente decrecientte. El pico es el máximo valor del vector, que separa la parte creciente de la dereciente. Por ejemplo, el vector {-1,4,5,6,9,3,2,1} es montaña pero el vector {1,2,3,4,5} no lo es.
*/

int pico_de_montaña_auxiliar(const vector<int>& v, int izquierda, int derecha) {
    if (izquierda == derecha) {
        return v[izquierda]; // Solo queda un elemento, este es el pico
    }

    int mitad = izquierda + (derecha - izquierda) / 2;
    if (v[mitad] < v[mitad + 1]) {
        // El pico está en la parte derecha
        return pico_de_montaña_auxiliar(v, mitad + 1, derecha);
    } else {
        // El pico está en la parte izquierda o es el actual
        return pico_de_montaña_auxiliar(v, izquierda, mitad);
    }
}

int pico_de_montaña(const vector<int>& v) {
    return pico_de_montaña_auxiliar(v, 0, v.size() - 1);
}


int main(){
    cout << potencia(2, 3) << endl;
    cout << potencia(3, 3) << endl;
    cout << potencia(2, 4) << endl;
    cout << potencia(3, 4) << endl;
    cout << potencia(2, 5) << endl;

    vector<int> v;
    v.push_back(-1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(9);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    cout << pico_de_montaña(v) << endl;

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    // este vector no es montaña
    cout << pico_de_montaña(v2) << endl;

    return 0;
}