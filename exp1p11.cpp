#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int>NumerosEnteros;
    int num, cantNum;
    cout<<"Cuantos numeros enteros desea ingresar?"<<endl;
    cin>>cantNum;
    for (int i=0; i<cantNum; i++){
        cout<<"Ingrese un numero entero:"<<endl;
        cin>>num;
        NumerosEnteros.push_back(num);
    }
    int suma=0;
    for (int numero: NumerosEnteros){
        suma+=numero;
    }
    sort(NumerosEnteros.begin(),NumerosEnteros.end());
    int maximo,minimo;
    maximo= *max_element(NumerosEnteros.begin(),NumerosEnteros.end());
    minimo= *min_element(NumerosEnteros.begin(), NumerosEnteros.end());
    cout<<"Suma de toditos los numeros: "<<suma<<endl;
    cout<<"Numero mayor: "<<maximo<<endl;
    cout<<"Numero menor: "<<minimo<<endl;
    cout<<"Numeros sin ordenar: "<<endl;
    for(int numero: NumerosEnteros){
        cout<<numero<<", ";
    }
    cout<<endl;
    cout<<"Numeros Ordenados de forma ascendente: "<<endl;
    for(int numero: NumerosEnteros){
        cout<<numero<<", ";
    }
    cout<<"Lista de numeros con numeros pares: "<<endl;
    for(int numero: NumerosEnteros){
        cout<<numero<<", ";
    }
    cout<<endl;
    cout<<"Lista de numeros sin numeros pares: "<<endl;
    NumerosEnteros.erase(remove_if(NumerosEnteros.begin(),NumerosEnteros.end(), [](int num){
        return num%2==0;
    }),NumerosEnteros.end());
    for(int numero: NumerosEnteros){
        cout<<numero<<", ";
    }
    return 0;
}
