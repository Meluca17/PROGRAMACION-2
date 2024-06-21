/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NodoEstante.cpp
 * Author: Josue
 * 
 * Created on 21 de junio de 2024, 12:02 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NodoEstante.h"

NodoEstante::NodoEstante() {
    estante=nullptr;
    sig=nullptr;
    ant=nullptr;
}

