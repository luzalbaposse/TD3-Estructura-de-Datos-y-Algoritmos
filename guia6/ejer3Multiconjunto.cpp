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
        Multiconjunto() : cantidad_distintos(0), elementos({}) {} // Precondición: Rep(e:estr) válida | Postcondición: cantidad_distintos == 0
        
        int contar_apariciones(int e) const{
            int contador = 0;
            for (int i = 0; i < elementos.size(); i++){
                if (elementos[i] == e){
                    contador++;
                }
            } 
            return contador;
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

// ) Construir el siguiente Multiconjunto: {2, 65, 2, 3, 8, 8, 7, 65, 0} y consultar la cantidad de
// elementos distintos.

int main(){
    Multiconjunto m;
    m.agregar(2);
    m.agregar(65);
    m.agregar(2);
    m.agregar(3);
    m.agregar(8);
    m.agregar(8);
    m.agregar(7);
    m.agregar(65);
    m.agregar(0);
    cout << "Cantidad de elementos distintos: " << m.cantidad_elementos_distintos() << endl;
    return 0;
}