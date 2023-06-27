#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
string ConvertidorDeMayusculas(const string& palabra){
    string resultado=palabra;
    for (char& a:resultado){
        if (a >='a' && a <= 'z'){
            a=a-'a'+'A';
        }
    }
    return resultado;
}
int main(){
    list<string>ListaDePalabras;
    string palabra;
    int cantPalabras;
    cout<<"Cuantas palabras desea ingresar?"<<endl;
    cin>>cantPalabras;
    for (int i=0; i<cantPalabras;i++){
        cout<<"Ingresa la palabra"<<endl;
        cin>>palabra;
        ListaDePalabras.push_back(palabra);
    }
    cout<<"Lista de palabras sin ordenar:"<<endl;
    for (string a:ListaDePalabras){
        cout<<a<<", ";
    }
    cout<<endl;
    ListaDePalabras.sort();
    cout<<"Lista de palabras en orden alfabetico: "<<endl;
    for (string a:ListaDePalabras){
        cout<<a<<", ";
    }
    cout<<endl;
    string PalabraABuscar;
    cout<<"Ingrese la palabra a buscar: ";
    cin>>PalabraABuscar;
    cout<<endl;
    int Repetida=count(ListaDePalabras.begin(),ListaDePalabras.end(), PalabraABuscar);
    cout<<"La palabra "<<PalabraABuscar<<" se repite "<<Repetida<<" veces en la lista."<<endl;
    cout<<"Lista de palabras sin convertirlas a mayusculas:"<<endl;
    for (string a:ListaDePalabras){
        cout<<a<<", ";
    }
    cout<<endl;
    transform(ListaDePalabras.begin(), ListaDePalabras.end(), ListaDePalabras.begin(), ConvertidorDeMayusculas);
    cout<<"Lista de palabras final convertidas en mayusculas:"<<endl;
    for (string a:ListaDePalabras){
        cout<<a<<", ";
    }
    cout<<endl;
    return 0;
}
