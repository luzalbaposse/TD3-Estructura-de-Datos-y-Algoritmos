#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Multiconjunto{ 
    private:
        int cantidad_distintos; 
        vector<int> elementos;
    public:
        Multiconjunto();
        void agregar(int e);
        void quitar(int e);
        int contar_apariciones(int e) const;
        int cardinal() const;
        int cantidad_elementos_distintos() const;
};
