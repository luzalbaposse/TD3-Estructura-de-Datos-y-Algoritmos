#include "funciones.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
    // Cargar el listado de palabras
    vector<string> listado = cargar_listado("listado.txt");
    if (listado.size() == 0){
        cout << "Ups! El listado de palabras está vacío! Probá de nuevo" << endl;
        return 1;
    }
    // Elegir una palabra secreta al azar
    bool InicioDelJuego = false;
    string RespuestaUsuario;
    cout << "¿Estás para jugar un Wordle? Respondé s o n"<<endl;
    cin >> RespuestaUsuario;
    if(RespuestaUsuario == "s"){
        InicioDelJuego = true;
    }
    else{
        cout << "¿Seguro que no querés jugar? Respondé s o n"<<endl;
        cin >> RespuestaUsuario;
        if(RespuestaUsuario == "s"){
            InicioDelJuego = true;
        }
        else{
            cout << "Bueno, está bien!" << endl;
        }
    }
    while(InicioDelJuego){
        srand(time(0));
        int PalabraRandomIndex = rand() % listado.size();
        string palabra_secreta = listado[PalabraRandomIndex];

        // Inicializar el contador de intentos
        int MaxIntentos = 6;
        // Comienzo el juego
        /*
        
        En caso de que el intento sea válido se debe evaluar el intento y darle la respuesta al usuario por pantalla. ✅
        Esto le resta un intento al usuario para adivinar la palabra. ✅

        En caso de que el intento no sea válido (es decir, no sea legal) se debe indicar por pantalla que el intento 
        no es valido e invitar al usuario escribir un nuevo intento. En este caso no se le resta al usuario una oportunidad. ✅

        En caso de que el usuario adivine la palabra el juego termina y se debe indicar por pantalla que el usuario adivinó. ✅

        En caso de que se agoten los cinco intentos el juego termina y se debe indicar por pantalla que el número de intentos se agotó.✅
        */

        while(MaxIntentos >= 0){
            string intento;
            cout << "Intentá adivinar la palabra secreta: ";
            cin >> intento;
            if(intento_valido(intento, palabra_secreta, listado)){
                vector<EstadoLetra> respuesta = evaluar_intento(intento, palabra_secreta);
                cout << respuesta_en_string(respuesta) << endl;
                if(respuesta_en_string(respuesta) == "+++++"){
                    cout << "¡Felicitaciones! Adivinaste la palabra secreta" << endl;
                    return 0;
                }
                else{
                if(MaxIntentos == 0){
                    cout << "¡Oh no! Te quedaste sin intentos. La palabra secreta era " << palabra_secreta << endl;
                    return 0;
                }
                else{
                MaxIntentos--;
                cout << "Mmmm... Me parece que así no es. Te quedan " << MaxIntentos << " intentos. Volvé a intentar!" << endl;
                }
                }
            }
            else{
                cout << "Uy, ese intento no es válido, intentá de nuevo" << endl;              
            }
        }
}
}