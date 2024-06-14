/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 02:07 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "Estante.h"
#include "EstanteHorizontal.h"
#include "EstanteVertical.h"

Lista::Lista() {
    lini=nullptr;
    lfin=nullptr;
}

void Lista::leeEstantes(const char*nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error:no se pudo abrir " <<nombArch<<endl;
        exit(1);
    }
    class Estante *dato;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        asignaMemoria(tipo,dato);
        dato->lee(arch);
        insertaNodo(dato);
    }
}

void Lista::insertaNodo(class Estante *dato){
    class Nodo *nuevoNodo=new class Nodo;
    nuevoNodo->est=dato;
    if(lini==nullptr){
        lini=nuevoNodo;
        lfin=nuevoNodo;
    }
    else{
        lfin->sig=nuevoNodo;
        lfin=nuevoNodo;
    }
}

void Lista::asignaMemoria(char tipo,class Estante *&nuevoNodo){
    if(tipo=='H'){
        nuevoNodo=new class EstanteHorizontal;
    }
    else{
        nuevoNodo=new class EstanteVertical;
    }
}

void Lista::imprime(const char* nombArc) {
    ofstream arch(nombArc,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR AL ABRIR "<<nombArc<<endl;
        exit(1);
    }
    class Nodo *p=lini;
    while(p){
        p->est->imprime(arch);
        p=p->sig;
    }
}

void Lista::posicionarLib(const char *nomb){
    
}