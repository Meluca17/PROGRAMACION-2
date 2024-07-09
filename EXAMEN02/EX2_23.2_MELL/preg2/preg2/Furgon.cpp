/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: Josue
 * 
 * Created on July 2, 2024, 8:04 PM
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
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

void Furgon::lee (ifstream &arch){
    Vehiculo::lee(arch);
    arch>>filas;
    arch.get();
    arch>>puertas;    
}

void Furgon::imprime(ofstream &arch){
    Vehiculo::imprime(arch);
    arch<<"#Filas: "<<filas<<endl;
    arch<<"#Puertas: "<<puertas<<endl;
    if(depositos.size()>0){
        for(Pedido ped:depositos){
            ped.imprime(arch);
        }
    }
    else{
        arch<<"No hay pedidos para el cliente "<<endl;
    }
}

void Furgon::insertar (class Pedido &ped){
    double pesoPaquete=ped.GetPeso(),nuevoPeso;
    if(GetCarga_maxima()>=GetCarga_actual()+pesoPaquete){
        list <Pedido>::iterator it;
        for(it=depositos.begin();it!=depositos.end();it++){
            if(pesoPaquete>it->GetPeso())break;
        }
        nuevoPeso=GetCarga_actual()+pesoPaquete;
        SetCarga_actual(nuevoPeso);
        depositos.insert(it,ped);
    }
}