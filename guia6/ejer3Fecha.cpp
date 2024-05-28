#include <vector>
#include <iostream>
using namespace std;

class Fecha{
    
    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha(int dia, int mes, int anio);

        void avanzar_dia(){
            dia++;
            if(dia>31){
                dia = 1;
                mes++;
                if(mes>12){
                    mes = 1;
                    anio++;
                }
            }
            
        }
        void avanzar_n_dias(int n){
            dia = dia + n; 
            if(dia>31){
                dia = dia - 31;
                mes++;
                if(mes>12){
                mes = mes - 12;
                anio++;
            }
            }

        }
        int dia() const{
            return dia;
        }
        int mes() const{
            return mes;

        }
        int anio() const{
            return anio;

        }
        bool operator==(const Fecha& f) const{
            return (dia == f.dia && mes == f.mes && anio == f.anio);
        }
};