/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "ColaGenerica.h"
enum cola{CAB,COLA,CANT};
enum nodo{DATO,SIG};

void generacola(void *&cola){
    void **nuevaCola=new void*[3];
    int *cant=new int;
    (*cant)=0;
    nuevaCola[CAB]=nullptr;
    nuevaCola[COLA]=nullptr;
    nuevaCola[CANT]=cant;
    cola=nuevaCola;
}

void encola(void *&cola,void *dato){
    void **auxCola=(void **)cola, **nodo=new void *[2];
    int *cant=(int *)auxCola[CANT];
    nodo[DATO]=dato;
    nodo[SIG]=nullptr;
    if(colavacia(cola)){//primer elemento
        auxCola[CAB]=nodo;
        auxCola[COLA]=nodo;
//        int *cant=(int *)auxCola[CANT];
        (*cant)++;
    }
    else{
        void **aux=(void**)auxCola[COLA];
        aux[SIG]=nodo;
        auxCola[COLA]=nodo;
        (*cant)++;
    }
    
}

//DESENCOLA UN ELEMENTO

void *desencola(void *&cola){
    void **auxCola=(void **)cola;
    if(colavacia(cola)){
        auxCola[CAB]=nullptr;
        return nullptr;
    }
    else{
        void *dato,**aux=(void **)auxCola[CAB];
        dato=aux[DATO];
        auxCola[CAB]=aux[SIG];
        delete aux;
        return dato;
    }
        
}
bool colavacia (void *cola){
    void **auxCola=(void **)cola;
    if(auxCola[CAB]==nullptr){
        return true;
    }
    else{
        return false;
    }
}