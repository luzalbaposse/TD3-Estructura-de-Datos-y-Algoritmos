#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Palabras{
    private:
        vector<string> palabras;
    public:
        // Constructor
        Palabras() : palabras({}) {};
        // Observadores
        bool contiene(string p) const{
        // binary search 
        int l = 0;
        int r = palabras.size() - 1;
        while (l <= r){ // O(log n)
            int m = l + (r - l) / 2;
            if (palabras[m] == p){
                return true;
            }
            if (palabras[m] < p){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return false;
        }

        // Modificadores
        void agregar_palabras(vector<string> ps){
            for (int i = 0; i < ps.size(); i++){
                if (!contiene(ps[i])){
                    palabras.push_back(ps[i]);
                }
            }
        }
        void borrar_palabra(string p){
            for (int i = 0; i < palabras.size(); i++){
                if (palabras[i] == p){
                    palabras.erase(palabras.begin() + i);
                }
            }
        }
        // Otras operaciones
        int contar_vocales() const{
            int c = 0;
            for (int i = 0; i < palabras.size(); i++){
                for (int j = 0; j < palabras[i].size(); j++){
                    if (palabras[i][j] == 'a' || palabras[i][j] == 'e' || palabras[i][j] == 'i' || palabras[i][j] == 'o' || palabras[i][j] == 'u'){
                        c++;
                    }
                }
            }
            return c;
        }
    };


    /*
    (a) ¿Qué precondición debería tener el método agregar_palabra para garantizar que el invariante de representación se mantiene? En general, ¿cuál es el vínculo entre la precondición de los métodos y el invariante Rep?
    El vinculo entre la precondición y el Rep es que podemos asumir que rep vale en la pre, pero hay que asegurar que vale en la post.
    La precondición es que |ps| > 0.

    (b) Implementar los métodos en C++ asumiendo las precondiciones que vea necesarias.

    (c) ¿Cuál es el órden de complejidad O en peor caso para el método contar_vocales? Puede
    tomar como tamaño de entrada N la suma de todas las longitudes todas las palabras.

    El orden de complejidad es O(N) porque recorro toda la lista una vez y para cada palabra recorro todas las letras.

    (d) ¿Se puede dar una implementación de contar_vocales con órden de complejidad O(1) en
    peor caso, respetando la estructura de datos dada?

    No, porque para saber cuantas vocales hay en una palabra tengo que recorrerla entera.

    (e) Proponer una nueva estructura de datos con su invariante de representación que permita
    implementar contar_vocales en O(1). Volver a implementar todos los metodos respetando
    la nueva estructura y el nuevo invariante de representación.

    Rep(e:estr) = |e.palabras| >= 0 && para todo i : 0<=i<=|e.palabras|-1 y para todo j : 0<=j<=|e.palabras[i]|-1 => e.palabras[i][j] es vocal
    Esta rep es valida porque si todas las palabras tienen al menos una vocal, entonces la cantidad de vocales es la cantidad de palabras.
    */

    class Palabras2{
        private:
            vector<string> palabras;
            int cantidad_vocales;
        public:
            Palabras2() : palabras({}), cantidad_vocales(0) {};
            // Observadores
        bool contiene(string p) const{
        // binary search 
        int l = 0;
        int r = palabras.size() - 1;
        while (l <= r){ // O(log n)
            int m = l + (r - l) / 2;
            if (palabras[m] == p){
                return true;
            }
            if (palabras[m] < p){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return false;
        }

        // Modificadores
        void agregar_palabras(vector<string> ps){
            for (int i = 0; i < ps.size(); i++){
                if (!contiene(ps[i])){
                    palabras.push_back(ps[i]);
                }
                cantidad_vocales=+contar_vocales(ps);
            }
        }
        void borrar_palabra(string p){
            int voc = contar_vocales_s(p);
            cantidad_vocales -= voc;
            for (int i = 0; i < palabras.size(); i++){
                if (palabras[i] == p){
                    palabras.erase(palabras.begin() + i);
                }
            }
        }
        // Otras operaciones
        int contar_vocales(const vector<string>& p) const {
            int c = 0;
            for (const string& s : p) {
                c += contar_vocales_s(s);
            }
            return c;
        }
        int contar_vocales_s(string s) const{
            int c = 0;
            for (int i = 0; i < s.size(); i++){ // O(n)
                    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i]== 'u'){
                        c++;
                    }
                }
        return c;

            }

        int cantidad_vocales_() const{
            return cantidad_vocales; // O(1)
        }
    };