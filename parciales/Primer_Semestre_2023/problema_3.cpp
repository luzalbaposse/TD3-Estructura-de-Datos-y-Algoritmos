#include <vector>
#include <iostream>
using namespace std;

vector<int> histograma(vector<int> v, int a, int b){
    vector<int> res(b - a + 1, 0);
    int i = 0;
    while(i < v.size()){
        int num = v[i];
        if(num >= a && num <= b){
            res[v[i] - a]++;
        }
        i++;
    }
    return res;
}


int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int> h = histograma(v, 4, 5);
    cout << "Debería imprimir 1 1" << endl;

    for(int i = 0; i < h.size(); i++){
        cout << h[i] << " ";
    }
    cout << endl;
    return 0;
}