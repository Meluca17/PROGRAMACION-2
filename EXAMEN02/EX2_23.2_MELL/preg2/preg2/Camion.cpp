/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Josue
 * 
 * Created on July 2, 2024, 7:57 PM
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Camion.h"

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

void Camion::lee (ifstream &arch){
    Vehiculo::lee(arch);
    arch>>ejes;
    arch.get();
    arch>>llantas;
}

void Camion::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<"#Llantas: "<<llantas<<endl;
    arch<<"#Ejes: "<<ejes<<endl;
    if(depositos.size()>0){
        for(Pedido ped:depositos){
            ped.imprime(arch);
        }
    }
    else{
        arch<<"No hay pedidos para el cliente "<<endl;
    }
    
    
}

void Camion::insertar (class Pedido &ped){
    double pesoPaquete=ped.GetPeso(),nuevoPeso;
    int cantPedidos=depositos.size();
    if(cantPedidos<=5 and GetCarga_maxima()>=GetCarga_actual()+pesoPaquete){
        depositos.push_back(ped);
        nuevoPeso=GetCarga_actual()+pesoPaquete;
        SetCarga_actual(nuevoPeso);
    }

}