/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 6 de mayo de 2024, 10:22 AM
 */

#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01PunterosGenericos.h"
#include "ColaConEnteros.h"
#include "ColaConProductos.h"
#include "ColaGenerica.h"

/*
 * 
 */
int main(int argc, char** argv) {  
    char **codigoDelProducto;
    int **fechaClienteCantidad;
    void *productos;
    void *cola;
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    pruebaCargaDePedidos(fechaClienteCantidad,codigoDelProducto,"PruebaPedidos.txt");
    cargaProductos(productos,"Productos.csv");
    pruebaDeCargaDeProductos(productos);
     
    cargaEnteros(cola,leenumero,"numeros.txt");
    mostrarEnteros(cola,imprimenumero,"reporte.txt");
    
    procesarPedidos(fechaClienteCantidad,codigoDelProducto,productos);
//    reporteDePedidos(productos,"reportefinal.txt");
    return 0;
}

