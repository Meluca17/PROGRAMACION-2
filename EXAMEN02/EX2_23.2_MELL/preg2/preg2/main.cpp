/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on July 2, 2024, 7:03 PM
 */

#include "Flota.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Flota flota;
    flota.cargar_vehiculos();
    flota.carga_pedidos();
    flota.mostrar_vehiculos();
    return 0;
}

