/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: MELL ALESSANDRA CARBAJAL ROMAN 20214987
 *
 * Created on 26 de abril de 2024, 08:05 AM
 */

#include "Utils.h"
#include "PunterosGenericos.h"
#include "MuestraPunteroGenerico.h"
using namespace std;


int main(int argc, char** argv) {
    void *clientes, *reserva; 
    
    cargaclientes(clientes);
    //muestraclientes(clientes); 
    creareserva(reserva); 
    //muestrareservas(reserva);
    cargareserva(clientes,reserva);
    reportefinal(reserva); 
    
    return 0;
}

