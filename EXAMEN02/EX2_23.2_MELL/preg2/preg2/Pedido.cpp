/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Josue
 * 
 * Created on July 2, 2024, 7:50 PM
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    cantidad=0;
    peso=0;
}

Pedido::Pedido(const Pedido& orig) {
    *this=orig;
}


void Pedido::SetPeso(double peso) {
    this->peso = peso;
}

double Pedido::GetPeso() const {
    return peso;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::operator = (const class Pedido &ped){
    codigo=ped.codigo;
    cantidad=ped.cantidad;
    peso=ped.peso;
}

void Pedido::leePedido(ifstream &arch){
    getline(arch,codigo,',');
    arch>>cantidad;
    arch.get();
    arch>>peso;
    arch.get();
}

void Pedido::imprime(ofstream &arch){
    arch<<setw(8)<<codigo<<setw(5)<<" "<<setw(6)<<peso<<setw(5)<<" "<<setw(2)<<cantidad<<endl;
}