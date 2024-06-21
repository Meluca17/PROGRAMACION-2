
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 20 de junio de 2024, 17:11
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Flota.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Flota unidades;
    
    unidades.cargaflota();
    unidades.cargapedidos();
    unidades.muestracarga();
    return 0;
}

