#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Carrito{
    private:
        int peso_maximo;
        vector<string> items;
        map<string, int> pesos_items;
        map<string, float> precios_por_item;

    public:

        // Constructor
        Carrito(int peso_maximo) : peso_maximo(peso_maximo) {}; 
        // Observadores
        int peso_disponible() const{
            int peso_total = 0;
            for (int i = 0; i < items.size(); i++){
                peso_total += pesos_items.at(items[i]); // at se usa para ir a un valor de un map
            }
            return peso_maximo - peso_total;
        }
        
        bool buscar_item(string nombre) const{
            // binary search
            // int l = 0;
            // int r = items.size() - 1;
            // while (l <= r){
            //     int m = l + (r - l) / 2;
            //     if (items[m] == nombre){
            //         return true;
            //     }
            //     if (items[m] < nombre){
            //         l = m + 1;
            //     }
            //     else{
            //         r = m - 1;
            //     }
            // }
            int i = 0;
            while (i < items.size()){
                if(items[i] == nombre){
                    return true;
                }
                i++;
            }
            return false;
        }
        
        int peso_de_item(string nombre) const{
            return pesos_items.at(nombre);
        }
        int precio_de_item(string nombre) const{
            return precios_por_item.at(nombre);
        }
        // Modificadores
        void borrar_item(string nombre){
            for (int i = 0; i < items.size(); i++){
                if (items[i] == nombre){
                    items.erase(items.begin() + i);
                    break;
                }
            }
        }
        void agregar_item(string nombre, int peso, float precio){
            if (peso_disponible() >= peso){
                items.push_back(nombre);
                pesos_items[nombre] = peso;
                precios_por_item[nombre] = precio;
            }

        }
        // Otras operaciones
        float monto_total() const{
            float monto = 0;
            for (int i = 0; i < items.size(); i++){
                   monto += precios_por_item.at(items[i]);
            }
            return monto;
        }

};

int main(){
    // (d) Construir un Carrito de peso máximo 10 con los items necesarios para cocinar lo que cenaste ayer, consultar el peso disponible y el monto total.
    Carrito c(10);
    c.agregar_item("papa", 2, 10);
    c.agregar_item("cebolla", 1, 5);
    c.agregar_item("ajo", 1, 5);
    c.agregar_item("carne", 3, 20);
    c.agregar_item("sal", 1, 2);
    c.agregar_item("pimienta", 1, 2);
    c.agregar_item("aceite", 1, 5);
    cout << "Peso disponible: " << c.peso_disponible() << endl; // 10 - 2 - 1 - 1 - 3 - 1 - 1 - 1 = 0
    cout << "Monto total: " << c.monto_total() << endl; // 10 + 5 + 5 + 20 + 2 + 2 + 5 = 49
    return 0;

}