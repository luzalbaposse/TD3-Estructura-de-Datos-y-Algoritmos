#include <vector>
#include <iostream>
using namespace std;

// recursión simple

bool es_palindromo(string s){
    if (s.size()<=1){
        return true;
    }
    if (s[0]==s[s.size()-1]){
        return es_palindromo(s.substr(1,s.size()-2));
    }
    return false;
}


string concatenar_palindromos_aux(const vector <string> &v, int index){
    if (index==v.size()){
        return "";
    }
    
    if (es_palindromo(v[index])){
        return v[index] + concatenar_palindromos_aux(v,index+1);
    }

    return concatenar_palindromos_aux(v,index+1);
}

string concatenar_palindromos(const vector <string> &v){
    return concatenar_palindromos_aux(v,0);
}

// Caso con Divide and Conquer


string concatenar_palindromos_dc(const vector <string> &v){
    // Divide: a la mitad
    vector<string> p1(v.begin(), v.begin() + (v.size()/2));
    vector<string> p2(v.begin() + (v.size()/2), v.end());

    // Conquer
    string pal1 = concatenar_palindromos_aux(p1, 0);
    string pal2 = concatenar_palindromos_aux(p2, 0);

    // Combine
    return pal1 + pal2;
}

int main(){
    vector<string> v;
    v.push_back("hola");
    v.push_back("ana");
    v.push_back("oso");
    v.push_back("casa");
    cout << concatenar_palindromos(v) << endl; // anaoso

    // prueba con divide and conquer
    cout << concatenar_palindromos_dc(v) << endl; // anaoso
    return 0;
}