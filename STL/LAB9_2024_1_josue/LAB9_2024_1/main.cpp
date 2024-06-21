/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Josue
 *
 * Created on 20 de junio de 2024, 11:41 PM
 */

#include "Biblioteca.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca bli;
    bli.carga();
    bli.llena();
    bli.actualiza();
    bli.muestra();
    return 0;
}

