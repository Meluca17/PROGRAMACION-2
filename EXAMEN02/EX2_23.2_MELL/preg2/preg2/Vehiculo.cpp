/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Josue
 * 
 * Created on July 2, 2024, 7:55 PM
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    dni=0;
    carga_actual=0;
    carga_maxima=0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
    *this=orig;
}


void Vehiculo::SetCarga_actual(double carga_actual) {
    this->carga_actual = carga_actual;
}

double Vehiculo::GetCarga_actual() const {
    return carga_actual;
}

void Vehiculo::SetCarga_maxima(double carga_maxima) {
    this->carga_maxima = carga_maxima;
}

double Vehiculo::GetCarga_maxima() const {
    return carga_maxima;
}

void Vehiculo::SetPlaca(string placa) {
    this->placa = placa;
}

string Vehiculo::GetPlaca() const {
    return placa;
}

void Vehiculo::SetDni(int dni) {
    this->dni = dni;
}

int Vehiculo::GetDni() const {
    return dni;
}

void Vehiculo::operator = (const class Vehiculo &veh){
    dni=veh.dni;
    placa=veh.placa;
    carga_actual=veh.carga_actual;
    carga_maxima=veh.carga_maxima;
}

void Vehiculo::lee (ifstream &arch){
    arch>>dni;
    arch.get();
    getline(arch,placa,',');
    arch>>carga_maxima;
    arch.get();
}

void Vehiculo::imprime(ofstream &arch){
    arch<<"Codigo del cliente: "<<dni<<endl;
    arch<<"Placa:            : "<<placa<<endl;
    arch<<"Carga Maxima      : "<<carga_maxima<<endl;
    arch<<"Carga Actual      : "<<carga_actual<<endl;
}

void Vehiculo::insertar (class Pedido &ped){
    
}
