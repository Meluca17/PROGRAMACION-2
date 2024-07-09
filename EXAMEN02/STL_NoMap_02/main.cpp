
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 8 de julio de 2024, 4:51 p. m.
 */

#include "Utils.h"
using namespace std;
#include "Biblioteca.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca biblioteca;
    
    biblioteca.leeLibros("Libros.csv");
    biblioteca.imprimeLibros("ReporteLibrosInicial.txt");
    biblioteca.leeUsuarios("Usuarios.csv");
    biblioteca.imprimeUsuarios("ReporteUsuariosInicial.txt");
    biblioteca.leerPrestamos("RegistroDePrestamos.csv");
    biblioteca.imprimeUsuarios("ReporteUsuariosFinal.txt");
    biblioteca.imprimeLibros("ReporteLibrosFinal.txt");
    biblioteca.imprimirSuspendidos("ReporteSuspendidos.txt",19,10,2021);
    
    return 0;
}

