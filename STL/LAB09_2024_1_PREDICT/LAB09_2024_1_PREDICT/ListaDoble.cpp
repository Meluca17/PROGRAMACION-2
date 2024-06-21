/* 
 * File:   ListaDoble.cpp
 * Author: ramir
 * 
 * Created on 21 de junio de 2024, 12:25 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaDoble.h"
#include "EstanteHorizontal.h"
#include "EstanteVertical.h"

ListaDoble::ListaDoble() {
}

ListaDoble::ListaDoble(const ListaDoble& orig) {
}

ListaDoble::~ListaDoble() {
}

void ListaDoble::creaLista(ifstream &archEst){
    char tipo;
    NodoEstante *nuevo;
    while(1){
        archEst>>tipo;
        if(archEst.eof()) break;
        archEst.get();
        nuevo = new NodoEstante;
        switch(tipo){
            case 'H':
                nuevo->pestante = new EstanteHorizontal;
                break;
            case 'V':
                nuevo->pestante = new EstanteVertical;
                break;
        }
        nuevo->pestante->SetClase(tipo);
        nuevo->pestante->lee(archEst);
        insertar(nuevo);
    }
}

void ListaDoble::insertar(class NodoEstante *nuevo){
    NodoEstante *p = lfin,*ant = nullptr;
    if(lini==nullptr){
        lini = nuevo;
        lfin = nuevo;
    }else{
        nuevo->ant = p;
        p->sig = nuevo;
        lfin = nuevo;
    }
}

void ListaDoble::llenaLibros(ifstream &archLib){
    char tipo;
    NodoLibro nuevo;
    while(1){
        nuevo.leerLibros(archLib);
        if(archLib.eof()) break;
        insertarLibro(nuevo);
        nuevo.SetNull();
    }
}

void ListaDoble::insertarLibro(class NodoLibro nuevo){
    NodoEstante *p = lini;
    while(p){
        if(p->pestante->GetMaxcapacidad()-p->pestante->GetActcapacidad() >=
                nuevo.GetPeso()){
            p->pestante->agregarLibro(nuevo);
            break;
        }
        p = p->sig;
    }
}

void ListaDoble::actualizaVigencia(){
    NodoEstante *p = lini;
    while(p){
        p->pestante->actualizaLibros();
        p = p->sig;
    }
}

void ListaDoble::imprimeEstantes(ofstream &archRep){
    NodoEstante *p = lini;
    while(p){
        p->pestante->muestraEstantes(archRep);
        p = p->sig;
    }
}