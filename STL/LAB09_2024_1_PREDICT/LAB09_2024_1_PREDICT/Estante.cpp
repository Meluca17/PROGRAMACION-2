/* 
 * File:   Estante.cpp
 * Author: ramir
 * 
 * Created on 21 de junio de 2024, 12:20 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estante.h"
#define MAX_LINEA 70
Estante::Estante() {
    id = 0;
    maxcapacidad = 0.0;
    actcapacidad = 0.0;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetActcapacidad(double actcapacidad) {
    this->actcapacidad = actcapacidad;
}

double Estante::GetActcapacidad() const {
    return actcapacidad;
}

void Estante::SetMaxcapacidad(double maxcapacidad) {
    this->maxcapacidad = maxcapacidad;
}

double Estante::GetMaxcapacidad() const {
    return maxcapacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}
/*
1,20
*/
void Estante::lee(ifstream &archEst){
    char c;
    
    archEst>>id>>c>>maxcapacidad;
    archEst.get();
}

void Estante::agregarLibro(class NodoLibro nlib){
    vlibros.push_back(nlib);
    actcapacidad += nlib.GetPeso();
}

void Estante::actualizaLibros(){
    for(int i=0;i<vlibros.size();i++){
        vlibros[i].actualizaVigencia();
    }
}

void Estante::muestraEstantes(ofstream &archRep){
    archRep<<"Id: "<<id<<endl;
    archRep<<"Tipo: ";
    switch(clase){
        case 'H':
            archRep<<"Horizontal"<<endl;
            break;
        case 'V':
            archRep<<"Vertical"<<endl;
            break;
    }
    archRep<<"Capacidad: "<<maxcapacidad<<endl;
    archRep<<"Libros Contenidos:"<<endl;
    imprimirLinea(archRep,'=');
    for(int i=0;i<vlibros.size();i++) 
        vlibros[i].imprimeLibro(archRep);
    imprimirLinea(archRep,'=');
}

void Estante::imprimirLinea(ofstream &archRep,char c){
    for(int i=0;i<MAX_LINEA;i++)
        archRep<<c;
    archRep<<endl;
}