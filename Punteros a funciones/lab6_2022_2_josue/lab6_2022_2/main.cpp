/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 2 de mayo de 2024, 11:08 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistro.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *arreglo, *pilaini, *pilafin;
    cargaarrelo(arreglo,cmpnumero,leenumero,"numeros.txt");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimenumero,"repnumeros.txt");
    
    cargaarrelo(arreglo,cmpregistro,leeregistro,"medicinas.csv");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimeregistro,"repmedicinas.txt");
    return 0;
}

