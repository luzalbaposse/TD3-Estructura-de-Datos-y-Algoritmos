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

vector<int> mergear_muchos(vector<vector<int>> &vs){
    vector<int> mergeado;
    for(int i=0; i<vs.size(); i++){ // O(n)
        for(int j = 0; j< vs[i].size() ; j++){ // O(n) 
            mergeado.push_back(vs[i][j]);
        }
    }
    mergesort(mergeado, 0, mergeado.size()-1); // O(n log n)
    
    return mergeado;
}

// Complejidad en O(n**2 + n log n) = O(n**2)


