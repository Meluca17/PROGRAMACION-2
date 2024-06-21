/* 
 * File:   NodoLibro.cpp
 * Author: ramir
 * 
 * Created on 21 de junio de 2024, 12:18 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NodoLibro.h"
#include "Novela.h"
#include "Enciclopedia.h"
#include "Revista.h"

NodoLibro::NodoLibro() {
    ptr_libro = nullptr;
}

NodoLibro::NodoLibro(const NodoLibro& orig) {
    this->ptr_libro = orig.ptr_libro;
}

NodoLibro::~NodoLibro() {
}
/*
N,Diamantes y pedernales,120,0.4,Jose Maria Arguedas
E,ENCICLOPEDIA SALVAT,2000,12,78323,2015
R,Boletin de Arqueologia PUCP,40,0.25,10292004,2023,3
*/
void NodoLibro::leerLibros(ifstream &archLib){
    char tipo;
    
    archLib>>tipo;
    if(archLib.eof()) return;
    archLib.get();
    switch(tipo){
        case 'N':
            ptr_libro = new Novela;
            break;
        case 'E':
            ptr_libro = new Enciclopedia;
            break;
        case 'R':
            ptr_libro = new Revista;
            break;
    }
    ptr_libro->lee(archLib);
}

void NodoLibro::SetNull(){
    ptr_libro = nullptr;
}

double NodoLibro::GetPeso() const{
    return ptr_libro->GetPeso();
}

void NodoLibro::actualizaVigencia(){
    ptr_libro->actualiza();
}

void NodoLibro::imprimeLibro(ofstream &archRep){
    ptr_libro->imprime(archRep);
    archRep<<endl;
}