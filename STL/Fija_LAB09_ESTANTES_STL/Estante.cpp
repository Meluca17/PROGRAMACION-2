
/* 
 * File:   Estante.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 21:57
 */
#include "Utils.h"
#include "Estante.h"
using namespace std;

Estante::Estante() {
    
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
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

void Estante::lee(ifstream &arch){
    char c;
    arch>>clase;
    if(arch.eof()) return;
    arch>>c>>id>>c>>capacidad;
}

double Estante::GetEspacioSobrante(){
    if(vlibro.size()==0){
        return capacidad;
    }else{
        //recorremos y sumamos el peso de cada libro
        int cant = vlibro.size();
        double capUsada=0;
        for(int i=0; i<cant;i++){
            capUsada+=vlibro[i].GetPesoLibro();
        }
        return capacidad-capUsada;
    }
}

void Estante::agregaLibro(class NLibro &lib){
    vlibro.push_back(lib);
}

void Estante::imprimeEstante(ofstream&arch){
    arch.precision(2);
    arch<<fixed;
    arch<<setw(10)<<" "<<left<<setw(15)<<"Id: "<<id<<endl;
    arch<<setw(10)<<" "<<left<<setw(15)<<"Tipo: ";
    if(clase=='H') arch<<"Horizontal"<<endl;
    else arch<<"Vertical"<<endl;
    arch<<setw(10)<<" "<<left<<setw(15)<<"Capacidad: "<<capacidad<<endl;
    arch<<setw(10)<<" "<<left<<setw(15)<<"Libros contenidos: "<<endl;
    // impresion de libros
    for(int i=0; i<100;i++) arch<<"-";
    arch<<endl;
    //imprimelibros
    imprimeLibros(arch);
    //imprime separacion de estante
    for(int i=0; i<100;i++) arch<<"=";
    arch<<endl;
}

void Estante::imprimeLibros(ofstream&arch){
    int cant = vlibro.size();
    for(int i=0; i<cant;i++){
        vlibro[i].imprimeLibro(arch);
    }
}

void Estante::actualizaLibros(int anho){
    int cant = vlibro.size();
    for(int i=0; i<cant;i++){
        //actualizamos el anho con metodo polimorfico 
        vlibro[i].actualizaLibro(anho);
    }
}