#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort_(vector<int> &v){
// Buscar el mínimo de la parte que falta ordenar y colocarlo al final de la parte que ya está ordenada.
    int n = v.size(); 
    for(int i = 0; i < n; i++){ // O ( n )
        int minimo = i; 
        for(int j = i+1; j<n;j++){ // O ( n )
            if(v[j] < v[minimo]){
                minimo = j;
            }
        }
        swap(v[i], v[minimo]);
    }
    // O(n^2)   
}
int main(){

vector<int> v = {8, 2, 5, 8, 10, 7, 6, 4};

for(int num : v){
    cout << num << " ";
}

cout << endl;

selection_sort_(v);

for(int num : v){
    cout << num << " ";
}

}

