/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NVehiculo.cpp
 * Author: alulab14
 * 
 * Created on 17 de noviembre de 2023, 08:02 AM
 */

#include "NVehiculo.h"
#include "Camion.h"
#include "Furgon.h"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

void NVehiculo::leeDatos(ifstream& arch) {
    char tipo;
    arch >> tipo;
    if (arch.eof()) return;
    arch.get();
    if (tipo == 'C') unidad = new class Camion;
    else if (tipo == 'F') unidad = new class Furgon;
    unidad->lee(arch);
}

void NVehiculo::imprimeDatos(ofstream& arch) {
    unidad->imprime(arch);
    arch << endl;
}



