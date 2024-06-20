/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: alulab14
 * 
 * Created on 17 de noviembre de 2023, 08:01 AM
 */

#include "Vehiculo.h"
#include "NPedido.h"

Vehiculo::Vehiculo() {
    placa = nullptr;
    maxcarga = 0;
    actcarga = 0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
    placa = nullptr;
    maxcarga = 0;
    actcarga = 0;
    *this = orig;
}

Vehiculo::~Vehiculo() {
    if (placa != nullptr) delete placa;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char* pla) {
    if (placa != nullptr) delete placa;
    placa = new char [strlen(pla)+1];
    strcpy(placa, pla);
}

void Vehiculo::GetPlaca(char* pla) const {
    if (placa == nullptr) pla[0] = 0;
    else strcpy(pla, placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::operator=(const class Vehiculo& veh) {
    char pla[20];
    SetActcarga(veh.GetActcarga());
    SetCliente(veh.GetCliente());
    SetMaxcarga(veh.GetMaxcarga());
    veh.GetPlaca(pla);
    SetPlaca(pla);
}

void Vehiculo::lee(ifstream& arch) {
    char pla[20];
    arch >> cliente;
    arch.get();
    arch.getline(pla,20,',');
    SetPlaca(pla);
    arch>>maxcarga;
    arch.get();
}

void Vehiculo::imprime(ofstream& arch) {
    arch << left << setw(17)<<"Codigo Cliente:"<<cliente<<endl;
    arch << left << setw(17)<<"Placa:"<<placa<<endl;
    arch << left << setw(17)<<"Carga Maxima:"<<maxcarga<<endl;
    arch << left << setw(17)<<"Carga Actual:"<<actcarga<<endl;
}

void Vehiculo::cargadeposito(ifstream& arch, class NPedido &ped) {
    ped.leePedido(arch);
}


