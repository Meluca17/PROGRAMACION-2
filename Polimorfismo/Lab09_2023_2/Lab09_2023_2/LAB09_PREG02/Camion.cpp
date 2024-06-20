/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.cpp
 * Author: alulab14
 * 
 * Created on 17 de noviembre de 2023, 08:01 AM
 */

#include "Camion.h"


void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::lee(ifstream& arch) {
    Vehiculo::lee(arch);
    arch >> ejes;
    arch.get();
    arch >> llantas;
    arch.get();
}

void Camion::imprime(ofstream& arch) {
    Vehiculo::imprime(arch);
    arch << left << setw(17)<<"#Ejes:"<<ejes<<endl;
    arch << left << setw(17)<<"#Llantas:"<<llantas<<endl;
    if (mdeposito.empty()) arch << "No hay pedidos para el cliente"<<endl;
    else{
        arch << "Lista de Pedidos:"<<endl;
        for (auto ped: mdeposito){
            arch << right << setw(2)<<ped.first;
            ped.second.imprimePedido(arch);
        }
    }
}

void Camion::cargadeposito(ifstream& arch, class NPedido& ped) {
    Vehiculo::cargadeposito(arch, ped);
    double posibleCarga = ped.GetPeso() + GetActcarga();
    int cant = mdeposito.size();
    if (posibleCarga <= GetMaxcarga() && cant<5){
        mdeposito[cant+1] = ped;
        SetActcarga(posibleCarga);
    }
}



