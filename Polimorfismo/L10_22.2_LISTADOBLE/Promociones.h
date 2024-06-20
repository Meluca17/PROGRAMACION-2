

/* 
 * File:   Promociones.h
 * Author: BlueCod (mell1)
 *
 * Created on 11 de junio de 2024, 0:45
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H
#include "Lista.h"
class Promociones {
private:
    class Lista lpedidos; // se guardan todos los pedidos de los clientes 
public:
    Promociones();
    void leepedidos();
    void imprimepedidos(); 
    void actualizapedidos(); 
};

#endif /* PROMOCIONES_H */

