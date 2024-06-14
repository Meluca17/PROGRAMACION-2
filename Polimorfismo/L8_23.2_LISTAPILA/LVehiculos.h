

/* 
 * File:   LVehiculos.h
 * Author: BlueCod (mell1)
 *
 * Created on 12 de junio de 2024, 10:20
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H
#include "NodoLista.h"
#include "Vehiculo.h"

class LVehiculos {
private:
    class NodoLista *lini;
    class NodoLista *lfin;
    
    //ya que maneja el elemento del nodo -> es privado 
    void asignaMemoria(class Vehiculo *&vel, char tipo);
public:
    LVehiculos();
    virtual ~LVehiculos();
    void leeDatos(const char *filename);
    void insertarOrden(class Vehiculo *&vehiculo);
    void insertarFinal(class Vehiculo *&vehiculo);
    void mostrarDatos(const char *filename);
    void leePedidos(const char *filename);
    void asignaPedido(int dni,class NPedido *ped);
    void asignaPedidoVariante(int dni,class NPedido *ped);
};

#endif /* LVEHICULOS_H */

