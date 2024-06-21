
/* 
 * File:   NVehiculo.cpp
 * Author: mell1
 * 
 * Created on 20 de junio de 2024, 17:45
 */
#include "Utils.h"
#include "NVehiculo.h"
#include "Camion.h"
#include "Furgon.h"
#include "NPedido.h"
using namespace std;

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

NVehiculo::NVehiculo(const NVehiculo& orig) {
    unidad = nullptr;
    *this = orig;
}

NVehiculo::~NVehiculo() {
}

void NVehiculo::asignamemoria(char tipo){
    if(tipo=='F') unidad = new class Furgon;
    if(tipo=='C') unidad = new class Camion;
}

void NVehiculo::leeDatos(ifstream &arch){
    unidad->lee(arch);
}

bool NVehiculo::operator <(const class NVehiculo &v){
    return unidad->GetCliente() < v.unidad->GetCliente();
}

ostream &operator<<(ostream &out, const class NVehiculo &nveh){
    //nveh.imprimeDatos();
    
    return out;
}

void NVehiculo::imprimeDatos(ofstream &arch){
    unidad->imprime(arch);
}

int NVehiculo::GetCliente(){
    return unidad->GetCliente();
}

void NVehiculo::insertaPedidoVector(class NPedido &ped){
    unidad->insertaPed(ped);
}