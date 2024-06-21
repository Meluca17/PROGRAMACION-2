/* 
 * File:   NodoEstante.cpp
 * Author: ramir
 * 
 * Created on 21 de junio de 2024, 12:24 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NodoEstante.h"

NodoEstante::NodoEstante() {
    pestante = nullptr;
    sig = nullptr;
    ant = nullptr;
}

NodoEstante::NodoEstante(const NodoEstante& orig) {
}

NodoEstante::~NodoEstante() {
}

