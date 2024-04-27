#include <iostream>
#include <vector>
using namespace std;


int productoria_dc(const vector<int> &v, int index = 0){
    
    // Caso base
    if(v.size() == 1){
        return v[0];
    }

    else{
        // Dividir
        vector<int> p1(v.begin(), v.begin() + (v.size()/2));
        vector<int> p2(v.begin() + (v.size()/2), v.end());

        // Conquistar
        int prod1 = productoria_dc(p1, index);
        int prod2 = productoria_dc(p2, index);

        // Combinar 
        return prod1 * prod2;

    }

}

int sumatoria_dc(const vector<int> &v, int index = 0){
    
    // Caso base
    if(v.size() == 1){
        return v[0];
    }

    else{
        // Dividir
        vector<int> s1(v.begin(), v.begin() + (v.size()/2));
        vector<int> s2(v.begin() + (v.size()/2), v.end());

        // Conquistar
        int sum1 = sumatoria_dc(s1, index);
        int sum2 = sumatoria_dc(s2, index);

        // Combinar 
        return sum1 + sum2;

    }

}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << productoria_dc(v) << endl; // 120
    cout << sumatoria_dc(v) << endl; // 15
    return 0;

}

