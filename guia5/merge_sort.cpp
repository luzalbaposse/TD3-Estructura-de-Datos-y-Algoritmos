// Re-versión de mergesort tal que en lugar de devolver el vector ordenado, modifique y ordene el vector que se pasa por referencia. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergesort(vector<int> & v, int d, int h){
   
    // Caso Base
    if ( d == h){ // Ya estamos : D
        return;
    }
    // Mitad
    int m = (d+h)/2; 
    
    // Divide
    mergesort(v, d, m); //Izquierda
    mergesort(v, m+1, h); // Derecha

    // ordeno
    vector<int> aux(h-d+1);
    int i = d;
    int j = m+1;
    int k = 0;
    while (i <= m && j <= h){
        if (v[i] < v[j]){
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    // lo q falte
    while (i <= m){
        aux[k] = v[i];
        i++;
        k++;
    }

    while (j <= h){
        aux[k] = v[j];
        j++;
        k++;
    }

    // junto todo
    for (int i = d; i <= h; i++){
        v[i] = aux[i-d];
    }


}

// Modificiación de mergesort que devuelve la cantidad de inversiones del vector v.
// Una inversión va a ser un par de posiciones i,j del vector tal que i < j y v[i] > v[j]. Entonces, [1,3,5,8,10,12] tiene 0. [1,3,12,5,8,10] tiene 3, que son (2,3) (2,4) y (2,5). Siendo (x,y) posiciones del vector.

int mergesort_inversiones(vector<int> &v, int d, int h){
    // Caso base 
    if (d == h){
        return 0;
    }
    // mitad
    int m = (d+h)/2;

    // Divido
    int inv = mergesort_inversiones(v, d, m);
    inv += mergesort_inversiones(v, m+1, h);

    // voy
    vector<int> aux(h-d+1); // tamaño dado por la cantidad de elementos que hay entre d y h
    int i = d;
    int j = m+1;
    int k = 0;
    int inv_local = 0; // va a contar las inversiones de este merge
    while (i <= m && j <= h){
        if (v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
            inv_local += m-i+1; // si v[j] es menor que v[i], entonces v[j] es menor que todos los elementos de la izquierda
        }
        k++;
    }

    // lo q falte
    while (i <= m){
        aux[k] = v[i];
        i++;
        k++;
    }

    while (j <= h){
        aux[k] = v[j];
        j++;
        k++;
    }

    // junto todo
    for (int i = d; i <= h; i++){
        v[i] = aux[i-d];
    }

    return inv + inv_local;
}

// la lógica acá es: si v[i] > v[j] entonces v[i] es mayor que todos los elementos de la derecha de v[j]. Entonces, si v[i] > v[j] entonces hay m-i+1 inversiones, siendo m la mitad del vector. Esto de que es mayor que todosl os elementos a la derecha de v[j] se puede asegurar porque el vec

int main(){
    vector<int> v = {3, 2, 1, 5, 4};
    mergesort(v, 0, v.size()-1);
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int> v2 = {1,3,5,8,10,12};
    cout << mergesort_inversiones(v2, 0, v2.size()-1) << endl;

    vector<int> v3 = {1,3,12,5,8,10};
    cout << mergesort_inversiones(v3, 0, v3.size()-1) << endl;


    return 0;
}

