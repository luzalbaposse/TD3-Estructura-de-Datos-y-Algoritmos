#include <vector>
#include <iostream>
#include <set>
using namespace std;



int main(){

    set<int> mi_conjunto = {6, 8, -95, 9};
    mi_conjunto.insert(6);
    mi_conjunto.insert(7);
    mi_conjunto.erase(9);

    cout << mi_conjunto.size() << endl; // 4
    cout << mi_conjunto.contains(6) << endl; // true
    cout << mi_conjunto.contains(9) << endl; // true
    cout << mi_conjunto.empty() << endl; // false
}