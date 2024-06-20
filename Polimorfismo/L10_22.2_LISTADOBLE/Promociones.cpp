
/* 
 * File:   Promociones.cpp
 * Author: mell1
 * 
 * Created on 11 de junio de 2024, 0:45
 */
#include "Utils.h"
#include "Promociones.h"
using namespace std;

Promociones::Promociones() {
}

void Promociones::leepedidos(){
    lpedidos.leeDatos("pedidos5.csv");
    
 }

void Promociones::imprimepedidos(){
    lpedidos.imprimeDatos("Reporte.txt");
    
 }

void Promociones::actualizapedidos(){
    lpedidos.actualizaDatos("promocion.csv");
}