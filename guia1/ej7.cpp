#include <vector>
#include <iostream>

using namespace std;

// void modificar_primero(const vector<int> & lista){
//    lista[0] = 0;
// }
void modificar_primero_2(vector<int> & lista){
   lista[0] = 0;
}

bool es_vacio(vector<int> & lista){
    return lista.size() == 0;
}


int main(){
    vector<int> mediciones = {19, 18, 22, 20, 23, 24};
    // modificar_primero(mediciones);
    modificar_primero_2(mediciones);    
    cout << mediciones[0] << endl;
    const vector<int> mediciones2 = {19, 18, 22, 20, 23, 24};
    bool res = es_vacio(mediciones2); // No se puede hacer esto porque la función no modifica el vector? O sea, se tiene q pasar por refe y debería almacenar el resultado de esto
    
}

/*
- ¿Cuál es el defecto en el código? No se modifica el vector.
- ¿Que se debe modificar? sacas el const, basically
*/
