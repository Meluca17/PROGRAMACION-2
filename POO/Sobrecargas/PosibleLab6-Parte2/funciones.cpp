/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
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
#include "funciones.h"

void cargarLibros(ifstream &archLibros,Libro *arrLibros){
    int i=0;
    //cargamos el arreglo de libros
    while(archLibros>>arrLibros[i]){
        i++;
    }
}

void cargarClientes(ifstream &archClientes,Cliente *arrClientes){
    int i=0;
    //cargamos el arreglo de libros
    while(archClientes>>arrClientes[i]){
        i++;
    }
}

void cargarPedidos(ifstream &arch,Libro *arrLibros,Cliente *arrClientes){
    int numPed,dni;
    while(true){
        arch>>numPed;
        if(arch.eof()) break;
        arch.get();
        arch>>dni;
        arch.get();
        cargarLibrosSolicitados(arch,numPed,dni,arrLibros,arrClientes);
    }
}

void cargarLibrosSolicitados(ifstream &arch,int numPed,int dni,Libro *arrLibros,Cliente *arrClientes){
    char codigo[8];
    int pos;
    LibroSolicitado libSol;
    libSol.SetNumeroDelPedido(numPed);
    while(true){
        if(arch.get() =='\n') break;
        arch>>codigo;
        libSol.SetCodigoDelLibro(codigo);
        if(libSol>>arrLibros){
            pos=buscarPosicionCliente(dni,arrClientes);
            if(pos!=-1){
                arrClientes[pos]<<libSol;
            }
        }
    }
}

int buscarPosicionCliente(int dni,Cliente *arrClientes){
    int i=0,dniCliente;
    while(true){
        dniCliente=arrClientes[i].GetDni();
        if(dniCliente==0) return -1;
        if(dni==dniCliente) return i;
        i++;
    }
}

void imprimirLibros(ofstream &archLibrosOf,Libro *arrLibros){
    archLibrosOf<<fixed;
    archLibrosOf.precision(2);
    int i=0;
    char codigo[8];
    archLibrosOf<<left<<setw(10)<<"CODIGO"<<setw(60)<<"TITULO"<<setw(60)<<"AUTOR";
    archLibrosOf<<right<<setw(5)<<"STOCK"<<setw(10)<<"PRECIO"<<endl;
    for(int i=0;i<145;i++) archLibrosOf<<'-';
    archLibrosOf<<endl;
    while(true){
        arrLibros[i].GetCodigo(codigo);
        if(strcmp(codigo,"FIN")==0) break;
        archLibrosOf<<arrLibros[i];
        i++;
    }
}

void imprimirClientes(ofstream &archClientesOf,Cliente *arrClientes){
    archClientesOf<<fixed;
    archClientesOf.precision(2);
    int i=0,dni;
    while(true){
        dni=arrClientes[i].GetDni();
        if(dni==0) break;
        archClientesOf<<left<<setw(10)<<"DNI"<<setw(15)<<"NOMBRE"<<endl;
        archClientesOf<<arrClientes[i];
        for(int i=0;i<50;i++) archClientesOf<<'-';
        archClientesOf<<endl;
        i++;
    }
}