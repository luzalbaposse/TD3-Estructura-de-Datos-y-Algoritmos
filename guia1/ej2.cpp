#include <iostream>
using namespace std;

int suma(int a, int b){
    int c = a + b;
    if(c > 0){
        cout << "La suma es positiva" << endl;
    }
    if (c < 0){
        cout << "La suma es negativa" << endl;
    }
    if (c == 0){
        cout << "La suma es cero" << endl;
    }
    return 0;
}

int main(){
    int a, b;
    cout << "Ingrese dos numeros: ";
    cin >> a >> b;
    suma(a, b);
    return 0;
}