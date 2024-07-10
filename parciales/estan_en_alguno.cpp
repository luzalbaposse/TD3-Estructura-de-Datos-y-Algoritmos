/*
Problema 2. (50 puntos) Ordenamiento
Se quiere implementar una función
vector<int> estan_en_alguno(const vector<int> & A, const vector<int> & B, const vector<int> & C)
que toma por parámetro tres vectores de int. Se tiene como precondición que cada vector A, B y C está ordenado
de forma creciente y no tiene elementos repetidos. Se debe devolver un vector que contenga todos los elementos
de A que están en B o en C.
Ejemplos:
si A = {1,2,3,4,5}, B = {-1,1,2,5,9}, C = {-5,0,2,5,10} se debe devolver {1,2,5}.
si A = {1,2,3,4,5}, B = {1,3,5,7,9}, C = {2,4,6,8,10} se debe devolver {1,2,3,4,5}.
si A = {-2,-1,3,6,7}, B = {1,2,4,5,9}, C = {-5,0,2,5,10} se debe devolver {}.
(a) Implementar la función estan_en_alguno. El algoritmo debe tener órden de complejidad temporal O(n +
m + k) en peor caso, donde n = |A|, m = |B|, k = |C|. Puede asumir que ejecutar X veces la operación
push_back de vector<int> es de tiempo O(X).
(b) Dar un ejemplo de vectores (todos del mismo tamaño N) A, B, C que sea el peor caso de ejecución del
algoritmo y un ejemplo de vectores A, B, C que no sea el peor caso de ejecución del algoritmo. Justificar
cada caso.
(c) Calcular la función de costo temporal T(n, m, k) para el peor caso en función de n, m y k las longitudes
de los vectores. Justificar por qué se cumple el órden O(n + m + k) (ya sea utilizando la definición formal
de O u operando con álgebra de órdenes).
*/

// (a) Lo q me está pidiendo es hacer una funcion que tome A, B y C y devuelva la operación A intersección B U A intersección C en un vector. 


#include <vector>
#include <iostream>
using namespace std;
// Acá conviene usar merge 
/*
Lógica: 
¡Pensar en reducir problemas!
- Podría juntar B y C en un solo vector. O(b+c)
- 
*/
vector<int> estan_en_alguno(const vector<int> & A, const vector<int> & B, const vector<int> & C){
    vector<int> res;
    int ia = 0, ib = 0, ic = 0;
    while(ia < A.size() && ib < B.size() && ic < C.size()){
        if(A[ia] == B[ib] || A[ia] == C[ic]){ 
            // Chequeo que no esté en res A[ia] para no agregarlo dos veces
            if(res.size() == 0 || res[res.size()-1] != A[ia]){
                res.push_back(A[ia]); 
                ia++;
            } else{
                ia++;
            }
            }
        else if(A[ia] < B[ib] && A[ia] < C[ic]){
            ia++;
        }else if(B[ib] < A[ia] && B[ib] < C[ic]){
        ib++;
        }else{
            ic++;
            }

}
    return res;
}

int main(){
    vector<int> A = {1,2,3,4,5};
    vector<int> B = {-1,1,2,5,9};
    vector<int> C = {-5,0,2,5,10};
    vector<int> res = estan_en_alguno(A, B, C);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    vector<int> A2 = {1,2,3,4,5};
    vector<int> B2 = {1,3,5,7,9};
    vector<int> C2 = {2,4,6,8,10};
    vector<int> res2 = estan_en_alguno(A2, B2, C2);

    for(int i = 0; i < res2.size(); i++){
        cout << res2[i] << " ";
    }

    cout << endl;

    vector<int> A3 = {-2,-1,3,6,7};
    vector<int> B3 = {1,2,4,5,9};
    vector<int> C3 = {-5,0,2,5,10};
    vector<int> res3 = estan_en_alguno(A3, B3, C3);

    for(int i = 0; i < res3.size(); i++){
        cout << res3[i] << " ";
    }

    cout << endl;

    vector<int> A4 = {-2,-1,3, 3,6,7,7,8};
    vector<int> B4 = {1,2,3,3,4,5,9};
    vector<int> C4 = {-5,0,2,5,5,7,10};
    vector<int> res4 = estan_en_alguno(A4, B4, C4);

    for(int i = 0; i < res4.size(); i++){
        cout << res4[i] << " ";
    }

    cout << endl;


    return 0;
}