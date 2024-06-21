
/* 
 * File:   ListaEstante.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 22:44
 */
#include "Utils.h"
#include "ListaEstante.h"
#include "Estante.h"
#include "NodoEstante.h"
using namespace std;

ListaEstante::ListaEstante() {
    lfin = nullptr;
    lini = nullptr;
}

ListaEstante::ListaEstante(const ListaEstante& orig) {
}

ListaEstante::~ListaEstante() {
}

void ListaEstante::leeDatos(ifstream &arch){
     class Estante *dato;
     while(true){
         dato = new Estante;
         dato->lee(arch);
         if(arch.eof()) break;
         //insertar en Orden por peso 
         insertaOrden(dato);
     }
 }

void ListaEstante::insertaOrden(class Estante *&dato){
    class NodoEstante *nuevo, *ant = nullptr, *rec = lini;
    nuevo = new class NodoEstante;
    nuevo->pEstante = dato;
    
    while(rec){
        if(rec->pEstante->GetCapacidad()> dato->GetCapacidad()) break;
        ant = rec;
        rec = rec->sig;
    }
    //nuevo nodo
    nuevo->sig = rec;
    nuevo->ant = ant;
    //rec
    if(rec==nullptr){ // es el pompi
        lfin = nuevo;
    }else{
        rec->ant = nuevo;
    }
    //ant
    if(ant==nullptr){ // es la cabeciña
        lini = nuevo;
    }else{
        ant->sig = nuevo;
    }
}

void ListaEstante::muestraDatos(ofstream &arch){
    class NodoEstante  *rec = lini;
    
    while(rec){
        //impresion
        rec->pEstante->imprimeEstante(arch);
        
        rec = rec->sig;
    }
}

bool ListaEstante::meteLibroEstante(class NLibro &lib){
    class NodoEstante  *rec = lini;
    //validamos cada estante 
    while(rec){
        //validacion
        if(rec->pEstante->GetEspacioSobrante() >= lib.GetPesoLibro()){
            // se añade el libro al vector de libros del estante 
            rec->pEstante->agregaLibro(lib);
            return true;
        }
        
        rec = rec->sig;
    }
    return false;
}

// actualiza los menores iguales a anho
void ListaEstante::actualizaLibrosEstante(int anho){ 
    class NodoEstante  *rec = lini;
    while(rec){
        //actualiza cada estante
        rec->pEstante->actualizaLibros(anho);
        rec = rec->sig;
    }
}