
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 7 de julio de 2024, 11:09 p. m.
 */

#include "Utils.h"
using namespace std;
#include "Procesa.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Procesa pro;
    
    pro.Carga();
    pro.Atiende();
    pro.Imprime();
    
    return 0;
}

