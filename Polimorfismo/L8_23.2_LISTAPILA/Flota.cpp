
/* 
 * File:   Flota.cpp
 * Author: mell1
 * 
 * Created on 12 de junio de 2024, 10:21
 */
#include "Utils.h"
#include "Flota.h"
using namespace std;

Flota::Flota() {
}


Flota::~Flota() {
}

void Flota::cargaflota(){
    lista.leeDatos("Vehiculos.csv");
}

void Flota::muestracarga(){
    lista.mostrarDatos("Reporte.txt");
}

void Flota::cargapedidos(){
    lista.leePedidos("Pedidos3.csv");
}