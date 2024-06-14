/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 01:47 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"
#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    peso=0;
}

void Enciclopedia::SetPeso(double peso) {
    this->peso = peso;
}

double Enciclopedia::GetPeso() const {
    return peso;
}

