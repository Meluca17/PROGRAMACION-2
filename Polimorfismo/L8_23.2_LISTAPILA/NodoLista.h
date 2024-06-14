

/* 
 * File:   NodoLista.h
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 10:18
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Vehiculo.h"
#include "LVehiculos.h"

class NodoLista {
private:
    class Vehiculo *unidad; 
    class NodoLista *sig; 
public:
    NodoLista();
    
    friend class LVehiculos;
};

#endif /* NODOLISTA_H */

