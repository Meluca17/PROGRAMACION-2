
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 23 de mayo de 2024, 16:22
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"
#include "AlmacenBib.h"

int main(int argc, char** argv) {
    ifstream archLib("Libros.csv",ios::in);
    ifstream archCLi("Clientes.csv",ios::in);
    ifstream archPed("Pedidos.txt",ios::in);
    
    class Libro lib1;
    class LibroSolicitado libSOl1;
    class AlmacenBib almacen;
    
    almacen.cargar_libros();
    almacen.cargar_clientes();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    
    
    
    
    return 0;
}

//LIBROS 
// cod tit aut stock    prec