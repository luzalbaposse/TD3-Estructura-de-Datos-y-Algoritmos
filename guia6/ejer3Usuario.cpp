#include <vector>
#include <iostream>
#include <set>
using namespace std;
// El invariante de representación va a definir todos los atributos.

class Usuario{
/*
Rep(e:estr) = |e.nombre| > 0 && e.edad > 0  && #(amigos) > 10 => es_popular == true 
*/
    private:
        string nombre; // Precondición: nombre no está vacío | Postcondición: nombre() == nombre
        int edad;  // Precondición: edad es mayor a cero | Postcondición: edad( ) == edad
        set<string> amigos; // Precondición: - | Postcondición: amigos == {}
        bool es_popular; // Precondición: - | Postcondición: es_popular() == false
    
    public:
        Usuario(string nombre, int edad) : nombre(nombre), edad(edad), es_popular(false) {};
        /*Precondición: nombre no está vacío y edad es mayor a cero | Postcondición: cree un objeto usuario.
        */
        string nombre_() const{
        /*
        Método observador, devuelve el nombre del usuario.
        Pre-condición: -
        Post-condición: devuelve el nombre del usuario.
        */
        return nombre;
        }
        int edad_() const{
        /*
        Método observador, devuelve la edad del usuario.
        Pre-condición: -
        Post-condición: devuelve la edad del usuario.
        */
        return edad;
        }
        void agregar_amigo(string nombre){
        /*
        Método modificador, agrega un amigo al usuario.
        Pre-condición: -
        Post-condición: amigos == amigos U {nombre}
        */
        amigos.insert(nombre);

        if (amigos.size() >= 10){
            es_popular = true;
        }
        }

        bool es_amigo(string nombre) const{
        /*
        Método observador, devuelve si el usuario es amigo de otro.
        Pre-condición: -
        Post-condición: devuelve si el usuario es amigo de otro.
        */
            return (amigos.count(nombre) > 0);
        }
        bool es_popular_() const{
        /*
        Método observador, devuelve si el usuario es popular.
        Pre-condición: -
        Post-condición: if |amigos|>=10 true else false fi
        */
            return (amigos.size() >=10);
        }  
};

int main(){
    // Me creo un usuario para mi
    Usuario u("Luz", 20);
    // Me creo un usuario para mi amiga
    Usuario u2("Martina", 20);
    Usuario u3 ("Pepito", 30);
    Usuario u4 ("Juan", 30);
    Usuario u5 ("Pedro", 30);
    Usuario u6 ("Maria", 30);

    // Agrego a todos como amigos
    u.agregar_amigo(u2.nombre_());
    u.agregar_amigo(u3.nombre_());
    u.agregar_amigo(u4.nombre_());
    u.agregar_amigo(u5.nombre_());
    u.agregar_amigo(u6.nombre_());

    // Martina es mi amiga?
    cout << u.es_amigo(u2.nombre_()) << endl;

}