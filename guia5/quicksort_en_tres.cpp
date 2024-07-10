/*
Implementar una modificación de quicksort que divida el vector en tres partes en lugar de dos. Para eso, la función dividir debe elegir dos pivots p y q, con p<=q y ver para cada elemento e del vector cual de estas se cumple:

- e >= p
- p < e <= q
- q < e
*/
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void quicksort_tres(vector<int>& v, int d, int h) {
    if (d >= h) {
        return;
    }
    
    // p va a ser inferior y q será el pivote superior

    if (v[d] > v[h]) {
        swap(v[d], v[h]);
    }
    int p = v[d];
    int q = v[h];
    
    int i = d + 1;
    int k = d + 1;
    int j = h - 1;
    
    while (k <= j) {
        if (v[k] < p) {
            swap(v[k], v[i]);
            i++;
        } else if (v[k] > q) {
            swap(v[k], v[j]);
            j--;
            k--; // 
        }
        k++;
    }
    
    swap(v[d], v[i - 1]);
    swap(v[h], v[j + 1]);
    
    quicksort_tres(v, d, i - 2); //
    quicksort_tres(v, i, j);
    quicksort_tres(v, j + 2, h);
}

int main() {
    vector<int> v = {3, 7, 8, 5, 2, 1, 9, 5, 4};
    quicksort_tres(v, 0, v.size() - 1);
    
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
