
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 11 de junio de 2024, 0:23
 */

#include "Utils.h"
#include "Promociones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Promociones pro;
    
    pro.leepedidos(); 
    pro.actualizapedidos();
    pro.imprimepedidos(); 
    
    return 0;
}

