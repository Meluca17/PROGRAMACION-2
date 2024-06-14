/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   EstanteVertical.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 02:00 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "EstanteVertical.h"


void EstanteVertical::SetInicioLetra(char inicioLetra) {
    this->inicioLetra = inicioLetra;
}

char EstanteVertical::GetInicioLetra() const {
    return inicioLetra;
}

void EstanteVertical::lee(ifstream &arch){
    Estante::lee(arch);
    
    arch>>inicioLetra;
}

void EstanteVertical::imprime(ofstream& arch) {
    Estante::imprime(arch);
    arch<<left<<"   Tipo: Vertical"<<endl;
    arch<<left<<"Letra de Inicio: "<<inicioLetra<<endl;
    imprimeLib(arch);
    arch<<endl;
}