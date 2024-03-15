#include <vector>
#include <iostream>

using namespace std;

int sumatoria(const vector<int> &numeros){
    int suma = 0;
    for (int i = 0; i < numeros.size(); i++){
        suma += numeros[i];
    }
    return suma;
}

int farenheit_a_celcius(int farenheit){
    return (farenheit - 32) * 5 / 9;
}

bool es_primo(int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

bool es_palindromo(string s){
    for (int i = 0; i < s.size()/2; i++){
        if (s[i] != s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}

string concatenacion(vector<string> s){
    string resultado = "";
    for (int i = 0; i < s.size(); i++){
        resultado += s[i];
    }
    return resultado;
}

int main(){
    vector<int> numeros = {1, 2, 3, 4, 5};
    cout << sumatoria(numeros) << endl;
    cout << farenheit_a_celcius(32) << endl;
    cout << es_primo(7) << endl;
    cout << es_palindromo("hola") << endl;
    cout << concatenacion({"hola", " ", "mundo"}) << endl;
    return 0;
}