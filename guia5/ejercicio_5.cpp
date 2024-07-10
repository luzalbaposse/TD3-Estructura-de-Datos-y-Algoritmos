/*

Ejercicio 5. Dar un algoritmo para ordenar alfabéticamente un string sabiendo que sólo contiene letras minúsculas (sin tíldes ni eñe). El algoritmo debe tener una complejidad temporal en peor
caso de O(n) donde n es el tamaño del string.

*/

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void ordenar_string(string & s){
// Counting sort? 
// tengo 26 opciones
vector<int> f(26,0); // O(1)
// cuento cuantas veces aparece cada una
for (int i = 0; i < s.size(); i++){
    f[s[i]-'a']++;
}
// armo el string ordenado
for(int i = 0, j = 0; i < 26; i++){ // O(1)
    while(f[i] > 0){ // O(n)
        s[j] = i + 'a';
        j++;
        f[i]--;
    }
}
}


int main(){
    string s = "zbca";
    ordenar_string(s);
    cout << s << endl;
    return 0;
}