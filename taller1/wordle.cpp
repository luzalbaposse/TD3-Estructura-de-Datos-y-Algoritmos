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
            return 0;
        }
    }
    while(InicioDelJuego){
        srand(time(0));
        int PalabraRandomIndex = rand() % listado.size();
        string palabra_secreta = listado[PalabraRandomIndex];

        // Inicializar el contador de intentos
        int MaxIntentos = 6;

        // Comienzo el juego

        while(MaxIntentos >= 0){
            string intento;
            cout << "Intentá adivinar la palabra secreta... Pista: Tiene 5 letras!";
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