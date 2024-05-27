#include <vector>
#include <iostream>
using namespace std;

/*
El histograma de una serie de valores enteros es un gráfico de barras ver-
ticales donde cada barra tiene como longitud la cantidad de apariciones
de cada valor del rango [a, b]. Representaremos un histograma como un
vector<int> con la longitud de cada barra en el intervalo [a,b], que incluye
a y b, con a < b. Por ejemplo, el histograma {1,4,5,1} en el rango [11,14]
representa a una serie de 11 valores entre 11 y 14, con 1 aparición del valor 11, 4 apariciones del valor 12, 5 apariciones del valor 13, y 1 aparición del valor 14, como muestra la figura adjunta.
Dados dos histogramas h1 de rango [a,b] y h2 de rango [c,d], implementar la función vector<int> combinar(vector<int> h1, vector<int> h2, int a, int b, int c, int d)
que calcula el resultado de combinar ambos histogramas, sabiendo que el rango [c,d] está conteni- do en el rango [a,b], es decir, que vale que a ≤ c < d ≤ b. Notar que como el rango del histograma h1 es igual o mayor que el rango de h2, se cumple que |h2| ≤ |h1|.

Ejemplo: Dado el histograma h1 = {0,0,1,1,2,3,0,0} en el rango [-5,2] y el histograma h2 = {4,3,2,1} en el rango [-4,-1], el resultado de combinar(h1,h2,-5,2,-4,-1) será el histograma {0,4,4,3,3,3,0,0} (también en rango [-5,2]).

*/

//a. Escribir la función combinar con un único ciclo, sabiendo que a <= c < d <= b.

vector <int> combinar(vector<int> h1, vector<int> h2, int a, int b, int c, int d){
    vector <int> res;
    int i = 0;
    while(i < h1.size()){
        if(i < c-a){
            res.push_back(h1[i]);
        }else if(i >= c-a && i < d-a){
            res.push_back(max(h1[i], h2[i-(c-a)]));
        }else{
            res.push_back(h1[i]);
        }
        i++;
    }
    return res;
}
