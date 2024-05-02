/* 
 * Proyecto: Pilas_Codigo
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 22 de septiembre de 2023, 17:01
 */

#include <iostream>
#include <iomanip> 

using namespace std;

#include "pilas.h"

int main(int argc, char** argv) {
    Pila P2,pilaCopia,P1; 
    Elemento x; 
    
    construir(P2);
    cout <<"Es pila vacia: "<<esPilaVacia(P2)<<endl;
    
    apilar(P2,20); 
    cout <<"Es pila vacia: "<<esPilaVacia(P2)<<endl;
    mostrar(P2);
    
    desapilar(P2);
    cout <<"Es pila vacia: "<<esPilaVacia(P2)<<endl;
    
    apilar(P2,30); 
    apilar(P2,50); 
    apilar(P2,40); 
    apilar(P2,80); 
    mostrar(P2);
    
    //PARA DESAPILAR UNA PILA
    while(!esPilaVacia(P2)){
        x = desapilar(P2);
        cout <<"dato desapilado: "<< x<<endl; 
        mostrar(P2);
    }
    destruir(P2);
    
    cout <<"******************"<<endl;
    construir( P1);
    apilar(P1,48);
    apilar(P1,21);
    apilar(P1,37);
    apilar(P1,40);
    pilaCopia = copiar(P1); 
    cout <<"pila original"<<endl;
    mostrar(P1);
    cout <<"pila copia "<<endl;
    mostrar(pilaCopia);
    
    
    
    return 0;
}

