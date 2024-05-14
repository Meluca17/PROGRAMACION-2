/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 13 de mayo de 2024, 11:33 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *libros;
    char ***librosMult;
    int *stock;
    double *precio;
    leerLibros(libros,"Libros.csv");
    reporteLibros(libros,"reporteLib.txt");
    
    leePunteroMultiple(librosMult,stock,precio,libros);
    reporteDePunteros(librosMult,stock,precio,"ReportePunteros.txt");
    return 0;
}

