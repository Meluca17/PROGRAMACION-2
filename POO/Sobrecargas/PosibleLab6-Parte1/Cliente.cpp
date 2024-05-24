/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: julia
 * 
 * Created on 23 de mayo de 2024, 11:58
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Cliente.h"

Cliente::Cliente() {
    nombre=nullptr;
}


Cliente::~Cliente() {
    if(nombre!=nullptr) delete nombre;
}

void Cliente::SetPagoTotal(double pagoTotal) {
    this->pagoTotal = pagoTotal;
}

double Cliente::GetPagoTotal() const {
    return pagoTotal;
}

void Cliente::SetCantDeLibros(int cantDeLibros) {
    this->cantDeLibros = cantDeLibros;
}

int Cliente::GetCantDeLibros() const {
    return cantDeLibros;
}

void Cliente::SetNombre(const char* nom) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nom)+1];
    strcpy(nombre,nom);
}

void Cliente::GetNombre(char *nom) const {
    if(nombre==nullptr) nom[0]=0;
    else strcpy(nom,nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

bool Cliente::operator <<(const LibroSolicitado &libro){
    if(cantDeLibros<30){
        librosSolicitados[cantDeLibros]=libro;
        cantDeLibros++;
        return true;
    }else{
        return false;
    }
}

void Cliente::operator ++(){
    if(cantDeLibros>0){
        for(int i=0;i<cantDeLibros;i++){
            double precio=librosSolicitados[i].GetPrecio();
            pagoTotal+=precio;
        }
    }
}

void Cliente::imprimirPedidos(ofstream &arch){
    int numPed;
    char codigo[8];
    double precio;
    for(int i=0;i<cantDeLibros;i++){
        numPed=librosSolicitados[i].GetNumeroDelPedido();
        librosSolicitados[i].GetCodigoDelLibro(codigo);
        precio=librosSolicitados[i].GetPrecio();
        arch<<right<<setw(9)<<' '<<setw(5)<<setfill('0')<<numPed<<setfill(' ')<<setw(7)<<' ';
        arch<<left<<setw(11)<<codigo;
        arch<<right<<setw(6)<<precio<<endl;
    }
}

bool operator >>(ifstream &arch,Cliente &cliente){
    int dni;
    char nombre[60];
    arch>>dni;
    if(arch.eof()) return false;
    arch.get();
    arch.getline(nombre,60,'\n');
    cliente.SetDni(dni);
    cliente.SetNombre(nombre);
    cliente.SetCantDeLibros(0);
    cliente.SetPagoTotal(0.0);
    return true;
}

void operator <<(ofstream &arch,Cliente &cliente){
    int dni=cliente.GetDni();
    char nombre[60];
    cliente.GetNombre(nombre);
    int cant=cliente.GetCantDeLibros();
    double pago=cliente.GetPagoTotal();
    arch<<right<<setw(8)<<dni<<"  "<<left<<setw(60)<<nombre<<endl;
    if(cant>0){
        arch<<"Libros entregados:"<<endl;
        arch<<right<<setw(7)<<' '<<left<<setw(15)<<"Pedido No.";
        arch<<setw(10)<<"Codigo"<<"Precio"<<endl;
        cliente.imprimirPedidos(arch);
    }
}