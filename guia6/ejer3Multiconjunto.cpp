#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Multiconjunto{ 
/*
Rep(e:estr):: (e.cantidad_distintos == |elementos| <=> e.elementos = {e1, e2, ..., en} && para todo i : 0<=i<=n-1 y para todo j : 0<=j<=n-1 => i!=j => e.elementos[i] != e.elementos[j]) && |e.cantidad_distintos| >= 0 && |e.elementos| >= 0
*/
    private:
        int cantidad_distintos;  // Precondición: - | Postcondición: cantidad_distintos == 0
        vector<int> elementos; // Precondición: - | Postcondición: elementos == {}
    public:
        Multiconjunto(); // Precondición: Rep(e:estr) válida | Postcondición: cantidad_distintos == 0
        
        int contar_apariciones(int e) const{
            int contador = 0;
            for (int i = 0; i < elementos.size(); i++){
                if (elementos[i] == e){
                    contador++;
                }
            return contador;
            } 
        }

        void agregar(int e){
        /*Precondición: true Postcondición: {} U e */
            elementos.push_back(e);
            // Si e no está en elementos, entonces cantidad_distintos++
            if (contar_apariciones(e) == 1){
                cantidad_distintos++;
            }
            }
       
        void quitar(int e){
        /*Precondición: e está en elementos | Postcondición: {} - e*/
            int ce = 0;
            for (int i = 0; i < elementos.size(); i++){
                if (elementos[i] == e){
                    elementos.erase(elementos.begin() + i); 
                    ce++;
                }
            }
            if (ce > 0){
                cantidad_distintos--;
            }
                }
        

        int cardinal() const{
        // Cuántos conjuntos hay
            return elementos.size();
        } 

        int cantidad_elementos_distintos() const{
            // Cantidad de elementos distintos
            return cantidad_distintos;
        }

};
