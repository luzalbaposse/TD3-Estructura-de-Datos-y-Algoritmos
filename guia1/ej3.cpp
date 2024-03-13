#include <iostream>
#include <vector>
using namespace std;

string materia = "Algoritmos y Estructuras de Datos";
vector<int> mediciones = {19, 18, 22, 20, 23, 24};
int main(){
    
    cout << materia[0] << endl; // A
    cout << materia[5] << endl; // i
    cout << (materia.front() == 'E') << endl; // False
    cout << (materia.back() == 's') << endl; // True
    cout << materia.size() << endl; // 33
    cout << materia.length() << endl; // 33
    cout << materia.substr(13, 11) << endl; // Estructuras (porque saca la subcadena, desde la posición 13 y por 11 lugares)
    
    cout << mediciones[0] << endl; // 19
    cout << mediciones[3] << endl; // 20
    cout << mediciones.front() << endl; // 19
    cout << (mediciones.back() == 23 )<< endl; // false
    cout << mediciones.size() << endl; // 6

    materia.append("{} - UTDT"); // Algoritmos y Estructuras de Datos{} - UTDT
    materia.push_back('X'); // Algoritmos y Estructuras de Datos{} - UTDTX
    mediciones.pop_back(); // 19, 18, 22, 20, 23 - saca el ultimo elemento
    mediciones.push_back(20); // 19, 18, 22, 20, 23, 20 - agrega un elemento al final
    
    return 0;
}