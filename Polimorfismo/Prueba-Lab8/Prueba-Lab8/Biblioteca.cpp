/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Josue
 * 
 * Created on 14 de junio de 2024, 02:08 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"



void Biblioteca::cargaEstantes(){
    lestantes.leeEstantes("estantes2.csv");
}
void Biblioteca::posicionarLib() {
    lestantes.posicionarLib("libros2.csv");
}
void Biblioteca::muestraDatos() {
    lestantes.imprime("ReporteFinal.txt");
}