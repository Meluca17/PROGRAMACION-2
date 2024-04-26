/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * 
 * void **aux=(void **)dato;
 * char *cadena=(char*)aux, *cadenaNueva;
 * cadenaNueva=new char[strlen(cadena)+1];
 * strcpy(cadenaNueva,cadena);
 * 
 * 
 * 
 * Created on 25 de abril de 2024, 01:44 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *libros, *clientes;
    lecturaDeLibros(libros,"Libros.csv");
    imprimeLibro(libros);
    lecturaDeClientes(clientes,"Clientes.txt");
    imprimeCliente(clientes,"reporteClientes.txt");
    completarPedidos(clientes,libros,"Pedidos.txt");
    imprimeReporteFinal(clientes,"reportefinal.txt");
    return 0;
}

