/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ContenedorLibro.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 01:55 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ContenedorLibro.h"

ContenedorLibro::ContenedorLibro() {
    plib=nullptr;
}

ContenedorLibro::~ContenedorLibro() {
    if(plib!=nullptr) delete plib;
}

