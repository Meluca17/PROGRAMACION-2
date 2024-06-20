/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.cpp
 * Author: alulab14
 * 
 * Created on 17 de noviembre de 2023, 08:02 AM
 */

#include "Furgon.h"


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

void Furgon::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    arch >> filas;
    arch.get();
    arch >> puertas;
    arch.get();
}

void Furgon::imprime(ofstream& arch) {
    Vehiculo::imprime(arch);
    arch << left << setw(17)<<"#Filas:"<<filas<<endl;
    arch << left << setw(17)<<"#Puertas:"<<puertas<<endl;
    if (pdeposito.empty()) arch << "No hay pedidos para el cliente"<<endl;
}



