

/* 
 * File:   Nodo.h
 * Author: BlueCod (mell1)
 *
 * Created on 11 de junio de 2024, 0:40
 */

#ifndef NODO_H
#define NODO_H
#include "Pedido.h"
#include "Lista.h"

class Nodo {
private:
    class Pedido *ped; //dato
    class Nodo *sig;
    class Nodo *ant;
public:
    Nodo();
    friend class Lista; 
};

#endif /* NODO_H */

