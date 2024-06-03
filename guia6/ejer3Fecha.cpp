#include <vector>
#include <iostream>
using namespace std;

class Fecha{
    
    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha(int dia, int mes, int anio)  : dia(dia), mes(mes), anio(anio) {};

    void avanzar_dia(){
        dia++;
        if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30){
            dia = 1;
            mes++;
        }
        else if(mes == 2 && ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) && dia > 29){
            dia = 1;
            mes++;
        }
        else if(mes == 2 && dia > 28){
            dia = 1;
            mes++;
        }
        else if(dia > 31){
            dia = 1;
            mes++;
        }

        if(mes > 12){
            mes = 1;
            anio++;
        }
    }
        void avanzar_n_dias(int n){
            for(int i = 0; i < n; i++){
                avanzar_dia();
            }
        }
        int dia_() const{
            return dia;
        }
        int mes_() const{
            return mes;

        }
        int anio_() const{
            return anio;

        }
        bool operator==(const Fecha& f) const{
            return (dia == f.dia && mes == f.mes && anio == f.anio);
        }
};

int main(){
    // Fecha con mi cumpleaños 17/12/2003
    Fecha f(17, 12, 2003);
    // Fecha de un añod espues
    Fecha f2(17, 12, 2004);
    // avanzo f1 un año
    f.avanzar_n_dias(365);

    bool iguales = f == f2;
    cout << "Las fechas son iguales: " << iguales << endl;
    cout << "Fecha 1: " << f.dia_() << "/" << f.mes_() << "/" << f.anio_() << endl;
}