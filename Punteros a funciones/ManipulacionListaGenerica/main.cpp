/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 29 de abril de 2024, 05:53 PM
 */

#include "Utils.h"
#include "BibliotecaListaGenerica.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *lista; 
    
    ifstream arch("Datos.txt",ios::in); 
    
    //                      le pasa func para leer + para ordenarlo segun el tipo de dato 
    crearLista(arch,lista, leeEntero, cmpEntero); 
//    imprimirLista(lista, imprimeEntero); 
//    eliminarLista(lista, eliminaEntero); 
    
    return 0;
}

