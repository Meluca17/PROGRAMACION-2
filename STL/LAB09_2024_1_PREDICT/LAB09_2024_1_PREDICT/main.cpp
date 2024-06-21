/* 
 * File:   main.cpp
 * Author: R4
 *
 * Created on 21 de junio de 2024, 12:11 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
int main(int argc, char** argv) {
    
    Biblioteca bli;
    
    bli.carga();
    bli.llena();
    bli.baja();
    bli.muestra();
    
    return 0;
}

