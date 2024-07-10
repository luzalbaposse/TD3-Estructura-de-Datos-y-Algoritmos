#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void insertion_sort(vector<int>&v){
    // Toma el próximo elemento de la parte que falta ordenar e insertarlo de manera ordenada en la parte que ya está ordenada

    for(int i = 0; i < v.size() ; i ++) {
        int j = i;
        while(j > 0 && v[j] < v[j-1]){
            swap(v[j], v[j-1]);
            j--;
        }
    }
    }


int main(){
    vector<int> v = {3,2,1,4};

    for(int num : v){
        cout << num << " ";
    }

    cout << endl;

    insertion_sort(v);

    for(int num : v){
        cout << num << " ";
    }

    cout << endl;
}