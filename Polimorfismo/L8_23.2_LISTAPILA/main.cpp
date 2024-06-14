
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 10:12
 */

#include "Utils.h"
#include "Flota.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Flota transporte;
    
    transporte.cargaflota();
    transporte.cargapedidos();
    transporte.muestracarga();
    
    return 0;
}

 