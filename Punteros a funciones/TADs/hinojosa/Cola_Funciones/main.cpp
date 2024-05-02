/* 
 * Proyecto: Cola_Funciones
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 23 de septiembre de 2023, 14:22
 */

#include <iostream>
#include <iomanip> 
using namespace std;
#include "cola.h"

int main(int argc, char** argv) {
    Cola C1,Ccopia;
    Elemento e;
    construir(C1);
    cout <<"cola vacia?: "<<esColaVacia(C1)<<endl;
    
    encolar(C1,20);
    encolar(C1,40);
    encolar(C1,25);
    encolar(C1,53);
    mostrar(C1);
    
    Ccopia  = copiar(C1);
    cout <<endl<<"Cola copia: "<<endl;
    mostrar(Ccopia);
    
    cout <<"*************************"<<endl;
    while(!esColaVacia(C1)){
        e = desencolar(C1);
        cout <<"elemento desencolado: "<<e<<endl;
        mostrar(C1);
    }
    cout <<"*************************"<<endl;
    
//    destruir(C1);
//    destruir(Ccopia);
    
    return 0;
}

