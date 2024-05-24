/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: julia
 *
 * Created on 23 de mayo de 2024, 11:40
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "AperturaDeArchivos.h"
#include "LibroSolicitado.h"
#include "Libro.h"
#include "Cliente.h"
#include "funciones.h"

int main(int argc, char** argv) {
    ifstream archLibros,archClientes,archPedidos;
    ofstream archLibrosOf,archClientesOf;
    AperturaDeUnArchivoDeTextosParaLeer(archLibros,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archLibrosOf,"reporteLibros.txt");
    //AperturaDeUnArchivoDeTextosParaEscribir(archLibrosOf2,"reporteLibros2.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archClientesOf,"reporteClientes.txt");
    Libro arrLibros[300];
    Cliente arrClientes[200];
    //LibroSolicitado libroSol(10,"ZOY6470",14.5,true);
    LibroSolicitado lib;
    cargarLibros(archLibros,arrLibros);
    //imprimirLibros(archLibrosOf2,arrLibros);
    cargarClientes(archClientes,arrClientes);
    cargarPedidos(archPedidos,arrLibros,arrClientes);
    imprimirLibros(archLibrosOf,arrLibros);
    imprimirClientes(archClientesOf,arrClientes);
    
    
    return 0;
}

