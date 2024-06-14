/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 01:43 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"

Libro::Libro() {
    codigo=nullptr;
    nombre=nullptr;
}


Libro::~Libro() {
    if(codigo!=nullptr)delete codigo;
    if(nombre!=nullptr)delete nombre;
}

void Libro::SetVolumen(double volumen) {
    this->volumen = volumen;
}

double Libro::GetVolumen() const {
    return volumen;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char* cad) {
    if(nombre!=nullptr)delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Libro::GetNombre(char* cad) const {
    if(nombre==nullptr)cad[0]=0;
    else strcpy(cad,nombre);
}

void Libro::SetCodigo(const char* cad) {
    if(codigo!=nullptr)delete codigo;
    codigo=new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void Libro::GetCodigo(char* cad) const {
    if(codigo==nullptr)cad[0]=0;
    else strcpy(cad,codigo);
}

