
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 13:45
 */

#include "Utils.h"
#include "Biblioteca.h"
using namespace std;

/*
 * TRYING 
 */
int main(int argc, char** argv) {
    Biblioteca bli;
    
    bli.carga();
    bli.llena();
    bli.baja();
    bli.muestra();
    
    return 0;
}

