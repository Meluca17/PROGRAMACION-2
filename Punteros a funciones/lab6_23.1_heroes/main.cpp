/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 1 de mayo de 2024, 20:29
 */

#include "Utils.h"
#include "arreglos_genericos.h"
#include "listas_genericas.h"
using namespace std;

int main(int argc, char** argv) {
    void *arreglo_heroes, *lista_heroes;
    int cantidad_total_heroes;
    
    llenar_arreglo_heroes(arreglo_heroes,cantidad_total_heroes,"heroes_changelog_1223.csv");
    qsort(arreglo_heroes,cantidad_total_heroes,sizeof(void *),cmp_multicriterio_void);
    
    crear_lista_heroes(arreglo_heroes,lista_heroes,leer_heroe);
    imprimir_lista_heroes("reporteSinEliminar.txt",lista_heroes,imprimir_registro_heroes);
    
    return 0;
}

