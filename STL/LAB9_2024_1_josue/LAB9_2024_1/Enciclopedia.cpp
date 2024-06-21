/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Josue
 * 
 * Created on 20 de junio de 2024, 11:56 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    vigencia=1;
}


void Enciclopedia::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
    return vigencia;
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::lee(ifstream &arch){
    Libro::lee(arch);
    arch>>sku;
    arch.get();
    arch>>anho;
}

void Enciclopedia::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<"SKU: "<<sku<<setw(7)<<" "<<"Año: "<<anho<<setw(7)<<" "<<"Vigencia: "<<vigencia<<endl;
}

void Enciclopedia::actualiza(){
    if(anho<=2020)vigencia=0;
}

