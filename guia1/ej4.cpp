#include <iostream>
#include <vector>
using namespace std;

int incisoa(){
    vector<int> mediciones = {19, 18, 22, 20, 23, 24};
    int i = 0;
    while(i<mediciones.size()){
        cout << mediciones[i] << endl;
        i++;
    }
    return 0;
}

int incisob(){  // Agrega el paréntesis de apertura aquí
    vector<int> mediciones = {19, 18, 22, 20, 23, 24};
    int i = mediciones.size()-1;
    while(i>=0){
        cout << mediciones[i] << endl;
        i--;
    }
    
    //implemento lo mismo pero haciendo q la variable j empiece en 0 y aumente hasta mediciones.size
    int j = 0;
    while(j<mediciones.size()){
        cout << mediciones[mediciones.size() - j - 1] << endl;  // Resta j+1 en lugar de j
        j++;
    }
    return 0;
}

int incisoc(){  
    /*
    Completar el código del siguiente programa para que imprima por pantalla un mensaje en caso de que el texto ingresado contenga la letra 'z'. En ese caso, se debe indicar también la posición de la letra en el texto ingresado. Por ejemplo, si el texto ingresado es "adivinanza", se debe indicar que la letra 'z' se encuentra en la posición 8
    */
    string texto;
    getline(cin, texto);
    int i = 0;
    while(i<texto.size()){
        if(texto[i] == 'z'){
            cout << "La letra 'z' se encuentra en la posicion " << i << endl;
        }
        i++;
    }
    return 0;
}

int incisod(){
    /*
    Escriba un programa que tome un texto ingresado por el usuario e imprima por pantalla el mismo texto reemplazando todas las letras vocales por la letra 'a'. Por ejemplo, si el texto ingresado es "Hola, ¿que tal?", se debe imprimir "Hala, ¿qaa tal?".
    */
    string texto;
    cout << "Ingrese un texto: ";
    getline(cin, texto);
    int i = 0;
    while(i<texto.size()){
        if(texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u'){
            texto[i] = 'a';
        }
        i++;
}
    cout << texto << endl;
    return 0;
}
int main(){
    incisoa();
    incisob();
    incisoc();
    incisod();
    return 0;
}