
/* 
 * File:   Camion.cpp
 * Author: mell1
 * 
 * Created on 12 de junio de 2024, 10:16
 */
#include "Utils.h"
#include "Camion.h"
#include "Vehiculo.h"
using namespace std; 

Camion::Camion() {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream &arch){
    Vehiculo::lee(arch);
    
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();
}

void Camion::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<setw(10)<<" "<<left<<setw(20)<<"#Ejes: "<<ejes<<endl;
    arch<<setw(10)<<" "<<left<<setw(20)<<"#Llantas: "<<llantas<<endl;
    Vehiculo::imprimePedido(arch);
    arch<<endl;
}
