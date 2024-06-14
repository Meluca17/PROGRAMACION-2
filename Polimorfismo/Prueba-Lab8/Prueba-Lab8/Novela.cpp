/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 01:51 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "Novela.h"

Novela::Novela() {
    tipo=nullptr;
}

Novela::~Novela() {
    if(tipo!=nullptr )delete tipo;
}

void Novela::SetTipo(const char* cad) {
    if(tipo!=nullptr)delete tipo;
    tipo=new char [strlen(cad)+1];
    strcpy(tipo,cad);
}

void Novela::GetTipo(char* cad) const {
    if(tipo==nullptr)cad[0]=0;
    else strcpy(cad,tipo);
}

