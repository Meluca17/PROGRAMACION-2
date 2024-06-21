/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Josue
 * 
 * Created on 21 de junio de 2024, 12:00 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nodo.h"
#include "Revista.h"
#include "Novela.h"
#include "Enciclopedia.h"
Nodo::Nodo() {
    plibro=nullptr;
}

Nodo::Nodo(const Nodo& orig) {
    plibro=nullptr;
    this->plibro=orig.plibro;
}

Nodo::~Nodo() {
    
}

void Nodo::leeDato(ifstream &arch,char tipo){
    if(tipo=='E'){
        plibro=new class Enciclopedia;
    }
    else{
        if(tipo=='N'){
            plibro=new class Novela;
        }
        else{
            if(tipo=='R'){
                plibro=new class Revista;
            }
        }
    }
    plibro->lee(arch);
}

void Nodo::setNull(){
    delete plibro;
    plibro=nullptr; 
}

double Nodo::getPeso(){
    return plibro->GetPeso();
}

void Nodo::imprimeLibro(ofstream &arch){
    plibro->imprime(arch);
}

void Nodo::actualiza(){
    plibro->actualiza();
}
