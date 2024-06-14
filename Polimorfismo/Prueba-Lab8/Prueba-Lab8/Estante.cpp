/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 01:55 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estante.h"

Estante::Estante() {
    cantLib=0;
    codigo=nullptr;
    volumenSop=0;
    volumenAct=0;
}


Estante::~Estante() {
    if(codigo!=nullptr)delete codigo;
}

void Estante::SetCantLib(int cantLib) {
    this->cantLib = cantLib;
}

int Estante::GetCantLib() const {
    return cantLib;
}

void Estante::SetVolumenAct(double volumenAct) {
    this->volumenAct = volumenAct;
}

double Estante::GetVolumenAct() const {
    return volumenAct;
}

void Estante::SetVolumenSop(double volumenSop) {
    this->volumenSop = volumenSop;
}

double Estante::GetVolumenSop() const {
    return volumenSop;
}

void Estante::SetCodigo(const char* cod ) {
    if(codigo!=nullptr)delete codigo;
    codigo=new char[strlen(cod)+1];
    strcpy(codigo,cod);
}

void Estante::GetCodigo(char* cod ) const {
    if(codigo==nullptr)cod[0]=0;
    else strcpy(cod,codigo);
}

void Estante::lee(ifstream &arch){
    char cod[10];
    arch.getline(cod,10,',');
    SetCodigo(cod);
    arch>>volumenSop;
    arch.get();    
}

void Estante::imprime(ofstream& arch) {
    arch<<"Codigo Estante: "<<codigo<<endl;
    arch<<"Volumen Soportado: "<<volumenSop<<endl;
    arch<<"Volumen Llenado: "<<volumenAct<<endl;
    arch<<"Cantidad de Libros: "<<cantLib;
}

void Estante::imprimeLib(ofstream& arch) {
    arch<<fixed;
    arch.precision(2);
    arch<<left<<setw(10)<<"CODIGO"<<setw(40)<<
            "NOMBRE"<<setw(10)<<"ANCHO"<<setw(10)
            <<"ALTO"<<setw(15)<<"VOLUMEN"<<setw(10)<<"PESO"<<"TIPO"<<endl;
    for(int i=0; i<cantLib; i++){
//        arrLib[i].imprime(arch);
    }     
}