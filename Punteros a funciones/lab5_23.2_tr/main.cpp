/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 30 de abril de 2024, 14:05
 */

#include "Utils.h"
#include "ListaConEnteros.h"
#include "PilaConRegistros.h"
#include "FlotaGenerica.h"
using namespace std;

/*
 *  FLOTA DE CAMIONES-> tamano limitado por NUMCAM
 * FLOTA: arr de punteros genericos 
 * no se puede colocar un pedido que origine que el peso de la pila exceda el peso maximo (para ese caso COLOCAR el peddo en el otro camion) 
 */
int main(int argc, char** argv) {
    int numcamiones; 
    double pesomaximo; 
    void *flota; 
    
    ////////////////////////////////// ENTEROS ////////////////////////////////////////////////////////////////
    numcamiones=5, pesomaximo=10; 
    cargacamiones(flota,numcamiones,pesomaximo,leenumero,calculanumero,"numeros.txt"); 
    //qsort ordena un arreglo
    qsort(flota,numcamiones,sizeof( void*),cmpnumero);    
    muestracamiones(flota,numcamiones,imprimenumero,"reporte.txt");
    
    ////////////////////////////////// REGISTROS ////////////////////////////////////////////////////////////////
    numcamiones = 100; pesomaximo=400;
    cargacamiones(flota,numcamiones,pesomaximo,leeregistro,calcularregistro,"pedidos3.csv");
    qsort(flota,numcamiones,sizeof( void*),cmpregistro);  
    muestracamiones(flota,numcamiones,imprimeregistro,"reporteregistro.txt");
    
    return 0;
}

