
/* 
 * File:   Furgon.cpp
 * Author: mell1
 * 
 * Created on 12 de junio de 2024, 10:17
 */
#include "Utils.h"
#include "Furgon.h"
#include "Vehiculo.h"
using namespace std;

Furgon::Furgon() {
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(ifstream &arch){
    Vehiculo::lee(arch);

    char c;
    arch>>filas>>c>>puertas;
    arch.get();
}

void Furgon::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<setw(10)<<" "<<left<<setw(20)<<"#Filas: "<<filas<<endl;
    arch<<setw(10)<<" "<<left<<setw(20)<<"#Puertas: "<<puertas<<endl;
    Vehiculo::imprimePedido(arch);
    arch<<endl;
    
}

