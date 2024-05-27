/*
Se quiere una clase Tateti. Debe proveer métodos para crear un juego, determinar de quién es el turno, hacer una jugada (cruz o círculo), determinar si el juego terminó, y (cuando el juego terminó) determinar quién ganó o si hubo empate. Por simplicidad, suponer que siempre empieza jugando la cruz.
(c) Implementar la clase Tateti en C++.
*/

#include <vector>
#include <iostream>
using namespace std;

enum class Casillero {circulo, cruz, vacio};
enum class Jugador {circulo, cruz};

class Tateti{ 
    vector<vector<Casillero> > tablero;
    Jugador turno = Jugador::cruz;

    public:

        Tateti() : tablero(3, vector<Casillero>(3, Casillero::vacio)) {}

        Jugador a_quien_le_toca(){
            return turno;
        };

        Casillero observar_posicion(int fila, int columna){
            return tablero[fila][columna];
        };
        
        void hacer_jugada(Jugador jugador, int fila, int columna){

            if (jugador == Jugador::cruz){

                // Jugó cruz, despues le toca a circulo
                if(tablero[fila][columna]==Casillero::vacio){
                    tablero[fila][columna] = Casillero::cruz;
                }
                else{
                    cout << "Movimiento inválido" << endl;
                }
                turno = Jugador::circulo;
            }
            else{
                // Juega circulo, despues le toca a cruz
                if(tablero[fila][columna]==Casillero::vacio){
                    tablero[fila][columna] = Casillero::circulo;
                }
                else{
                    cout << "Movimiento inválido" << endl;
                }
                turno = Jugador::cruz;
            };
        };

        bool esta_terminado(){
        tuple<bool,Casillero> res = hay_ganador();

        if(get<0>(res)){
            return true;
        }
        if(hubo_empate()){
            return true;
        }
        return false;
        };

        bool hubo_empate(){
            bool resultado = false;
            tuple<bool,Casillero> res = hay_ganador();
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(tablero[i][j] != Casillero::vacio && !(get<0>(res))){
                        resultado = true;
                    }
                    else{
                        resultado = false;
                    }
                }
            }
            return resultado; 
        };


        Jugador quien_gano(){
           tuple<bool,Casillero> res = hay_ganador();
           if(get<1>(res) == Casillero::circulo){
            return Jugador::circulo;
           }
           else{
            return Jugador::cruz;
           }
        };

    private:
         tuple<bool,Casillero> hay_ganador(){
            // chequeo para cada fila
            Casillero ganador;
            bool res = false;
            
            if(tablero[0][0]==tablero[0][1] && tablero[0][1]==tablero[0][2]){
            
                ganador = tablero[0][0];
                res = true;
            };
            if(tablero[1][0]==tablero[1][1] && tablero[1][1]==tablero[1][2]){
                ganador = tablero[1][0];
                res = true;            
                };
            if(tablero[2][0]==tablero[2][1] && tablero[2][1]==tablero[2][2]){
                ganador = tablero[2][0];
                res = true; 
            };
            //chequeo cada columna
            if(tablero[0][0]==tablero[1][0] && tablero[1][0]==tablero[2][0]){
                ganador = tablero[0][0];
                res = true; 
            };
            if(tablero[0][1]==tablero[1][1] && tablero[1][1]==tablero[2][1]){
                ganador = tablero[0][1];
                res = true; 
            };
            if(tablero[0][2]==tablero[1][2] && tablero[1][2]==tablero[2][2]){
                ganador = tablero[0][2];
                res = true;             };

            // chequeo las diagonales
            if(tablero[0][0]==tablero[1][1] && tablero[1][1]==tablero[2][2]){
                ganador = tablero[0][0];
                res = true;             };
            if(tablero[2][0]==tablero[1][1] && tablero[1][1]==tablero[0][2]){
                ganador = tablero[2][0];
                res = true;             
                };   
            tuple<bool,Casillero> resultado = make_tuple(res, Casillero::vacio);
            return resultado;

            };
        };