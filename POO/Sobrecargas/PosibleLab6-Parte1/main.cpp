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
#include "LibroSolicitado.h"
#include "Libro.h"
#include "Cliente.h"
#include "AperturaDeArchivos.h"

int main(int argc, char** argv) {
    ifstream archLibros,archClientes;
    ofstream archLibrosOf,archClientesOf;
    AperturaDeUnArchivoDeTextosParaLeer(archLibros,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archLibrosOf,"reporteLibros.txt");
    archLibrosOf<<fixed;
    archLibrosOf.precision(2);
    AperturaDeUnArchivoDeTextosParaEscribir(archClientesOf,"reporteClientes.txt");
    archClientesOf<<fixed;
    archClientesOf.precision(2);
    Libro arrLibros[5];
    Cliente arrClientes[5];
    LibroSolicitado libroSol(10,"ZOY6470",14.5,true);
    /* PARA LOS LIBROS */
    int i=0;
    archLibrosOf<<"Cargamos el arreglo de Libros sin actualizar:"<<endl;
    while(archLibros>>arrLibros[i]){
        archLibrosOf<<arrLibros[i];
        i++;
    }
    // asignamos un arreglo de pedido
    archLibrosOf<<endl;
    archLibrosOf<<"Cargamos el arreglo de Libros actualizado:"<<endl;
    if(libroSol>>arrLibros){
        for(int j=0;j<4;j++){
            archLibrosOf<<arrLibros[j];
        }
    }
    
    archClientesOf<<"Cargamos el arreglo de Clientes sin actualizar:"<<endl;
    i=0;
    while(archClientes>>arrClientes[i]){
        archClientesOf<<arrClientes[i];
        i++;
    }
    archClientesOf<<endl;
    archClientesOf<<"Cargamos el Cliente actualizado:"<<endl;
    //vamos asignar un mismo libroSolicitado a los 3
    if(arrClientes[0]<<libroSol){
        ++arrClientes[0];
        archClientesOf<<arrClientes[0];
    }
    return 0;
}

